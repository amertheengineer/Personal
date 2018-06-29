



<?php

	

	if (isset($_POST['submit'])) {
		$files = $_FILES['file'];
		
		$file_name = $FILES['file']['name'];
		$file_tmpname = $FILES['file']['tmp_name'];
		$file_size = $FILES['file']['size'];

		$file_ext = explode('.',$file_name);
		$file2ext = strtolower(end($file_ext));
		
		$allow  = array('jpg','jpeg','pdf');

		if (in_array($file2ext, $allow)) {
			if($file_size < 500000)
			{
					$newfile = uniqid('', true).".".$file2ext; 
					$filedest = 'upload/'.$newfile;

					move_uploaded_file($file_tmpname, $filedest);
			}
			else 
			{
				echo "File too big";
			}
		}
			else
			{
				echo "Can't upload";
			}
	}


?>
