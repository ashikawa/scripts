#!/bin/sh
#
# rsync script for mac 
#

options="-avnR"

while getopts f OPT 
do
    case $OPT in
        "f")
            options="-avR"
            shift
            continue;;
    esac
done

cd ../www/

rsync -e "ssh -i secret.key" \
	$options \
   --exclude ".svn/" \
   --exclude ".DS_Store" \
   --exclude ".settings/" \
   --exclude ".project" \
   --exclude ".buildpath" \
   --exclude ".htaccess" \
   --exclude "Thumbs.db" \
   --exclude "data/log" \
   --exclude "data/cache" \
   --delete \
	* \
   user@domain:/path/to/dir/
