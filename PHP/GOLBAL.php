

<form method="post" action="<?php echo $_SERVER['PHP_SELF'];?>">
  Name: <input type="text" name="fname">  </br>
  Email : <input type = "text" name="email" >  </br>
  Address : <input type = "text" name="addr">  </br>
  Phone Number : <input type = "int" name="num">  </br>
  Comment: <textarea name="comment" rows="5" cols="40"></textarea>
  Gender:
	<input type="radio" name="gender" value="female">Female
	<input type="radio" name="gender" value="male">Male
	<input type="radio" name="gender" value="other">Other
	  <input type="submit">
</form>


<?php
	/*
	$x = 25;
	$y = 75;

	function add()
	{

		return $GLOBALS['x'] + $GLOBALS['y'];
	}
		echo add() . "</br>";


		echo $_SERVER['PHP_SELF'];
		echo "<br>";
		echo $_SERVER['GATEWAY_INTERFACE'];
		echo "<br>";
		echo $_SERVER['HTTP_HOST'];
		echo "<br>";
		echo $_SERVER['HTTP_REFERER'];
		echo "<br>";
		echo $_SERVER['HTTP_USER_AGENT'];
		echo "<br>";
		echo $_SERVER['SERVER_ADMIN'];
*/

		function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}

$name = $email = $gender = $comment = $website = "";
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // collect value of input field
    $name = test_input($_POST['fname']);
    $email = test_input($_POST['email']);
    $addr = test_input($_POST['addr']);
    $Num = test_input($_POST['num']);
    $Comment = test_input($_POST['comment']);
    $gender = test_input($_POST['gender']);
    if (empty($name)) {
        echo "Name is empty";

    } else {
        echo "Name is :" . $name . "</br>";
        echo "Email Address is: " .$email . "</br>";
        echo "House Address is: " .$addr . "</br>";
        echo "Phone Number is: " .$Num . "</br>";
        echo "Comment : " . $Comment . "</br>";
        echo "Gender is : " . $gender . "</br>";
    }
   
}

?>
