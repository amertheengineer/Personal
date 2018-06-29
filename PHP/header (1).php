<?php
/**
 * The header for our theme
 *
 * This is the template that displays all of the <head> section and everything up until <div id="content">
 *
 * @link https://developer.wordpress.org/themes/basics/template-files/#template-partials
 *
 * @package consult
 */

?>
<!doctype html>
<html <?php language_attributes(); ?>>
<head>
	<meta charset="<?php bloginfo( 'charset' ); ?>">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="profile" href="http://gmpg.org/xfn/11">

	<?php wp_head(); ?>
</head>

<body <?php body_class(); ?>>
<div id="page" class="site">
	

	<header id="masthead" class="site-header">

		<div class="container">

		<div class="topBanner">
			<div class="businessInformation">
				<ul>
					<li class="addressInfo">20109 Natures Hike Way, Tampa, FL, 33647</li>
					<li class="openTimes">Mon-Fri: 8am-5pm</li>
					<li class="phoneNumber">813-447-3566</li>
				</ul>	
			</div><!--/.businessInformation-->
				<div class="businessAdditonalInformation">
					<ul class="socialMedia">

						<li> <a href="#" target="_blank"> <img src="http://www.placehold.it/20x20" alt="facebook icon"/></a></li>
						<li> <a href="#" target="_blank"> <img src="http://www.placehold.it/20x20" alt="twitter icon"/></a></li>
						<li> <a href="#" target="_blank"> <img src="http://www.placehold.it/20x20" alt="linkedin icon"/></a></li>
					</ul>



					<ul class="officeLocations">
						<li class="active location">Tampa</li>
						<li class="location location--1">Florida</li>
						<li class="location location--2">New York</li>
						<li class="location location--3">Toronto</li>

					</ul><!--/.officeLoactions-->
					</div><!--businessAddisitonalInfo-->
						<div class="clear"></div><!--/.clear-->


			</div> <!---/.topBanner-->
			</div><!--/.container--> 

			<div class="heroImage">

				<div class="container">


					<div class="site-branding">

						<a href="#" title ="Business Theme"> <img src="http://placehold.it/240x45" alt="Business logo" /> </a>
					</div><!-- .site-branding -->


					<nav id="site-navigation" class="main-navigation">
						
						<?php
							wp_nav_menu( array(
								'theme_location' => 'menu-1',
								'menu_id'        => 'primary-menu',
							) );
						?>
					</nav><!--#site-navigation-->
		
				<div class="clear"> </div><!--/.clear-->
                <div class="heroImageContent">                  
                   <h1>We are
leaders in the indusrty, not followers, we are setting examples</h1>
<p>Team OVO </p>               



	<a href="#" title="About us" class="Button buttonYellow">about us </a>
  </div><!--/.heroImageContent-->

	</div><!--/.container-->
	</div><!--/.heroImage-->
	</header><!-- #masthead-->


