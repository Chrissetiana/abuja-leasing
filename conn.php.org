<?php
	$link = mysql_connect("localhost", "root", "") or die ("Could not connect to web server<br />".mysql_error());
	//$link = mysql_connect("abujale.accountsupportmysql.com", "alcweb", "alcweb") or die ("Could not connect to web server<br />".mysql_error());
	$linkdb = mysql_select_db("alc")or die("Could not open database<br />".mysql_error());
?>