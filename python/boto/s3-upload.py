#!/usr/bin/python 
# coding: utf8

import sys
from boto.s3.connection import S3Connection
from boto.s3.key import Key

AWS_ACCESS_KEY	= 'XXXXXXXXXX'
AWS_SECRET_KEY	= 'YYYYYYYYYY'
BUCKET_NAME		= 'mybucket'

conn = S3Connection(
	aws_access_key_id		= AWS_ACCESS_KEY,
	aws_secret_access_key	= AWS_SECRET_KEY)

bucket = conn.get_bucket(BUCKET_NAME)

print "connect:", bucket

if len(sys.argv) == 1:
    print "Error: no input file specified"
    sys.exit()


args = sys.argv
# arg[0] は実行スクリプト名なのでスキップ
args.pop(0)

for arg in args:
	upload_file = arg

	key		= Key(bucket)
	key.key	= upload_file
	key.set_contents_from_filename(upload_file)

	# web 公開モードにする
	key.make_public()
	print "upload file:", key
