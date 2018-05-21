<?php include("sess.php"); include("conn.php");
	error_reporting(E_ALL ^ E_NOTICE ^ E_WARNING);
	if (!isset($_SESSION['valid_id']))
		header("location: home.php");
	include("a.inc");
	echo '<center>';
		echo '<form method="GET" action="'.htmlspecialchars($_SERVER["PHP_SELF"]).'" target="_self" enctype="multipart/form-data">';
			echo '<br /><h2 class="css-postheader">Add News Item</h2><br /><br />';
			echo '<label for="Subject">Subject:&nbsp;&nbsp;<input type="text" id="subject" name="subject" title="Subject" autocomplete="off" style="width:30%;" /><br /><br />';
			echo '<label for="Author">Author:&nbsp;&nbsp;&nbsp;<input type="text" id="author" name="author" title="Author" autocomplete="off" style="width:30%;" /><br /><br />';
			echo '<label for="Content">Content:&nbsp;<textarea id="content" name="content" title="Content" autocomplete="off" style="width:30%;"></textarea>';
			echo '<br /><br />';
			echo '<input type="submit" id="submit" name="submit" class="css-button css-button" value="Submit" />&nbsp;&nbsp;';
			echo '<input type="reset" id="reset" name="reset" class="css-button css-button" value="Reset" />';
	echo '</center>';
	if($_GET['submit'])
	{
		$trail = mysql_query("INSERT INTO newsfeed(subject, content, author) VALUES('".trim($_GET['subject'])."','".trim($_GET['author'])."','".trim($_GET['content'])."')");
		echo '<script language="javascript">';
			echo 'alert("Action successful!");';
			echo 'location.replace("add.php");';
		echo '</script>';
	}
include("z.inc"); ?>