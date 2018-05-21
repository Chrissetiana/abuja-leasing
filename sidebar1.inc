<?php include("conn.php"); ?>
<div class="css-layout-cell css-sidebar1 clearfix">
	<div class="css-block clearfix">
		<div class="css-blockheader"><h3 class="t">Credit Checklist</h3></div>
		<div class="css-blockcontent">
			<p><a href="credit_score.php" target="_blank"><blink>Check your credit score now!!</blink></a></p>
		</div>
	</div>
	<div class="css-vmenublock clearfix">
        <div class="css-vmenublockheader"><h3 class="t">Newsfeed</h3></div>
        <div class="css-vmenublockcontent">
			<ul class="css-vmenu">
				<li><a href="#">2014</a><ul>
					<?php getNews(2014); ?></ul></li>
				<li><a href="#">2013</a><ul>
					<?php getNews(2013); ?></ul></li>
				<li><a href="#">2012</a><ul>
					<?php getNews(2012); ?></ul></li>
				<li><a href="#">2011</a><ul>
					<?php getNews(2011); ?></ul></li>
				<li><a href="#">2010</a><ul>
					<?php getNews(2010); ?></ul></li>
				<li><a href="#">2009</a><ul>
					<?php getNews(2009); ?></ul></li>
				<li><a href="#">2008</a><ul>
					<?php getNews(2008); ?></ul></li>
				<li><a href="#">2007</a><ul>
					<?php getNews(2007); ?></ul></li>
				<li><a href="#">2006</a><ul>
					<?php getNews(2006); ?></ul></li>
				<li><a href="#">2005</a><ul>
					<?php getNews(2005); ?></ul></li>
			</ul>
			<?php
				function getNews($year) {
					$query = mysql_query("SELECT * FROM newsfeed WHERE date_format(added, '%Y')=$year AND status='Active' ORDER BY added DESC") or die("This webpage is not available. ".mysql_error());
					if($query)
					{
						if(mysql_num_rows($query) != 0)
						{
							while($rows = mysql_fetch_array($query))
							{
								//echo '<li><a href="news_post.php?article='.urlencode(htmlspecialchars($rows['subject'])).'">'.implode(" ", array_slice(explode(" ", $rows['subject']), 0, 10)).'...</a></li>';
								echo '<li><a href="news_post.php?article='.urlencode(htmlspecialchars($rows['subject'])).'">'.$rows['subject'].'...</a></li>';
							}
						}
						else
						{
							echo '<li>No news item available</li>';
						}
					}
				}
			?>                
        </div>
	</div>	
	<div class="css-block clearfix">
        <div class="css-blockheader"><h3 class="t">Feedback</h3></div>
        <div class="css-blockcontent">
			<form name="" class="" method="POST" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" enctype="multipart/form-data">
				<p>Your Name:<input type="text" id="name" name="name" autocomplete="off" /><br /></p>
				<p>Your Email:<input type="email" id="email" name="email" autocomplete="off" /><br /></p>
				<p>Subject:
					<select name="subject">
						<option selected="selected"></option>
						<option value="Comment/Suggestion">Comment/Suggestion</option>
						<option value="Inquiry">Inquiry</option>
					</select>
				</p>
				<p>Your Message:<textarea name="message"></textarea></p>
				<br />
				<p style="text-align:right;"><input type="submit" id="submit" name="submit" class="css-button" value="Send" /></p>
				<?php
					include("conn.php");
					error_reporting(E_ALL ^ E_NOTICE ^ E_WARNING);

					if($_POST['submit'])
					{
						$name = mysql_real_escape_string(ucfirst(trim($_POST['name'])));
						$email = mysql_real_escape_string(trim($_POST['email']));
						$subj = mysql_real_escape_string(trim($_POST['subject']));
						$msg = mysql_real_escape_string(trim($_POST['message']));

						if(!isset($name) && !isset($email) && !isset($subj) && !isset($msg))
						{
							echo '<script language="javascript">';
								echo 'alert("Please fill out all the fields.");';
							echo '</script>';
						}
						else
							$query = mysql_query("INSERT INTO feedback(name, email, subj, msg) VALUES('".$name."','".$email."','".$subj."','".$msg."') ") or die("Trouble in sending data. ".mysql_error());
					}
				?>
			</form>
		</div>
	</div>	
</div>