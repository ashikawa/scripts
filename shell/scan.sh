#!/bin/sh

for i in `seq 2 254`
do
  echo "192.168.1.$i"
  nmap -p 53 192.168.1.$i 
done
