#!/bin/sh

# stdin for mac

#TIME=`date +'%H:%M:%S'`
#DATE=`date +'%Y%m%d'`  

#echo "input:"
#read CONTEXT

#echo $TIME"\t"$CONTEXT | tee -a ~/"${DATE}.txt"

while read CONTEXT; do
	TIME=`date +'%H:%M:%S'`
	DATE=`date +'%Y%m%d'`  

	if [ $CONTEXT ]; then
		echo $TIME"\t"$CONTEXT | tee -a ~/"${DATE}.txt"
	fi

done

