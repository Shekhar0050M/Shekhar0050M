#!/usr/bin/env bash
# scan_peripherals.sh - Inspect physical and connected hardware devices on the system.

set -euo pipefail

echo "================================================================================"
echo "                  CONNECTED HARDWARE & PHYSICAL PERIPHERALS                     "
echo "================================================================================"

echo ""
echo "--- [1] SYSTEM & CHASSIS IDENTIFICATION ---"
if command -v hostnamectl >/dev/null 2>&1; then
    hostnamectl | grep -E "Static hostname|Icon name|Chassis|Operating System|Kernel|Architecture|Hardware Vendor|Hardware Model" || true
fi

echo ""
echo "--- [2] USB ATTACHED DEVICES ---"
if command -v lsusb >/dev/null 2>&1; then
    lsusb | while read -r line; do
        echo " - $line"
    done
else
    echo "lsusb command not found."
fi

echo ""
echo "--- [3] AUDIO & MULTIMEDIA DEVICES ---"
if [ -d /dev/snd ]; then
    echo "Sound Cards / Audio Codecs:"
    if [ -f /proc/asound/cards ]; then
        sed 's/^/   /' /proc/asound/cards
    fi
fi

if ls /dev/video* >/dev/null 2>&1; then
    echo "Video Capture / Webcams:"
    for dev in /dev/video*; do
        if [ -e "$dev" ]; then
            name=$(cat "/sys/class/video4linux/$(basename "$dev")/name" 2>/dev/null || echo "Camera")
            echo " - $dev: $name"
        fi
    done
fi

echo ""
echo "--- [4] NETWORK INTERFACES ---"
ip -br link show | while read -r line; do
    echo " - $line"
done

echo ""
echo "--- [5] BLUETOOTH CONTROLLER ---"
if command -v bluetoothctl >/dev/null 2>&1; then
    bluetoothctl show 2>/dev/null | grep -E "Controller|Name|Alias|Powered|Discovering" | sed 's/^/ - /' || true
fi
