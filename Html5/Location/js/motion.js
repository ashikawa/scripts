/*
 motion.js
 @copyright s.ashikawa
*/
$(function(){var f=function(){var c=Array(500),a=!0,b;for(b=0;500>b;b++)c[b]=0;return{push:function(b){var e=c[Math.floor(250)],e=Math.abs(e.x)+Math.abs(e.y)+Math.abs(e.z);c.shift();c.push(b);30<e&&a&&(a=!1,window.setTimeout(function(){a=!0},5E3),this.render())},render:function(){var a=c.concat(),b=[],f=[],j=[],d,g=0,h=0,i=0;for(d=0;500>d;d++)g+=a[d].x,h+=a[d].y,i+=a[d].z,0===(d+1)%50&&(b.push(g/50),f.push(h/50),j.push(i/50),i=h=g=0);$.jqplot("plotcanvas",[b,f,j],{}).replot()}}}();window.moments=
f;(function(){function c(a){a=a.accelerationIncludingGravity;f.push({x:a.x,y:a.y,z:a.z})}window.addEventListener("devicemotion",c,!0);window.triggerMotion=function(){var a={},b;for(b=0;1E3>b;b++)a.accelerationIncludingGravity={x:10*Math.random(),y:10*Math.random(),z:10*Math.random()},c(a)}})()});
