#!/usr/bin/env python3
"""
scan_all.py - Master device discovery suite.
Orchestrates Wi-Fi, Bluetooth, Local Network (LAN), and Hardware Peripheral scans.

Usage:
    ./scan_all.py                 # Run complete discovery scan
    ./scan_all.py --wifi          # Scan only nearby Wi-Fi APs and hotspots
    ./scan_all.py --bluetooth     # Scan only nearby Bluetooth / BLE devices
    ./scan_all.py --lan           # Scan only devices on the local subnet
    ./scan_all.py --peripherals   # Inspect attached physical hardware
    ./scan_all.py --bt-timeout 10 # Configure Bluetooth scan duration (seconds)
"""

import argparse
import os
import subprocess
import sys

BASE_DIR = os.path.dirname(os.path.abspath(__file__))

def run_script(script_name, args=None):
    script_path = os.path.join(BASE_DIR, script_name)
    if not os.path.exists(script_path):
        print(f"Error: Script not found: {script_path}")
        return

    cmd = [script_path]
    if args:
        cmd.extend(args)

    try:
        subprocess.run(cmd)
    except Exception as e:
        print(f"Error running {script_name}: {e}")

def main():
    parser = argparse.ArgumentParser(description="Comprehensive Nearby & Local Device Discovery Suite")
    parser.add_argument("--wifi", action="store_true", help="Run Wi-Fi network and hotspot scan")
    parser.add_argument("--bluetooth", action="store_true", help="Run Bluetooth and BLE scan")
    parser.add_argument("--lan", action="store_true", help="Run Local Subnet (LAN) scan")
    parser.add_argument("--peripherals", action="store_true", help="Run Connected Hardware / Peripherals scan")
    parser.add_argument("--bt-timeout", type=int, default=8, help="Bluetooth scan duration in seconds (default: 8)")
    
    args = parser.parse_args()

    # If no specific module was chosen, run all of them
    run_all = not (args.wifi or args.bluetooth or args.lan or args.peripherals)

    print("================================================================================")
    print("                    NEARBY & CONNECTED DEVICE DISCOVERY SUITE                   ")
    print("================================================================================")
    print("Working Directory: " + BASE_DIR)
    print("")

    if run_all or args.bluetooth:
        run_script("scan_bluetooth.py", ["-t", str(args.bt_timeout)])
        print("\n" + "=" * 80 + "\n")

    if run_all or args.lan:
        run_script("scan_lan.py")
        print("\n" + "=" * 80 + "\n")

    if run_all or args.wifi:
        run_script("scan_wifi.sh")
        print("\n" + "=" * 80 + "\n")

    if run_all or args.peripherals:
        run_script("scan_peripherals.sh")
        print("\n" + "=" * 80 + "\n")

    print("Scan completed successfully.")

if __name__ == "__main__":
    main()
