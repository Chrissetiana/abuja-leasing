<?php include("sess.php"); include("conn.php");
	error_reporting(E_ALL ^ E_NOTICE ^ E_WARNING); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html dir="ltr" lang="en-US">
	<head>
		<meta charset="utf-8">
		<link href="favicon.ico" rel="shortcut icon" />
		<title>Abuja Leasing Company Limited | Simple Money Solutions</title>
		<meta name="viewport" content="initial-scale = 1.0, maximum-scale = 1.0, user-scalable = no, width = device-width">

		<!--[if lt IE 9]><script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script><![endif]-->
		<link rel="stylesheet" href="style.css" media="screen">
		<!--[if lte IE 7]><link rel="stylesheet" href="style.ie7.css" media="screen" /><![endif]-->
		<link rel="stylesheet" href="style.responsive.css" media="all">

		<script src="jquery.js"></script>
		<script src="script.js"></script>
		<script src="script.responsive.js"></script>
		<meta name="keywords" content="Abuja Leasing Company">

		<?php include("script.inc"); include("style.inc"); ?>
	</head>
	<body>
		<div id="css-main">
			<div class="css-sheet clearfix">
				<?php include("header.inc"); include("nav.inc"); ?>
				<div class="css-layout-wrapper clearfix">
					<div class="css-content-layout">
						<div class="css-content-layout-row">
							<!--sidebar1.inc-->
							<div class="css-layout-cell css-content clearfix">
								<article class="css-post css-article">
									<!--<h2 class="css-postheader">New Page</h2>-->
									<div class="css-postcontent css-postcontent-0 clearfix">
										<?php
											$query = mysql_query("SELECT * FROM quiz WHERE status='Active' ORDER BY rand()") or die("This webpage is not available. ".mysql_error());
											if($query)
											{
												if(mysql_num_rows($query) != 0)
												{
													while($rows = mysql_fetch_array($query))
													{
														echo '<p>'.$rows['question'].'<br />'.$rows['answer'].'</p>';
													}
												}
												else
												{
													echo '<p style="text-align:center;"><img width="400" height="300" alt="" class="css-lightbox" src="images/alc_construction.png"><br /></p>';
												}
											}
										?>
									</div>
								</article>
							</div>
							<!--sidebar2-->
						</div>
					</div>
				</div>
				<?php include("footer.inc"); ?>
			</div>
			<?php include("footnote.inc"); ?>
		</div>
	</body>
	<?php include("script.inc"); include("style.inc"); ?>
	<?php include("headerscript.php"); include("headerstyle.php"); ?>
</html>