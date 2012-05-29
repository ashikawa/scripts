#!/bin/zsh

out=~/Working/`date '+%Y%m%d'`.txt

if test $# -gt 0 ; then
    echo -`date '+%H:%M'` $@ >> $out
fi
cat $out
