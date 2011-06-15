#!/bin/sh
#
# rsync script for mac
#

options="-avn"

while getopts f OPT 
do
    case $OPT in
        "f")
            options="-av"
            shift
            continue;;
    esac
done

rsync $options \
   --exclude ".svn/" \
   --exclude ".DS_Store" \
   --exclude ".settings/" \
   --exclude ".project" \
   --delete \
   from/* \
   user@domains:/projectdir/
   