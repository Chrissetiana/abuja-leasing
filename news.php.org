<?php include("sess.php"); include("conn.php");
	error_reporting(E_ALL ^ E_NOTICE ^ E_WARNING);
	include("a.inc");
	$query = mysql_query("SELECT * FROM newsfeed WHERE status='Active' ORDER BY added DESC") or die("This webpage is not available. ".mysql_error());
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
					echo '<span class="css-postauthoricon">'.$rows['author'].'</span>';
				echo '</div>';
				echo '<div class="css-postcontent css-postcontent-0 clearfix">';
					echo implode(" ", array_slice(explode(" ", $rows['content']), 0, 100)).'...<a href="news_post.php?article='.urlencode(str_replace("'","",$rows['subject'])).'">Read more...</a>';
				echo '</div>';
				echo '</p><br />';
			}
		}
		else
		{
			echo '<p style="text-align:center;"><img width="400" height="300" alt="" class="css-lightbox" src="images/alc_construction.png"><br /></p>';
		}
	}
include("z.inc"); ?>