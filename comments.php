<?php
include("sess.php");
include("conn.php");
	error_reporting(E_ALL ^ E_NOTICE ^ E_WARNING);
	include("a.inc");
	echo '<form method="GET" action="'.htmlspecialchars($_SERVER["PHP_SELF"]).'" target="_self" enctype="multipart/form-data">';
		include("conn.php");
		$query = mysql_query("SELECT * FROM feedback WHERE status='Active' ORDER BY added DESC LIMIT 10") or die("This webpage is not available. ".mysql_error());
		if($query)
		{
			if(mysql_num_rows($query) != 0)
			{
				while($rows = mysql_fetch_array($query))
				{
					echo '<p style="text-align:justify;';
					echo '<a name="'.urlencode($rows['subject']).'"></a><h6 class="css-postheader">'.$rows['subject'].'</h6>';
					echo '<div class="css-postheadericons css-metadata-icons">';
						echo '<span class="css-postdateicon">'.date('M d, Y', strtotime($rows['added'])).'</span>';
						echo '<span class="css-postauthoricon">'.$rows['name'].'</span>';
					echo '</div>';
					echo '<div class="css-postcontent css-postcontent-0 clearfix">';
						//echo implode(" ", array_slice(explode(" ", $rows['msg']), 0, 100)).'...<a href="news.php?article='.urlencode($rows['subject']).'">Read more...</a>';
						echo $rows['msg'];
					echo '</div>';
					echo '</p><br />';
				}
			}
		}
	echo '</form>';
include("z.inc"); ?>