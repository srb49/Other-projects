<html>
	<head>
	
	</head>
	<body>
	
	<?php
	session_start();
	if($_REQUEST)
	{
		$sm=0;
		$sm1=0;
		$f=0;
		
		$host="localhost";
		$user="root";
		$password="";
		$database="rest";
		$conn=mysqli_connect($host, $user, $password, $database);
		
		if(!$conn)
			die("Connection failed: " . mysqli_connect_error());
		
		if(!empty($_POST['ch']))
		{
		
			foreach($_POST['ch'] as $s)
			{
				$sql="select *from menu where m_name='".$s."'";
				$result=mysqli_query($conn,$sql);
				$row = mysqli_fetch_assoc($result);
				$sm=$sm+$row["cost"];
				
				$sql="update menu set no_or=no_or+1 where m_name='".$s."'";
				mysqli_query($conn,$sql);
			}
		}
		//On page 2
		$cid = $_SESSION['id'];
		
	
			$sql="select *from customer where c_id='".$cid."'";
			$result=mysqli_query($conn,$sql);
			$row = mysqli_fetch_assoc($result);
		
				if($row["n_or"]==30)//this is for checking premium customer
				{
					echo "premium customer<br>";
					echo "oreder cost is Rs: ".$sm;
					
					$sm1=$sm*0.1;
					echo "<br> discount is Rs: ".$sm1;
					$sm=$sm-$sm1;
					echo "<br>total order price is".$sm;
					//updating customer table with number of order is 0
					$sql="update customer set n_or='0' where c_id='".$cid."'";
					mysqli_query($conn,$sql);
				}
				else
				{
					echo " oreder cost is Rs: ".$sm;
					
					echo "<br>total order price is".$sm;
					$sql="update customer set n_or= n_or + 1 where c_id='".$cid."'";
					mysqli_query($conn,$sql);
				}
				//update the on_order table
				$sql="insert into of_order (cid,bill) VALUES ('".$cid."','".$sm."')";
				mysqli_query($conn,$sql);
		}
		
	else{
	?>
	<h1 align="center"><b><u>-----SELECT ITEM-----</u></b></h1>	
	<form  method="post" action="p_of.php" align="CENTER">
	
	<table align="center" style="width:60%" border="5">
  <tr>
    <th>Food</th>
    <th>Beverage</th> 
  </tr>
  <tr>
    <td align="left">
	<ul>
	<li><input type="checkbox" name="ch[]" value="f1">f1(100)</li>
	<li><input type="checkbox" name="ch[]" value="f2">f2(200)</li>
	<li><input type="checkbox" name="ch[]" value="f3">f3(300)</li>
	<li><input type="checkbox" name="ch[]" value="f4">f4(350)</li>
	<li><input type="checkbox" name="ch[]" value="f5">f5(150)</li>
	</ul>
	</td>
	<td align="left">
    <ul>
	<li><input type="checkbox" name="ch[]" value="b1">b1(100)</li>
	<li><input type="checkbox" name="ch[]" value="b2">b2(75)</li>
	<li><input type="checkbox" name="ch[]" value="b3">b3(95)</li>
	<li><input type="checkbox" name="ch[]" value="b4">b4(150)</li>
	</ul>	
	</td> 
    
  </tr>
 
</table>

	<br><br><input type="submit" name="submit" value="PLACE ORDER" align="center"/>

<?php
	}
?>	
	</body>
</html>