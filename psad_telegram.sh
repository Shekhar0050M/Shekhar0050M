#!/usr/bin/env bash
#
# psad Telegram Notification Script
# Called automatically by psad when a port scan is detected.
# Argument 1: Attacker Source IP (SRCIP)
#

SRC_IP="${1:-Unknown}"
BOT_TOKEN="8936950741:AAGJI-lQVvqsNhaOYikDBayh852_mbS9AUk"
CHAT_ID="8980203857"
HOSTNAME="$(hostname 2>/dev/null || echo 'localhost')"
TIMESTAMP="$(date '+%Y-%m-%d %H:%M:%S')"

# Cooldown / throttling: at most 1 alert every 30 seconds per attacker IP
THROTTLE_DIR="/var/run/psad/throttle"
mkdir -p "$THROTTLE_DIR" 2>/dev/null || true
THROTTLE_FILE="${THROTTLE_DIR}/${SRC_IP}.last"
NOW=$(date +%s)

if [ -f "$THROTTLE_FILE" ]; then
    LAST=$(cat "$THROTTLE_FILE" 2>/dev/null || echo 0)
    DIFF=$((NOW - LAST))
    if [ "$DIFF" -lt 30 ]; then
        exit 0
    fi
fi
echo "$NOW" > "$THROTTLE_FILE" 2>/dev/null || true

# Inspect psad logs for alert details
PSAD_DIR="/var/log/psad/${SRC_IP}"
DANGER_LEVEL="1"
if [ -f "${PSAD_DIR}/danger_level" ]; then
    DANGER_LEVEL="$(cat "${PSAD_DIR}/danger_level" 2>/dev/null | tr -d '\r\n')"
fi

ALERT_FILE=$(find "${PSAD_DIR}" -name "*_email_alert" -type f 2>/dev/null | head -n 1)
TCP_INFO=""
UDP_INFO=""
FLAGS_INFO=""
SIG_INFO=""

if [ -n "$ALERT_FILE" ] && [ -f "$ALERT_FILE" ]; then
    TCP_INFO=$(grep -m 1 "Scanned TCP ports:" "$ALERT_FILE" 2>/dev/null | sed -e 's/^[ \t]*//' || true)
    UDP_INFO=$(grep -m 1 "Scanned UDP ports:" "$ALERT_FILE" 2>/dev/null | sed -e 's/^[ \t]*//' || true)
    FLAGS_INFO=$(grep -m 1 "TCP flags:" "$ALERT_FILE" 2>/dev/null | sed -e 's/^[ \t]*//' || true)
    SIG_INFO=$(grep -m 1 "Signature match:" "$ALERT_FILE" 2>/dev/null | sed -e 's/^[ \t]*//' || true)
fi

# Build message payload
MSG="🚨 *[psad Port Scan Alert]*
*Host:* \`${HOSTNAME}\`
*Attacker IP:* \`${SRC_IP}\`
*Danger Level:* *${DANGER_LEVEL} / 5*
*Time:* ${TIMESTAMP}"

if [ -n "$TCP_INFO" ]; then
    MSG="${MSG}
*${TCP_INFO}*"
fi

if [ -n "$UDP_INFO" ]; then
    MSG="${MSG}
*${UDP_INFO}*"
fi

if [ -n "$FLAGS_INFO" ]; then
    MSG="${MSG}
*${FLAGS_INFO}*"
fi

if [ -n "$SIG_INFO" ]; then
    MSG="${MSG}
*${SIG_INFO}*"
fi

curl -s -X POST "https://api.telegram.org/bot${BOT_TOKEN}/sendMessage" \
    -d "chat_id=${CHAT_ID}" \
    -d "parse_mode=Markdown" \
    --data-urlencode "text=${MSG}" > /dev/null 2>&1
