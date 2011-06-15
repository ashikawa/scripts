#!/bin/bash

USER="*****"
PASSWD="*****"

if [ x"$1" = "x" ]; then
        DATE=`date +%Y%m%d --date '1 day ago'`
else
        DATE=$1
fi

expect -c "
set timeout 600
spawn scp -v $USER@192.168.0.***:/path/to/dir/* ./local/
expect \"$USER@server name password:\" {
   send $PASSWD\r
}
expect {
        \"Exit status 0\" { exit 0 } \
}
"
