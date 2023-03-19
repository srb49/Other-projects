<html>
	<head><title>DATABASE log in</title></head>
	<body>
	<?php
	if($_REQUEST)
	{
		$s_id= $_REQUEST['sid'];
		$pass= $_REQUEST['pass'];
		
		$host="localhost"; 
		$user="root";
		$password="";
		$database="library";
		
		
		$conn=mysqli_connect($host, $user, $password, $database);
		
		if(!$conn)
			die("Connection failed: " . mysqli_connect_error());
		$table="student";
		$sql1 ="select *from student where s_id='".$s_id."'";
		$sql2 ="select *from student where pass='".$pass."'";
		//echo $sql;
		//echo "<br>";
		
		$result1=mysqli_query($conn,$sql1);
		$r1=mysqli_num_rows($result1);
		
		$result2=mysqli_query($conn,$sql2);
		$r2=mysqli_num_rows($result2);
		
		if($r1 && $r2)
		{
			//echo "log in successful";//give an hiper link to student account page where they can 1.modify account 2.search books
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
	<h1>Student log in Form</h1>
	<form action="std_log.php" method="post">
	sid<input type="text" name="sid" /><br/>
	Password:<input type="text" name="pass" /><br/>
	
	<input type="submit" value="Enroll"/>
	</form>
<?php
	}
?>
</body>
</html>