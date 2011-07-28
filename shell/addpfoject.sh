#!/bin/bash
# 
# svn add project
# 

project=""

usage="Usage: $0 -n PROJECTNAME"

while test -n "$1";
	do
		case $1 in
			-n)
				project="$2"
					shift
					shift
					continue;;

			--help)
				echo "$usage";
				exit 0;;
		esac
done

if [ -z $project ]; then
	echo "$usage"
	exit 0;
fi

mkdir $project \
&& svnadmin create $project \
&& chmod -R 770 $project \
&& chown -R svn:svn $project \
&& chmod -R g+s $project

exit 0
