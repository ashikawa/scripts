#!/bin/sh

# stdin for mac

TIME=`date +'%H:%M:%S'`
DATE=`date +'%Y%m%d'`  

echo "input:"
read CONTEXT

echo $TIME"\t"$CONTEXT | tee -a ~/"${DATE}.txt"

