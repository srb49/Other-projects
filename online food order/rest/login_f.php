<html>
	<head>
	
	</head>
	<body>
	<?php
	session_start();
	if($_REQUEST)
	{
		
		
		$host="localhost";
		$user="root";
		$password="";
		$database="rest";
		$conn=mysqli_connect($host, $user, $password, $database);
		
		
		$name=$_REQUEST['name'];
		$ph=$_REQUEST['pno'];
		
		if(!$conn)
			die("Connection failed: " . mysqli_connect_error());
		//if already registered then only give cid
	
		if($_REQUEST['name']&&$_REQUEST['pno'])
		{
			
			$sql="select *from customer where c_name='".$name."' and c_ph='".$ph."'";
			$result=mysqli_query($conn,$sql);
			$r=mysqli_num_rows($result);
			if($r)//this if-else is for checking the id already exists or not
			{
				
				$row = mysqli_fetch_assoc($result);
				$_SESSION['id'] = $row["c_id"];

				header('Location: p_of.php');
			}
			else
			{
				$sql="insert into customer (c_name,c_ph) VALUES ('".$name."','".$ph."')";
				mysqli_query($conn,$sql);
				$sql="select *from customer where c_name='".$name."' and c_ph='".$ph."'";
				$result=mysqli_query($conn,$sql);
				$row = mysqli_fetch_assoc($result);
				$cid=$row["c_id"];
				
				$_SESSION['id'] = $cid;
				header('Location:p_of.php');
				
			}
		}
		else
			echo "Please fill up all the necessary field!!! ";
    }
	else{
	?>
	<h1 align="center"><b><u>-----OFFLINE ORDER DETAILS-----</u></b></h1>
	<form  method="post" action="login_f.php" align="left">
	<div>
	
	Name:<input type="text" name="name"/><br/><br>
	Phone number<input type="text" name="pno" /><br/><br>
	</div>
	<input type="submit" value="Enter"/>
	
<?php
	}
?>	
	</body>
</html>