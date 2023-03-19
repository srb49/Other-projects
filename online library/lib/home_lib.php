<html>
	<head><title>DATABASE log in</title></head>
	<body>
	<?php
	if($_REQUEST)
	{
		$lid= $_REQUEST['lid'];
		$pass= $_REQUEST['pass'];
		
		$host="localhost"; 
		$user="root";
		$password="";
		$database="library";
		
		
		$conn=mysqli_connect($host, $user, $password, $database);
		
		if(!$conn)
			die("Connection failed: " . mysqli_connect_error());
		
		$sql1 ="select *from librarian where lid='".$lid."'";
		$sql2 ="select *from librarian where pass='".$pass."'";
		//echo $sql;
		//echo "<br>";
		
		$result1=mysqli_query($conn,$sql1);
		$r1=mysqli_num_rows($result1);
		
		$result2=mysqli_query($conn,$sql2);
		$r2=mysqli_num_rows($result2);
		
		if($r1 && $r2)
		{
			echo "log in successful";//give an hiper link to student account page where they can 1.modify account 2.search books
			header('Location: lib_sel.php');    
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
	<h1>librarian log in Form</h1>
	<h3>A LIBRAIN CAN RECORD THE ISSUE AND REISSUE AND RETURN IN THE DATABASE</h3>
	<form action="home_lib.php" method="post">
	lid<input type="text" name="lid" /><br/>
	Password:<input type="text" name="pass" /><br/>
	
	<input type="submit" value="Enroll"/>
	</form>
<?php
	}
?>
</body>
</html>