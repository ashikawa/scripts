#!/bin/bash
#
# gcc -O2 `mecab-config --cflags` mecab.c -o mecab `mecab-config --libs`
# http://mecab.sourceforge.net/libmecab.html
# 2009/09/16 ashikawa
#

out=""
sourcefile=""

version="1.0"
usage="Usage: $0 SRCFILE
   or: $0 -o OUTPUT SRCFILES
"
while test -n "$1";
	do
		case $1 in
			-o)
				out="$out $2"
				shift
				shift
				continue;;

		--help)
				echo "$usage";
				exit 0;;

		--version)
				echo "$0 $version";
				exit 0;;

		*)  # When -d is used, all remaining arguments are directories to create.
			# Otherwise, the last argument is the destination.  Remove it from $@.
			for arg
				do
					shift # arg
					sourcefile=$arg
				done
				break;;
			esac
done

if [ -z $sourcefile ]; then
	echo "$usage"
	exit 0;
fi

if [ $out ]; then
	gcc -O2 `mecab-config --cflags` $sourcefile -o $out `mecab-config --libs`
else
	gcc -O2 `mecab-config --cflags` $sourcefile `mecab-config --libs`
fi

exit 0
