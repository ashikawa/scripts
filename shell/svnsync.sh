#!/bin/sh

#
# リポジトリの引っ越し
# 2012/07/09 ashikawa
#

# 初回のみ
# svnsync init svn+ssh://user@desc/path/to/svn https://user@origin/path/to/svn

svnsync sync svn+ssh://user@desc/path/to/svn