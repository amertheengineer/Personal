<?php

	$foo = !!'foo';
	echo $foo;
	$val = ‘1.2.3.4.5.6.7.8.9.10.11.12’; 
	$arr[] = array(‘a’ => explode(‘.’,$val));
	echo $arr[9];
?>
