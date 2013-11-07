#!/bin/sh
source ~/.bash_profile

jscompile \
    --js=motion.js \
    >> ../motion.js

jscompile \
    --js=orient.js \
    >> ../orient.js
