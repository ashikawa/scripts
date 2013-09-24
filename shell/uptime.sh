#!/bin/sh

#
# check load average and echo server status
#
# cron
# */10 * * * * /path/to/watch.sh

LOAD=`uptime | awk '{print $10}' | sed -e "s/,//g"`
FLAG=`echo "$LOAD >= 1.0" | bc`

if [ "$FLAG" -eq 1 ]; then
{
    echo "=====" `date`  "====="
    echo "=== uptime ==="
    uptime
    echo "=== free ==="
    free
    echo "=== vmstat ==="
    vmstat
    echo "=== ps aux ==="
    ps aux
} | /usr/sbin/rotatelogs /home/ec2-user/watch/watch_log 86400 -f3
fi