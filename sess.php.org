<?php
	session_start();
	include("conn.php");

	/**if(!isset($_SESSION['valid_username']) && !isset($_SESSION['valid_password']))
	{
		echo '<script language="javascript">';
			echo 'location.replace("home.php");';
		echo '</script>';
	}**/
	$_SESSION['EXPIRES'] = time() + 3600;

	if (!isset($_SESSION['EXPIRES']) || $_SESSION['EXPIRES'] < time() + 3600)
	{
		session_destroy();
		$_SESSION = array();
	}
	$_SESSION['EXPIRES'] = time() + 3600;
?>