#!/usr/bin/env bash
# scan_wifi.sh - Scan and display nearby Wi-Fi access points and mobile hotspots.

set -euo pipefail

echo "================================================================================"
echo "                   NEARBY WI-FI NETWORKS & HOTSPOTS SCAN                        "
echo "================================================================================"
echo "Initiating Wi-Fi scan..."

# Request fresh Wi-Fi rescan (suppressing errors if interface busy)
nmcli dev wifi rescan 2>/dev/null || true
sleep 1

# Process and display table with hotspot detection
python3 -c '
import subprocess
import re

try:
    output = subprocess.check_output(["nmcli", "-e", "no", "dev", "wifi", "list"], text=True)
except Exception as e:
    print(f"Error executing nmcli: {e}")
    exit(1)

lines = output.strip().split("\n")
if not lines:
    print("No Wi-Fi networks found.")
    exit(0)

header = lines[0]
print(f"{header}  TYPE")
print("-" * (len(header) + 18))

hotspot_pattern = re.compile(r"(iphone|galaxy|pixel|oneplus|realme|redmi|vivo|oppo|moto|android|hotspot|phone)", re.IGNORECASE)

for line in lines[1:]:
    device_type = "Access Point"
    if hotspot_pattern.search(line):
        device_type = "Mobile Hotspot"
    elif "--" in line:
        device_type = "Hidden AP"
    print(f"{line:<{len(header)}}  {device_type}")

print("\nNote: \"*\" indicates your current connected Wi-Fi access point.")
'
