#!/bin/sh
rndstr=""
while [ `echo ${rndstr} | wc -m` -le 8 ]; do
  rndnum=`od -N1 -D /dev/urandom | sed "s/0* *//;q"`
  rnd=`expr ${rndnum} % 75 + 48` 
  if [ ${rnd} -ge 58 -a ${rnd} -le 64 -o ${rnd} -ge 91 -a ${rnd} -le 96 ]; then
    continue
  fi  
  rndx=`printf %o ${rnd}`
  rndstr=${rndstr}`printf \\\"${rndx}"`
done
echo ${rndstr}
# ついでにクリップボードにコピー
echo ${rndstr} | pbcopy
