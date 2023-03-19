<html>
<head></head>
<body>

<?php
if($_REQUEST)
{
	
		$host="localhost"; 
		$user="root";
		$password="";
		$database="rest";
		
		
		$conn=mysqli_connect($host, $user, $password, $database);
		
		if(!$conn)
			die("Connection failed: " . mysqli_connect_error());
		
		$c=0;
		
	if($_REQUEST['qr']=='q1')
		{
			header('Location: bill_mon.php');
		}
	else if($_REQUEST['qr']=='q2')
	{
		
		//$sql ="select no_or from menu limit 2";
		$sql="SELECT no_or,m_name FROM menu ORDER BY no_or DESC LIMIT 4";
		$result=mysqli_query($conn,$sql);
		//$row = mysqli_fetch_assoc($result);
		echo "<table border='2' width='20%' align='center'><tr><th colspan='2'>TOP 4 MOST PREFERRED DISHES</th></tr>";
		while($row = mysqli_fetch_assoc($result)) 
		echo "<tr><td>".$row["m_name"]."</td><td>".$row["no_or"]." </td></tr>";
		echo "</table>";
	}
		
}
else 
{
?>	
<h1 align="center">QUERY PAGE FOR REPORT OF ONLINE RESTAURANT MANAGEMENT SYSTEM</h1>
<hr></hr>
<form action="query1.php" method="post" align="center">
<br><br><br>
<select name="qr">

  <option value="q1">BILL OF A PARTICULAR MONTH</option>
  <option value="q2">most preffered 4 dishes in the record</option>
  
  </select>
<input type="submit" name="sb" value="search">
</form>
<?php
}
?>

</body>
</html>