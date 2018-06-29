<?php
/*
	$str = "Hello Amer";

	$val = strlen($str);



	$arr = explode('A',$str);
	$arr2 = implode('', $arr)	;


	foreach ($arr as $key) {
		echo $key . '</br>';
	}

	$str1 = "Hello Amer";
	$str2 = "Hello Moe";


	if(strcmp($str1, $str2) == 0)
	{
		echo $str1 . "is the same as " . $str2;
	}
	else
	{
		echo " They're not the same, they're different by : " . strcmp($str1, $str2);
	}
*/
		$str = "Amer";
		$str1 = "Jeff loves Amer tbh";

		$newstr = str_replace("Jeff", $str, $str1);

		echo $newstr;


	// rtrim($str) => Trims right white spaces
	// ltrim => Trims all the right spaces
	// trim => Trims all the white spaces
	// strtoupper($string)
	// strtolower(String)
	// ucfirst($string)
	//String to Aray : 
	// explode( ) => String to array
	// implode() => Array to string 
	// substr($string , start, end) => subset of strings

	// strcmp(str1 , str2) => returns 0 if equal, difference in str1 and str2 otherwise
	// Conversion Code

	/*
			b : int to binary
			c : int to char
			d : int to dec
			f : double to float
			o : int to octal
			s : string to string
			x : int to hexa
	*/			

?>