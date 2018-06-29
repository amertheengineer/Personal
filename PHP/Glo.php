<form method="post" action="<?php echo $_SERVER['PHP_SELF'];?>">
Name : <input type ="text" name = "fname" value = "<?php echo $fname;?>">
Email : <input type ="text" name = "email" value = "<?php echo $email;?>">
Website : <input type ="text" name = "Website" value = "<?php echo $Website;?>">

Comment : <textarea name = "coment" rows = "5" columns = "5" value =  "<?php echo $coment;?>">
</textarea>
<input type="submit">

</form>

<?php
		
		$name = $em = $web = $com = ""	;
if($_SERVER["REQUEST_METHOD"] == "POST")
{
	$name = $_POST['fname'];
	$em = $_POST['email'];
	$web = $_POST['Website'];
	$com = $_POST['coment'];

	echo "Name is : "  . $name . "</br>";
	echo "Email is : " . $em . "</br>";
	echo "Website is : " . $web . "</br>";
	echo "Comment is : " . $com . "</br>";
}
	


?>
