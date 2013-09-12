#!/bin/sh

#
# check load average and echo server status
#

LOAD=`uptime | awk '{print $9}' | sed -e "s/,//g"`
FLAG=`echo "$LOAD > 5.0" | bc`

if [ "$FLAG" -eq 1 ]; then
	echo "== top n 1 b =="
	top n 1 b
	echo "== ps aux =="
	ps aux
	echo "== netstat -an =="
	netstat -an
	echo "== df -i =="
	df -i
#else
 # Nothing to do
fi
