<?php

	$x = array('Amer', 'Moe');
	$y = array('John', 'Rami');
	$z = $x+$y;

	for ($i=0; $i < count($x + $y); $i++) { 
		echo $z[$i];
	}

	echo count($z);


	// Associative Array ==> Array with index other than numbers

	$age = array('Amer' =>'35' ,'Moe' => '20', 'Rami' => '21' );

	foreach ($age as $key => $value) {
		echo $age[$key] ."</br>";
	}
?>