<?php echo "Welcome to OOP in PHP";?>


<?php

	class Costumer
	{

		protected $name;
		protected $height;
		protected $weight;
		protected $Fav_sport;
		protected $id;

		function get_name()
		{
			return "Name : " . $this->name . <"/br">;
		}
		function get_height()
		{
			return "Height is :" . $this->height . <"/br">;
		}
		function get_weight()
		{
			return "Weight is :" . $this->weight . "Pounds" . <"/br">;
		}
		function get_favsport()
		{
			return "Favorite sport is :" . $this->Fav_sport . <"/br">;
		}
		function get_id()
		{
			return $this->id;
		}
		function __set($thisname,$val)
		{
			switch($thisname)
			{
				case "name":
					$this->name = $val;
					break;
				case "height":
					$this->height = $val;
					break;
				case "weight":
					$this->weight = $val;
					break;	
				case "Fav_sport":
					$this->Fav_sport = $val;	
					break;
				case "id":
					$this->id = $val;
					break;
				default :
					break;
			}

			echo "Set " . $thisname  . " to" . $val;
		}
		f



		function __construct(){

			$this->id = rand(100,100000000);
			echo $this->id . " has been made";


		}
	}




?>