<?php include("sess.php"); include("conn.php");
	error_reporting(E_ALL ^ E_NOTICE ^ E_WARNING);
	if (!isset($_POST['username']) || !isset($_POST['password']))
		header("location: home.php");
	include("a.inc");
	if ((isset($_POST['username'])) && (isset($_POST['password'])) && (isset($_POST['login'])))
	{
		$username = mysql_real_escape_string(trim(strtolower($_POST['username'])));
		$password = md5(mysql_real_escape_string(trim($_POST['password'])));

		$query = mysql_query("SELECT * FROM users WHERE username='$username' OR password='$password'") or die('This webpage is not available.'.mysql_error());
		if($query)
		{
			if (mysql_num_rows($query) != 0)
			{
				$row = mysql_fetch_object($query);
				$id = $row -> id;
				$uname = $row -> username;
				$pwd = $row -> password;
				$type = $row -> type;

				if(($username  ==  $uname) && ($password  ==  $pwd))
				{
					$_SESSION['valid_id'] = $id;
					$_SESSION['valid_username'] = $username;
					$_SESSION['valid_password'] = $password;
					$_SESSION['valid_type'] = $type;

					$trail = mysql_query("INSERT INTO ztrail(id, name, type, activity) VALUES('".$_SESSION['valid_id']."', '".strtoupper($_SESSION['valid_username'])."','".$_SESSION['valid_type']."','LOGIN')");

					if($type == 'Admin' || $type== 'User')
					{
						echo '<script language="javascript">';
							echo 'location.replace("add.php?u='.$_SESSION['valid_id'].'");';
						echo '</script>';
					}
					else
					{
						session_destroy();
					}
				}
				/*else
				{
					echo '<script type="text/javascript">';
						echo "alert('Invalid User. Please try again.');";
						echo 'location.replace("home.php");';
					echo '</script>';
				}*/
			}
			else
			{
				echo '<script type="text/javascript">';
					echo 'alert("User not found in record.");';
					echo 'location.replace("home.php");';
				echo '</script>';
			}
		}
	}
include("z.inc"); ?>