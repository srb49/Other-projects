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
		
		$cid=$_REQUEST['cid'];
		$name=$_REQUEST['name'];
		$ph=$_REQUEST['pno'];
		$add=$_REQUEST['add'];
		$pn=$_REQUEST['pn'];
		if(!$conn)
			die("Connection failed: " . mysqli_connect_error());
		//if already registered then only give cid
		if($_REQUEST['cid'])
		{
			$sql="select *from customer where c_id='".$cid."' ";
			$result=mysqli_query($conn,$sql);
			$row = mysqli_fetch_assoc($result);
			//if address is null fill up means if customer has ordered offline,so he/she don't have address in the database
			if($row["c_ad"]==NULL||$row["c_pin"]==NULL)
				echo "please enter your address and pin code";
			else
			{
				//On page 1
				$_SESSION['id'] = $cid;
				$_SESSION['ar'] = $row["c_pin"];

				header('Location: p_o.php');
			}
		}
		elseif($_REQUEST['name']&&$_REQUEST['pno']&&$_REQUEST['add']&&$_REQUEST['pn'])
		{
			$sql="select *from d_boy where a_code='".$pn."'";
			$result=mysqli_query($conn,$sql);
			$r=mysqli_num_rows($result);
			if($r)
			{
			$sql="select *from customer where c_name='".$name."' and c_ph='".$ph."'";
			$result=mysqli_query($conn,$sql);
			$r=mysqli_num_rows($result);
			if($r)
			{
				$sql="update customer set c_ad='".$add."' and c_pin='".$pn."'";
				
				$_SESSION['id'] = $cid;
				$_SESSION['ar'] = $pn;

				header('Location: p_o.php');
			}
			else
			{
				$sql="insert into customer (c_name,c_ph,c_ad,c_pin) VALUES ('".$name."','".$ph."','".$add."','".$pn."')";
				mysqli_query($conn,$sql);
				$sql="select *from customer where c_name='".$name."' and c_ph='".$ph."'";
				$result=mysqli_query($conn,$sql);
				$row = mysqli_fetch_assoc($result);
				$cid=$row["c_id"];
				
				$_SESSION['id'] = $cid;
				$_SESSION['ar'] = $pn;
				header('Location:p_o.php');
				
			}
			}
			else
				echo "sorry your area is not covered by us!";
		}
		else
			echo "please enter all the field(non-optional)";
    }
	else{
	?>
	<h1 align="center"><b><u>-----ORDER DETAILS-----</u></b></h1>
	<h3>if you have ordered online before(not more than one year ago) only enter your cid</h3>
	<form  method="post" action="login_c.php" align="left">
	<div>
	Cid:(optional)<input type="text" name="cid"/><br/><br>
	Name:<input type="text" name="name"/><br/><br>
	Phone number<input type="text" name="pno" /><br/><br>
	address(without pin)<br><textarea name="add" rows="5" cols="40"></textarea><br><br>
	pincode:<input type="text" name="pn" /><br/><br>
	</div>
	<input type="submit" value="Enter"/>
	
<?php
	}
?>	
	</body>
</html>