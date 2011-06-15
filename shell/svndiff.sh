#!/bin/bash
#
# svn 差分ファイル一覧の取得
# 	Nはリビジョン番号
#
svn diff -r N | awk '/^Index/ {print $NF}'
