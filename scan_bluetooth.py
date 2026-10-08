#!/usr/bin/env python3
"""
scan_bluetooth.py - Scan for nearby Bluetooth and BLE devices using bluetoothctl.
Resolves device names, manufacturer IDs, service UUIDs, and hardware vendors.
"""

import argparse
import os
import re
import subprocess
import sys
import time

COMPANY_IDS = {
    0x004c: "Apple, Inc.",
    0x0006: "Microsoft",
    0x00e0: "Google LLC",
    0x0075: "Samsung Electronics",
    0x000a: "Qualcomm Technologies",
    0x0002: "Intel Corporation",
    0x000f: "Broadcom",
    0x0087: "Garmin International",
    0x01ab: "Anker Innovations",
    0x0157: "Xiaomi Inc.",
    0x0059: "Nordic Semiconductor",
    0x02e5: "Amazon Lab126",
    0x0001: "Nokia Mobile Phones",
    0x0003: "IBM Corp.",
    0x0004: "Toshiba Corp.",
    0x0005: "3Com",
    0x000d: "Texas Instruments",
    0x001d: "Qualcomm",
    0x002d: "Sony Corporation",
    0x0046: "MediaTek, Inc.",
    0x0060: "Cisco Systems",
}

UUID_DESCRIPTIONS = {
    "0000fd69": "Samsung Electronics",
    "0000fe2c": "Google Fast Pair",
    "0000fe9f": "Google LLC",
    "0000feed": "Tile Tracker",
    "0000110a": "Audio Source",
    "0000110b": "Audio Sink (Headphones/Speaker)",
    "0000110c": "A/V Remote Control Target",
    "0000110e": "A/V Remote Control",
    "0000111e": "Handsfree",
    "00001124": "HID (Keyboard/Mouse)",
    "00001200": "PnP Information",
    "00001800": "Generic Access",
    "00001801": "Generic Attribute",
    "0000180a": "Device Information",
    "0000180f": "Battery Service",
    "00001812": "HID Service",
}

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
    return None

def run_cmd(cmd, timeout=30):
    try:
        res = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, timeout=timeout)
        return res.stdout
    except Exception as e:
        return ""

def scan_bluetooth(duration=10):
    print(f"Scanning for Bluetooth/BLE devices for {duration} seconds...")
    run_cmd(["bluetoothctl", "--timeout", str(duration), "scan", "on"], timeout=duration + 5)
    raw_devices = run_cmd(["bluetoothctl", "devices"])
    
    devices = []
    for line in raw_devices.strip().split("\n"):
        match = re.match(r"^Device\s+([0-9A-Fa-f:]+)\s*(.*)$", line)
        if match:
            mac = match.group(1).upper()
            name = match.group(2).strip()
            devices.append((mac, name))
    return devices

def get_device_info(mac):
    info_raw = run_cmd(["bluetoothctl", "info", mac])
    info = {
        "mac": mac,
        "name": mac,
        "addr_type": "public",
        "rssi": "N/A",
        "tx_power": "N/A",
        "manufacturer": None,
        "manufacturer_id": None,
        "services": [],
        "classification": "Unknown Device",
        "paired": False,
        "connected": False,
    }
    
    for line in info_raw.split("\n"):
        line = line.strip()
        if line.startswith("Device ") and "(" in line and ")" in line:
            if "random" in line.lower():
                info["addr_type"] = "random (private)"
            elif "public" in line.lower():
                info["addr_type"] = "public"
        elif line.startswith("Name:"):
            info["name"] = line.split(":", 1)[1].strip()
        elif line.startswith("Alias:") and info["name"] == mac:
            info["name"] = line.split(":", 1)[1].strip()
        elif line.startswith("RSSI:"):
            rssi_val = line.split(":", 1)[1].strip()
            # If formatted like 0xffffffb6 (-74), extract the decimal
            m = re.search(r"\((-?\d+)\)", rssi_val)
            if m:
                info["rssi"] = f"{m.group(1)} dBm"
            else:
                info["rssi"] = f"{rssi_val} dBm"
        elif line.startswith("TxPower:"):
            tx_val = line.split(":", 1)[1].strip()
            m = re.search(r"\((-?\d+)\)", tx_val)
            if m:
                info["tx_power"] = f"{m.group(1)} dBm"
            else:
                info["tx_power"] = f"{tx_val} dBm"
        elif line.startswith("ManufacturerData.Key:"):
            val_str = line.split(":", 1)[1].strip()
            # e.g., 0x004c (76)
            m = re.search(r"0x([0-9a-fA-F]+)", val_str)
            if m:
                key_int = int(m.group(1), 16)
                info["manufacturer_id"] = hex(key_int)
                if key_int in COMPANY_IDS:
                    info["manufacturer"] = COMPANY_IDS[key_int]
        elif line.startswith("UUID:"):
            uuid_line = line.split(":", 1)[1].strip()
            for short_uuid, desc in UUID_DESCRIPTIONS.items():
                if short_uuid in uuid_line.lower():
                    info["services"].append(desc)
        elif line.startswith("Paired:"):
            info["paired"] = "yes" in line.lower()
        elif line.startswith("Connected:"):
            info["connected"] = "yes" in line.lower()

    # Determine vendor & classification
    if info["addr_type"] == "public" and not info["manufacturer"]:
        oui_vendor = get_oui_vendor(mac)
        if oui_vendor:
            info["manufacturer"] = oui_vendor

    # Classify device
    if info["manufacturer"]:
        if "Apple" in info["manufacturer"]:
            info["classification"] = "Apple Device (iPhone / iPad / Mac / Watch / AirTag)"
        elif "Samsung" in info["manufacturer"]:
            info["classification"] = "Samsung Device (Galaxy / Wearable / SmartThings)"
        elif "Microsoft" in info["manufacturer"]:
            info["classification"] = "Microsoft Device (Surface / Peripherals)"
        elif "Google" in info["manufacturer"]:
            info["classification"] = "Google Device (Pixel / Nest / Wearable)"
        else:
            info["classification"] = f"{info['manufacturer']} Device"
    elif any("Audio" in s or "Handsfree" in s for s in info["services"]):
        info["classification"] = "Bluetooth Audio Device"
    elif any("HID" in s for s in info["services"]):
        info["classification"] = "Bluetooth Keyboard/Mouse/HID"
    elif any("Samsung" in s for s in info["services"]):
        info["classification"] = "Samsung Device (BLE Service)"
    elif any("Tile" in s for s in info["services"]):
        info["classification"] = "Tile Tracker Beacon"

    return info

def main():
    parser = argparse.ArgumentParser(description="Scan for nearby Bluetooth/BLE devices.")
    parser.add_argument("-t", "--timeout", type=int, default=10, help="Scan timeout in seconds (default: 10)")
    args = parser.parse_args()

    print("=" * 80)
    print("                      NEARBY BLUETOOTH / BLE SCAN                       ")
    print("=" * 80)

    devices = scan_bluetooth(args.timeout)
    if not devices:
        print("No Bluetooth devices found in range or Bluetooth adapter unavailable.")
        return

    print(f"\nDiscovered {len(devices)} device(s):\n")
    header_fmt = "{:<19} {:<24} {:<18} {:<10} {:<30}"
    print(header_fmt.format("MAC ADDRESS", "NAME / ALIAS", "ADDRESS TYPE", "RSSI", "IDENTIFIED TYPE / VENDOR"))
    print("-" * 105)

    for mac, alias in devices:
        info = get_device_info(mac)
        display_name = info["name"] if info["name"] != mac else alias
        if len(display_name) > 23:
            display_name = display_name[:20] + "..."
        classification = info["classification"]
        if len(classification) > 29:
            classification = classification[:27] + "..."

        print(header_fmt.format(
            mac,
            display_name,
            info["addr_type"],
            info["rssi"],
            classification
        ))

    print("\nDetailed Insights:")
    for mac, _ in devices:
        info = get_device_info(mac)
        extra = []
        if info["manufacturer"]:
            extra.append(f"Manufacturer: {info['manufacturer']} ({info['manufacturer_id']})")
        if info["services"]:
            extra.append(f"Services: {', '.join(set(info['services']))}")
        if info["connected"]:
            extra.append("Connected")
        if info["paired"]:
            extra.append("Paired")
        details = " | ".join(extra) if extra else "Generic BLE advertisement"
        print(f" - [{mac}] {info['name']}: {details}")

if __name__ == "__main__":
    main()
