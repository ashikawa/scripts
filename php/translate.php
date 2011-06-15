<?php
function transverse_matrix($array){
	return call_user_func_array('array_map',array_merge(array(null),$array));
}
print_r(transverse_matrix(array(
    array('Id','Name','Age'),
    array('1','Taro','15'),
    array('2','Hanako','16'),
    array('3','Tom','5400')
)));
