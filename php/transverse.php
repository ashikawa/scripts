<?php
/**
 * 配列の転地行列
 * @param array $array
 */
function transverse_matrix($array){
	return call_user_func_array('array_map',array_merge(array(null),$array));
}

$array = array(
	array('Id','Name','Age'),
	array('1','Taro','15'),
	array('2','Hanako','16'),
	array('3','Tom','5400'),
);
print_r(transverse_matrix($array));
