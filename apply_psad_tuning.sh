#!/usr/bin/env bash
set -euo pipefail

if [ "$EUID" -ne 0 ]; then
    echo "[-] Error: This script must be run as root. Please run with:"
    echo "    sudo bash $0"
    exit 1
fi

echo "[*] Applying psad tuning for scan evasion mitigation..."

# 1. Update DANGER_LEVEL1 threshold from 5 down to 2 packets
sed -i 's/^DANGER_LEVEL1\s\+[0-9]\+;/DANGER_LEVEL1               2;/' /etc/psad/psad.conf

# 2. Increase SCAN_TIMEOUT from 3600s to 7200s (2 hours tracking window)
sed -i 's/^SCAN_TIMEOUT\s\+[0-9]\+;/SCAN_TIMEOUT                7200;/' /etc/psad/psad.conf

# 3. Ensure PORT_RANGE_SCAN_THRESHOLD is set to 1
sed -i 's/^PORT_RANGE_SCAN_THRESHOLD\s\+[0-9]\+;/PORT_RANGE_SCAN_THRESHOLD   1;/' /etc/psad/psad.conf

# 4. Whitelist default router / gateway in /etc/psad/auto_dl to prevent false positives
GATEWAY_IP=$(ip route | awk '/default/ {print $3}' | head -n 1)
if [ -n "$GATEWAY_IP" ]; then
    if ! grep -q "^[[:space:]]*${GATEWAY_IP}[[:space:]]" /etc/psad/auto_dl; then
        echo "${GATEWAY_IP}        0;    # Whitelist local router / gateway" >> /etc/psad/auto_dl
        echo "[+] Whitelisted gateway IP ${GATEWAY_IP} in /etc/psad/auto_dl"
    else
        echo "[*] Gateway IP ${GATEWAY_IP} is already whitelisted in /etc/psad/auto_dl"
    fi
fi

# Whitelist IPv6 Link-Local prefix (fe80::/10) - used for Neighbor Discovery Protocol (NDP)
if ! grep -q "fe80::/10" /etc/psad/auto_dl; then
    echo "fe80::/10        0;    # Whitelist IPv6 Link-Local (NDP/Router Solicitations)" >> /etc/psad/auto_dl
    echo "[+] Whitelisted fe80::/10 in /etc/psad/auto_dl"
fi

# Whitelist local IPv6 router gateway and subnet
IPV6_GW=$(ip -6 route | awk '/default via/ {print $3}' | head -n 1)
if [ -n "$IPV6_GW" ] && ! grep -q "^[[:space:]]*${IPV6_GW}[[:space:]]" /etc/psad/auto_dl; then
    echo "${IPV6_GW}        0;    # Whitelist IPv6 default gateway" >> /etc/psad/auto_dl
    echo "[+] Whitelisted IPv6 gateway ${IPV6_GW} in /etc/psad/auto_dl"
fi

IPV6_NET=$(ip -6 route | awk '/proto ra/ && /dev/ && !/default/ {print $1}' | head -n 1)
if [ -n "$IPV6_NET" ] && ! grep -q "^[[:space:]]*${IPV6_NET}[[:space:]]" /etc/psad/auto_dl; then
    echo "${IPV6_NET}        0;    # Whitelist local IPv6 subnet" >> /etc/psad/auto_dl
    echo "[+] Whitelisted IPv6 local subnet ${IPV6_NET} in /etc/psad/auto_dl"
fi

# Also add the router's explicit global address if reported
ROUTER_GUA="2405:0201:a006:9a74:4a55:5eff:fe27:0949"
if ! grep -q "$ROUTER_GUA" /etc/psad/auto_dl; then
    echo "${ROUTER_GUA}        0;    # Router global IPv6" >> /etc/psad/auto_dl
    echo "[+] Whitelisted router GUA ${ROUTER_GUA} in /etc/psad/auto_dl"
fi

echo "[*] Cleaning up orphaned psad processes..."
pkill -9 -f psad 2>/dev/null || true
sleep 1

echo "[*] Starting psad service with systemd..."
systemctl restart psad.service

echo "[✓] Successfully tuned psad and restarted the service!"
