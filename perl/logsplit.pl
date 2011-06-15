#!/usr/bin/perl

# ecample
# [Thu Jun  2 23:54:40 2011] [error] [client 192.168.0.0] File does not exist: /path/to/rsource/favicon.ico

while(<>){
	if(/\[(.*?)\] \[(.*?)\] \[(.*?)\] (.*)/){
	
		# $1 date
		# $2 error level
		# $3 client
		# $4 message
		
		# print "$1, $2, $3, $4\n";
		print "$1, $2, $3, $4\n";
	}
}
