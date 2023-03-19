<html>
	<head><title>DATABASE log in</title></head>
	<body>
	<?php
	if($_REQUEST)
	{
		//$f_id= $_REQUEST['fid'];
		//$pass= $_REQUEST['pass'];
		$bname=$_REQUEST['srch'];
		
		$host="localhost"; 
		$user="root";
		$password="";
		$database="library";
		
		
		$conn=mysqli_connect($host, $user, $password, $database);
		
		if(!$conn)
			die("Connection failed: " . mysqli_connect_error());
			
		$sql="select *from book where b_name='".$bname."' and availability='yes'";
		$result=mysqli_query($conn,$sql);
		$r=mysqli_num_rows($result);
		echo "number of book(s) available: ".$r;
		
		$sql="select *from book where b_name='".$bname."'";
		$result=mysqli_query($conn,$sql);
		if(mysqli_num_rows($result)>0)
		{
			echo "<table border='2' width='100%'><tr><th>ID</th><th>Name</th><th>Publisher</th><th>Author</th><th>Availability</th></tr>";
			// output data of each row
		while($row = mysqli_fetch_assoc($result)) 
		{
			if($row["availability"]=='yes')
			echo "<tr><td>".$row["b_id"]."</td><td>".$row["b_name"]." </td><td>".$row["publisher"]."</td><td>".$row["author"]."</td><td>".$row["availability"]."</td></tr>";
		}
		echo "</table>";
		} 
	else 
	{
    echo "0 results";
	}
		
	}
	else{
	?>
	<h1>searching book</h1>
	<form action="std_bk.php" method="post">
	<!--for searching books -->
	enter:<input type="text" name="srch" /><br/>
	<input type="submit" value="search books"/>
	
	</form>
<?php
	}
?>
</body>
</html>