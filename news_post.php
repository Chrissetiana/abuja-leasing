<?php include("sess.php"); include("conn.php");
	error_reporting(E_ALL ^ E_NOTICE ^ E_WARNING);
	
	include("a.inc");
	$post = urldecode($_GET['article']);
	$query = mysql_query("SELECT * FROM newsfeed WHERE subject='$post' LIMIT 1") or die("This webpage is not available. ".mysql_error());
	if($query)
	{
		if(mysql_num_rows($query) != 0) 
		{
			while($rows = mysql_fetch_array($query))
			{
				echo '<p style="text-align:justify;">';
					echo '<a name="'.urlencode($rows['subject']).'"></a><h2 class="css-postheader">'.$rows['subject'].'</h2>';
					echo '<div class="css-postheadericons css-metadata-icons">';
						echo '<span class="css-postdateicon">'.date('M d, Y', strtotime($rows['added'])).'</span>';
						echo '<span class="css-postauthoricon">'.$rows['author'].'</span>';
					echo '</div>';
					echo '<div class="css-postcontent css-postcontent-0 clearfix">';
						echo $rows['content'];
					echo '</div>';
				echo '</p>';
				echo '<a href="#">Back To Top</a><br /><a href="news.php">Go Back</a>';
			}
		}
	}
include("z.inc"); ?>