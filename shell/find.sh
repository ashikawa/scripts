#!/bin/bash
# ディレクトリから再起的に grep する
#
find . -name "*.*" -exec fgrep -l "search query" {} \;