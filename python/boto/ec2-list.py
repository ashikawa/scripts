#!/usr/bin/python 
# coding: utf8

from boto.ec2 import EC2Connection

# defaults region
EC2Connection.DefaultRegionName		= "ap-northeast-1"
EC2Connection.DefaultRegionEndpoint	= "ec2.ap-northeast-1.amazonaws.com"

conn = EC2Connection(
	aws_access_key_id		= 'XXXXXXXXXXXXXXX',
	aws_secret_access_key	= 'YYYYYYYYYYYYYYY')

print conn.get_all_instances()
