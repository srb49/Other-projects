<html>
	<head><title>DATABASE:sign up</title></head>
	<body>
	<?php
	if($_REQUEST)
	{
		$s_id= $_REQUEST['sid'];
		$pass= $_REQUEST['pass'];
		$reg_no= $_REQUEST['rno'];
	
	
		$host="localhost"; 
		$user="root";
		$password="";
		$database="library";
		
		
		$conn=mysqli_connect($host, $user, $password, $database);
		
		if(!$conn)
			die("Connection failed: " . mysqli_connect_error());
        
	$s=substr($s_id,0,1);
	//echo $s;
	if($s=='s')	
	{
		
		//echo $sql;
		echo "<br>";
		
		$sql1="select *from student where reg_no='".$reg_no."'";
		$sql2="select *from student where s_id='".$s_id."'";
		
		$result1=mysqli_query($conn,$sql1);
		$r1=mysqli_num_rows($result1);
		
		$result2=mysqli_query($conn,$sql2);
		$r2=mysqli_num_rows($result2);
		
		if($r1>0)
		{
			echo "please sign up with a single id";
		}
		elseif($r2>0)
		{
			echo "please sign up with a different id(same id is already there)";
		}
		else
		{
			$sql ="insert into student (s_id,reg_no,pass) VALUES ('".$s_id."','".$reg_no."','".$pass."')";
			$flag=mysqli_query($conn, $sql);
			if(!$flag)
			die("Query failed: " . mysqli_error($conn));
			else
				echo "your account is successfully created";
		}
	}
	else
		echo "student id should start with s";
}
	else{
	?>
	<h1>Student sign up Form</h1>
	<form action="std_sign.php" method="post">
	sid<input type="text" name="sid" />student id should start with s<br/>
	reg no:<input type="text" name="rno" /><br/>
	Password:<input type="text" name="pass" /><br/>
	
	<input type="submit" value="Enroll"/>
	</form>
<?php
	}
?>
</body>
</html>