<html>
<head></head>
<body>

<?php
if($_REQUEST)
{
	
		$host="localhost"; 
		$user="root";
		$password="";
		$database="library";
		
		
		$conn=mysqli_connect($host, $user, $password, $database);
		
		if(!$conn)
			die("Connection failed: " . mysqli_connect_error());
		
		$mon = array("JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC");
		
		
		$date1=$_REQUEST['dt1'];
		$date2=$_REQUEST['dt2'];
		
		
		$diff=strtotime($date2) - strtotime($date1);
		$m=floor($diff/(60*60*24*30));
		
		if($diff>=0)
		{
		$m1=substr($date1,5,2);
		$m1=(int)$m1;
		$y1=substr($date1,0,4);
		$y1=(int)$y1;
		
		$m2=substr($date2,5,2);
		$m2=(int)$m2;
		$y2=substr($date2,0,4);
		$y2=(int)$y2;
		
		echo "<table align='center' border='2' width='20%'><tr><th>MONTH</th><th>YEAR</th><th>NUMBER OF ISSUE</th></tr>";
		for($i=1;$i<=$m;$i++)
		{
				if($m1==13)
				{
					$m1=1;
					$y1=$y2;
				}
				$sql="select count(br_id) as cnt from borrow where month(d_br)='".$m1."'";
				$result=mysqli_query($conn,$sql);
				$row = mysqli_fetch_assoc($result);
				echo "<tr align='center'><td>".$mon[$m1-1]."</td><td>".$y1." </td><td>".$row["cnt"]." </td></tr>";
				$m1=$m1+1;
				
		}
		echo "</table>";
		}
		else
			echo "please insert the dates accordingly";
		
		
		
}
else 
{
?>	
<h1 align="center">NUMBER OF ISSUES OF BOOKS IN DIFFERENT MONTH</h1>
<hr></hr>
<form action="month.php" method="post" align="center">
<br><br><br>
starting date:<input type="date" name="dt1"><br><br>
ending date:<input type="date" name="dt2"><BR><BR>
<input type="submit" name="sb" value="search">
<br><br>the records are kept from August 2016 to January 2017
</form>
<?php
}
?>

</body>
</html>