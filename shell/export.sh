#!/bin/bash

#
# プロジェクトの自動本アップ用シェル
# 2009 12 07 ashikawa
# 
# 構想
# /var/SnacleCircle (シンボリックリンク)
# /var/SnacleCircle1.0		復帰用に最低、一世代は残す
# /var/SnaacleCircle1.5		最新のプロジェクト
#	.......
# 		/var ディレクトリのパーミッションどうしよ？
#		もう一つ掘る？
#		

usage="Usage: $0 -r REPOSITORY PROJECT"

project=""
repository=""

while test -n "$1";
	do
		case $1 in
			-r)
				repository=$2
				shift
				shift
				continue;;
			*)
				project=$1
				shift
				continue;;
		esac
	done


# リポジトリ指定が無い場合。
# 本番では初期値を消しておくつもり
if [ -z $project ]; then
	echo $usage
	exit;
fi

if [ -z $repository ]; then
	echo $usage
	exit;
fi

exit;

echo "export $project $repository"

export CVSROOT=:ext:localhost:/cvs
export CVS_RSH=ssh

# CVSから読み込み
# 本番環境では、リポジトリ名をつけるか、
# -d オプションでディレクトリを指定した後に
# シンボリックリンクを切り替える。

cd /var/
cvs export -r $repository $project

