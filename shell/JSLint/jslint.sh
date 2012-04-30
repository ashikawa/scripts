#!/bin/sh

#Dependencies
#Set paths appropriately to the 'core' jslint javascript file and to the jslinter wrapper script
#JSLINT=`dirname $0`/fulljslint.js
JSLINT=`dirname $0`/jslint.js
JSC_WRAPPER=`dirname $0`/jsc_jslint_wrapper.js

if [ $# = "0" ]
then 
	echo 'Usage: \njslint file(s)'
	echo 'Examples:'
	echo 'jslint file.js file2.js'
	echo 'jslint folder/*.js folder2/*.js'

else
	#Loop over arguments, invoking jslint for each file separetely
	for sourcefile in "$@"
	do
		echo "\n=== $sourcefile ==="

		#Check that file exists
		if [ ! -r $sourcefile -o ! -s $sourcefile ]
		then
			echo "FIle is not readable or empty"
			continue
		fi

		#Invoke jslint via jsc
		/System/Library/Frameworks/JavaScriptCore.framework/Versions/A/Resources/jsc $JSLINT $JSC_WRAPPER -- "`cat $sourcefile`"

		echo "==="		
	done
fi