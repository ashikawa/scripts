<?php 
echo "足し算プログラム" . PHP_EOL
	. "一つ目の整数を入力してください。" . PHP_EOL;

while (true) { 
  $num1 = fgets(STDIN, 10); 

  //デバッグ用に出力 
  var_dump($num1); 

  $num1 = rtrim($num1, "\n"); 

  if (ctype_digit($num1)) { 
    break; 
  } 
  echo "整数を入力して下さい。\n"; 
} 

echo "二つ目の整数を入力してください。\n"; 
while (true) { 
  $num2 = rtrim(fgets(STDIN, 10), "\n"); 

  if (ctype_digit($num2)) { 
    break; 
  } 
  echo "整数を入力して下さい。\n"; 
} 


$ans = (int)$num1 + (int)$num2;
echo "$num1 + $num2 = $ans" . PHP_EOL;