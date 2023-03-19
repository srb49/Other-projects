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
		
		$c=0;
		
	if($_REQUEST['qr']=='q1')
		{
		$sql ="select max(no_iss) as maxiss from book ";
		$result=mysqli_query($conn,$sql);
		$row = mysqli_fetch_assoc($result);
		$l=$row["maxiss"];
		
		
		$sql ="select *from book where no_iss='".$l."'";
		$result=mysqli_query($conn,$sql);
		$row = mysqli_fetch_assoc($result);
		
		$nm=$row["b_name"];
		$au=$row["author"];
		$pb=$row["publisher"];
		echo "<br>name of the book ".$nm;
		echo "<br>author of the book ".$au;
		echo "<br>the book has been issued ".$l."times";
		
		
		$sql="select count(s_id) as tot from student";
		$result=mysqli_query($conn,$sql);
		$row = mysqli_fetch_assoc($result);
		$total1=$row["tot"];
		echo "<br>total number of students ".$total1;
		
		
		$sql="select count(f_id) as tot from faculty";
		$result=mysqli_query($conn,$sql);
		$row = mysqli_fetch_assoc($result);
		$total2=$row["tot"];
		echo "<br>total number of faculty ".$total2;
		
		$sql="select count(b_id) as tot from book where b_name='".$nm."' and author='".$au."' and publisher='".$pb."'";
		$result=mysqli_query($conn,$sql);
		$row = mysqli_fetch_assoc($result);
		$total3=$row["tot"];
		echo "<br>total number of book ".$total3;
		
		if($total3<=($total1+$total2))
			echo "<br><br>So the number of copies of the book is limited. More copies can be brought in the library";
		else if($total3>($total1+$total2))
			echo "<br><br>So the number of copies of the book is enough";
		}
	else if($_REQUEST['qr']=='q2')
	{
		header('Location: month.php');
	}
	else if($_REQUEST['qr']=='q3')
	{
		$sql="select s_id,fine from student where fine>0";
		$result=mysqli_query($conn,$sql);
		
		echo "<table border='2' width='20%' align='center'><tr><th>STUDENT ID</th><th>FINE</th></tr>";
		while($row = mysqli_fetch_assoc($result)) 
		{
			echo "<tr align='center'><td>".$row["s_id"]."</td><td>".$row["fine"]." </td></tr>";
		}
		echo "</table>";
	}
	
}
else 
{
?>	
<h1 align="center">QUERY PAGE FOR REPORT OF LIBRARY MANAGEMENT SYSTEM</h1>
<hr></hr>
<form action="query.php" method="post" align="center">
<br><br><br>
<select name="qr">

  <option value="q1">name of the book which has been issued maximum time</option>
  <option value="q2">number of issue in different month</option>
  <option value="q3">name of the students didn't pay the fine yet</option>	
  </select>
<input type="submit" name="sb" value="search">
</form>
<?php
}
?>

</body>
</html>