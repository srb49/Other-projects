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
		
		$m=$_REQUEST['mn'];
		$y=$_REQUEST['yr'];
		//echo $m;
		$tot=0;
		$mon = array("JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC");
		
		$sql="select sum(bill) as tbill1 from on_order where month(or_dt)='".$m."' and year(or_dt)='".$y."'";
		$result1=mysqli_query($conn,$sql);
		$sql="select sum(bill)  as tbill2 from of_order where month(or_dt)='".$m."' and year(or_dt)='".$y."'";
		$result2=mysqli_query($conn,$sql);
		
		echo "<table border='2' width='20%' align='center'><tr><th colspan='2'>REVENUW OF ".$mon[$m-1]."  ".$y."</th></tr>";
		if(mysqli_num_rows($result1)>0)
		{
			$row = mysqli_fetch_assoc($result1);
		echo "<tr><td>ONLINE ORDER</td><td>".$row["tbill1"]." </td></tr>";
		$tot=$tot+$row["tbill1"];
		}
		else
		echo "<tr><td>ONLINE ORDER</td><td>0</td></tr>";
		if(mysqli_num_rows($result2)>0)
		{
			$row = mysqli_fetch_assoc($result2);
			echo "<tr><td>OFFLINE ORDER</td><td>".$row["tbill2"]." </td></tr>";
			$tot=$tot+$row["tbill2"];
		}
		else
		echo "<tr><td>OFFLINE ORDER</td><td>0</td></tr>";	
		
		echo "<tr><td>TOTAL</td><td>".$tot."</td></tr>";
		
		
		echo "</table>";
		
}
else 
{
?>	
<h1 align="center">BILL OF A PARTICULAR MONTH</h1>
<hr></hr>
<form action="bill_mon.php" method="post" align="center">
<br><br><br>
SELECT THE MONTH
<select name="mn">

  <option value="1">JAN</option>
  <option value="2">FEB</option>
   <option value="3">MAR</option>
   <option value="4">APR</option>
   <option value="5">MAY</option>
   <option value="6">JUN</option> 
    <option value="7">JUL</option>
  <option value="8">AUG</option>
   <option value="9">SEP</option> 
    <option value="10">OCT</option>
    <option value="11">NOV</option>
    <option value="12">DEC</option>
 
 </select><BR><BR>

SELECT THE YEAR 
<select name="yr">

  <option value="2016">2016</option>
  <option value="2017">2017</option>

 </select>

<input type="submit" name="sb" value="search">
<br><br>the records are available from November 2016 to January 2017
</form>
<?php
}
?>

</body>
</html>