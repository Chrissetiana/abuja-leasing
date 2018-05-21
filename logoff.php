<?php include("sess.php"); include("conn.php");
	error_reporting(E_ALL ^ E_NOTICE ^ E_WARNING);
	include("a.inc");
	$trail = mysql_query("INSERT INTO ztrail(id, name, type, activity) VALUES('".$_SESSION['valid_id']."', '".strtoupper($_SESSION['valid_username'])."','".$_SESSION['valid_type']."','LOGOUT')");
	echo '<script language="javascript">';
		echo 'location.replace("logout.php");';
	echo '</script>';
include("z.inc"); ?>