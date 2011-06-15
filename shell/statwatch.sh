#! /bin/bash

while [ 1 ]; do
 PROC=`netstat -an | fgrep -c 5432`
 echo $PROC
 sleep 5 
done

