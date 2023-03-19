<html>
	<head><title>DATABASE log in</title></head>
	<body>
	<?php
	if($_REQUEST)
	{
		$f_id= $_REQUEST['fid'];
		$pass= $_REQUEST['pass'];
		
		$host="localhost"; 
		$user="root";
		$password="";
		$database="library";
		
		
		$conn=mysqli_connect($host, $user, $password, $database);
		
		if(!$conn)
			die("Connection failed: " . mysqli_connect_error());
		$table="faculty";
		$sql1 ="select *from faculty where f_id='".$f_id."'";
		$sql2 ="select *from faculty where pass='".$pass."'";
		//echo $sql;
		//echo "<br>";
		
		$result1=mysqli_query($conn,$sql1);
		$r1=mysqli_num_rows($result1);
		
		$result2=mysqli_query($conn,$sql2);
		$r2=mysqli_num_rows($result2);
		
		if($r1 && $r2)
		{
			//give an hiper link to student account page where they can 1.modify account 2.search books
			header('Location: std_bk.php');
		}
			
		elseif($r1==0 && $r2)
		{
			echo "please sign up. this id does not exist";
		}
		elseif($r2==0&&$r1)
		{
			echo "wrong password";
		}
		else
			echo "wrong id and password";
		}
	else{
	?>
	<h1>faculty log in Form</h1>
	<form action="fcl_log.php" method="post">
	fid<input type="text" name="fid" /><br/>
	Password:<input type="text" name="pass" /><br/>
	<input type="submit" value="Enroll"/>
	</form>
<?php
	}
?>
</body>
</html>