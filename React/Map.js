<html lang="en">
<head>
  <meta charset="utf-8">

  <title>The HTML5 Herald</title>

  <link rel="stylesheet" href="https://unpkg.com/leaflet@1.3.3/dist/leaflet.css" />
  <style>
  		#mapid
  		{
  			position: absolute;
  			top: 0;
  			right: 0;
  			bottom: 0;
  			left: 0;
  		}
  </style>
</head>

<body>
  		<div id="mapid"></div>
<script src="https://unpkg.com/leaflet@1.3.3/dist/leaflet.js"></script>
<script>
	// instantiate the map ==> setView ==> Latitude and Logitude 
	// Zoom level 0 shows whole world and zoom level 20 shows street level 
		var mymap = L.map('mapid').setView([40.7128, -74.0059],13);

		var layer = L.tileLayer('http://1.basemaps.cartocdn.com/light_all/0/0/0.png',
			{
					attribution: '&copy; <a href="http://www.openstreetmap.org/copyright">
					OpenStreetMap</a> contributors, &copy;<a href="https://carto.com/
					attributions">CARTO</a>'
			}).addTo(mymap)

		/*
			Tile tags: each corresponds to the number of tiles u want to fit on the map
			0 ==> whole world
			*****
		*/
</script>
</body>
</html>

