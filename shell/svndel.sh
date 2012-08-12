#!/bin/sh
find . -name ".svn" -type d -exec echo delete {} ";" -exec rm -rf {} ";"