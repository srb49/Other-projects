<html>
	<head><title>DATABASE:sign up</title></head>
	<body>
	<?php
	if($_REQUEST)
	{
		$f_id= $_REQUEST['fid'];
		$pass= $_REQUEST['pass'];
		$reg_no= $_REQUEST['rno'];
		
		$host="localhost"; 
		$user="root";
		$password="";
		$database="library";
		
		
		$conn=mysqli_connect($host, $user, $password, $database);
		
		if(!$conn)
			die("Connection failed: " . mysqli_connect_error());
		
		//echo $sql;
		echo "<br>";
		$f=substr($f_id,0,1);
	//echo $f;
	if($f=='f')
	{
		$sql1="select *from faculty where reg_no='".$reg_no."'";
		$sql2="select *from faculty where f_id='".$f_id."'";
		
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
			$sql ="insert into faculty (f_id,reg_no,pass) VALUES ('".$f_id."','".$reg_no."','".$pass."')";
			$flag=mysqli_query($conn, $sql);
			if(!$flag)
			die("Query failed: " . mysqli_error($conn));
			else
				echo "your account is successfully created";
		}
		
	}
	else
		echo "faculty id should start with f";
}
else{
	?>
	<h1>faculty sign up Form</h1>
	<form action="fcl_sign.php" method="post">
	fid<input type="text" name="fid" />faculty id should start with f<br/>
	reg no:<input type="text" name="rno" /><br/>
	Password:<input type="text" name="pass" /><br/>
	
	<input type="submit" value="Enroll"/>
	</form>
<?php
	}
?>
</body>
</html>