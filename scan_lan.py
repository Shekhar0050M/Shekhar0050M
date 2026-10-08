#!/usr/bin/env python3
"""
scan_lan.py - Discover all devices on the local Wi-Fi / Ethernet subnet.
Performs fast subnet sweeping, reads ARP neighbors, resolves hostnames via DNS/mDNS,
and identifies hardware vendors using the local OUI database.
"""

import concurrent.futures
import ipaddress
import os
import re
import socket
import subprocess
import sys

def load_oui_db():
    oui_path = "/usr/share/hwdata/oui.txt"
    db = {}
    if not os.path.exists(oui_path):
        return db
    try:
        with open(oui_path, "r", encoding="utf-8", errors="ignore") as f:
            for line in f:
                if "(base 16)" in line:
                    parts = line.strip().split("(base 16)")
                    if len(parts) == 2:
                        prefix = parts[0].strip().upper()
                        vendor = parts[1].strip()
                        db[prefix] = vendor
    except Exception:
        pass
    return db

OUI_DB = load_oui_db()

def get_oui_vendor(mac):
    clean = mac.replace(":", "").replace("-", "").upper()
    if len(clean) >= 6:
        prefix = clean[:6]
        if prefix in OUI_DB:
            return OUI_DB[prefix]
    return "Unknown Vendor"

def run_cmd(cmd, timeout=10):
    try:
        res = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, timeout=timeout)
        return res.stdout
    except Exception:
        return ""

def get_network_info():
    """Detect primary network interface, local IP, subnet, and default gateway."""
    route_out = run_cmd(["ip", "route", "show", "default"])
    gateway = None
    iface = None
    m = re.search(r"default via ([\d\.]+) dev (\S+)", route_out)
    if m:
        gateway = m.group(1)
        iface = m.group(2)

    local_ip = None
    subnet = None
    if iface:
        addr_out = run_cmd(["ip", "-o", "-f", "inet", "addr", "show", iface])
        m2 = re.search(r"inet ([\d\.]+)/(\d+)", addr_out)
        if m2:
            local_ip = m2.group(1)
            prefix_len = int(m2.group(2))
            network = ipaddress.IPv4Network(f"{local_ip}/{prefix_len}", strict=False)
            subnet = network

    # Get local MAC
    local_mac = None
    if iface:
        link_out = run_cmd(["ip", "link", "show", iface])
        m3 = re.search(r"link/ether ([0-9a-fA-F:]{17})", link_out)
        if m3:
            local_mac = m3.group(1).upper()

    return {
        "iface": iface,
        "local_ip": local_ip,
        "local_mac": local_mac,
        "subnet": subnet,
        "gateway": gateway,
    }

def ping_host(ip_str):
    try:
        res = subprocess.run(
            ["ping", "-c", "1", "-W", "1", ip_str],
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL
        )
        return ip_str, (res.returncode == 0)
    except Exception:
        return ip_str, False

def sweep_subnet(subnet):
    """Concurrently ping all hosts in the subnet to update ARP cache."""
    # Limit sweep to at most /24 to keep speed high
    hosts = list(subnet.hosts())
    if len(hosts) > 256:
        hosts = hosts[:256]

    print(f"Sweeping {len(hosts)} IP addresses on subnet {subnet} to discover active hosts...")
    with concurrent.futures.ThreadPoolExecutor(max_workers=60) as executor:
        results = list(executor.map(ping_host, [str(h) for h in hosts]))
    active_ips = {ip for ip, ok in results if ok}
    return active_ips

def get_mdns_services():
    """Query mDNS services via avahi-browse if available."""
    services = {}
    out = run_cmd(["avahi-browse", "-art", "--resolve"], timeout=5)
    current_ip = None
    current_host = None
    current_model = None

    for line in out.split("\n"):
        line = line.strip()
        if "address = [" in line:
            m = re.search(r"address = \[([\d\.]+)\]", line)
            if m:
                current_ip = m.group(1)
        if "hostname = [" in line:
            m = re.search(r"hostname = \[([^\]]+)\]", line)
            if m:
                current_host = m.group(1)
        if "txt = [" in line:
            m = re.search(r"Model_Number=([^\s\"]+)", line)
            if m:
                current_model = m.group(1)

        if current_ip:
            info = {}
            if current_host:
                info["hostname"] = current_host
            if current_model:
                info["model"] = current_model
            services[current_ip] = info
    return services

def read_arp_cache(iface):
    """Read neighbors from /proc/net/arp and ip neigh."""
    neighbors = {}
    if os.path.exists("/proc/net/arp"):
        with open("/proc/net/arp", "r") as f:
            for line in f.readlines()[1:]:
                parts = line.split()
                if len(parts) >= 6:
                    ip = parts[0]
                    mac = parts[3].upper()
                    dev = parts[5]
                    flags = parts[2]
                    if (not iface or dev == iface) and mac != "00:00:00:00:00:00" and flags != "0x0":
                        neighbors[ip] = mac

    neigh_out = run_cmd(["ip", "neigh", "show"])
    for line in neigh_out.split("\n"):
        parts = line.split()
        if len(parts) >= 5 and "lladdr" in parts:
            idx = parts.index("lladdr")
            ip = parts[0]
            mac = parts[idx + 1].upper()
            state = parts[-1]
            if state in ["REACHABLE", "STALE", "DELAY"]:
                neighbors[ip] = mac

    return neighbors

def resolve_hostname(ip):
    try:
        host, _, _ = socket.gethostbyaddr(ip)
        return host
    except Exception:
        return ""

def main():
    print("=" * 80)
    print("                      LOCAL NETWORK (LAN) DEVICES SCAN                  ")
    print("=" * 80)

    net_info = get_network_info()
    if not net_info["iface"] or not net_info["subnet"]:
        print("Error: Could not detect an active network interface.")
        sys.exit(1)

    print(f"Interface:       {net_info['iface']}")
    print(f"Local Host IP:   {net_info['local_ip']} (MAC: {net_info['local_mac']})")
    print(f"Default Gateway: {net_info['gateway']}")
    print(f"Network Subnet:  {net_info['subnet']}\n")

    active_pings = sweep_subnet(net_info["subnet"])
    arp_entries = read_arp_cache(net_info["iface"])
    mdns_info = get_mdns_services()

    # Collect all known devices
    all_ips = set(arp_entries.keys()) | set(active_pings)
    if net_info["local_ip"]:
        all_ips.add(net_info["local_ip"])

    devices = []
    for ip in sorted(all_ips, key=lambda x: [int(p) for p in x.split(".")] if "." in x else [0]):
        if ":" in ip:
            continue  # Focus on IPv4 hosts
        mac = arp_entries.get(ip, "")
        is_local = (ip == net_info["local_ip"])
        is_gateway = (ip == net_info["gateway"])

        if is_local:
            mac = net_info["local_mac"] or "Local Interface"
            role = "This Machine"
        elif is_gateway:
            role = "Default Gateway / Router"
        else:
            role = "Network Device"

        vendor = get_oui_vendor(mac) if mac and ":" in mac else "N/A"
        
        hostname = ""
        if ip in mdns_info and "hostname" in mdns_info[ip]:
            hostname = mdns_info[ip]["hostname"]
        if not hostname:
            hostname = resolve_hostname(ip)

        extra = ""
        if ip in mdns_info and "model" in mdns_info[ip]:
            extra = f"Model: {mdns_info[ip]['model']}"

        devices.append({
            "ip": ip,
            "mac": mac,
            "role": role,
            "vendor": vendor,
            "hostname": hostname or "--",
            "extra": extra,
        })

    print(f"\nDiscovered {len(devices)} device(s) on your local subnet:\n")
    header_fmt = "{:<16} {:<19} {:<24} {:<30} {:<20}"
    print(header_fmt.format("IP ADDRESS", "MAC ADDRESS", "ROLE", "VENDOR / MANUFACTURER", "HOSTNAME"))
    print("-" * 115)

    for d in devices:
        vendor_disp = d["vendor"]
        if d["extra"]:
            vendor_disp = f"{d['vendor']} ({d['extra']})"
        if len(vendor_disp) > 29:
            vendor_disp = vendor_disp[:27] + "..."

        print(header_fmt.format(
            d["ip"],
            d["mac"] or "--",
            d["role"],
            vendor_disp,
            d["hostname"][:19]
        ))

    print("\nDetailed Summary:")
    for d in devices:
        details = [d["role"]]
        if d["vendor"] != "N/A":
            details.append(d["vendor"])
        if d["extra"]:
            details.append(d["extra"])
        if d["hostname"] != "--":
            details.append(f"Host: {d['hostname']}")
        print(f" - [{d['ip']}] MAC: {d['mac'] or 'N/A'} -> {' | '.join(details)}")

if __name__ == "__main__":
    main()
