# Setup

```:shell
cd /usr/local/src/
wget http://nodejs.org/dist/node-latest.tar.gz
tar zxvf node-v0.10.20-linux-x64.tar.gz 
cd node-v0.10.20/
./configure
make
make install

node -v
npm install -g express
```

# INIT

```:shell
cd ~
express --sessions --css stylus --ejs Twilio
cd Twilio
npm install
```
