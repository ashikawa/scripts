#!/bin/sh
#
# WEB SERVER 死活監視用シェル
#
DOMAIN="http://mydomain.com"
TOMAIL="admin@gmial.com"

ping -c 1 $DOMAIN > /dev/null 2>&1 \
	|| (echo "no response from server" | mail -s ping_alert $TOMAIL)

wget -q -o /dev/null $DOMAIN \
	|| (echo "no response from server" | mail -s ping_alert $TOMAIL)
