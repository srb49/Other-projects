<html>
	<head><title>librarian</title></head>
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
	
	$bid=$_REQUEST['bid'];
	$uid=$_REQUEST['uid'];
	$tp=substr($uid,0,1);
	$date=$_REQUEST['dt'];
	//echo $tp;
	//echo $date;
	
  if($tp=='s')
  {	
	if($_REQUEST['sb']=="ISSUE")
	{
		
		$date1=$date;
		//echo $date1."<br>";
		$date2=date('Y-m-d', strtotime($date. ' + 15 days'));
		//echo $date2;
		
		$sql="select *from student where s_id='".$uid."'";
		$flag=mysqli_query($conn, $sql);
		$row = mysqli_fetch_assoc($flag);
		if($row["n_bk"]<3)//this if else is for checking limitation of number of books(that is 3)
		{
		
		$sql="select *from book where b_id='".$bid."' and availability='yes'";
		$flag=mysqli_query($conn, $sql);
		$r1=mysqli_num_rows($flag);
		if($r1)//this if else is for checking if the requested book is available
		{	
		$sql="update book set availability='no' where b_id='".$bid."'";
		$flag=mysqli_query($conn, $sql);
		echo "issue is successful";
		$sql="insert into borrow (uid,type,bid,d_br,d_ret,status) values ('".$uid."','".$tp."','".$bid."','".$date1."','".$date2."','issued')";
		$f=mysqli_query($conn,$sql);
		$sql="update student set n_bk = n_bk + 1 where s_id='".$uid."'";
		mysqli_query($conn,$sql);
		
		$sql="update book set no_iss = no_iss + 1 where b_id='".$bid."'";
		mysqli_query($conn,$sql);
		}
		else
			echo "this book can't be issued";
			
		}
		else
			echo "you can not issue more books";
	}
	
	elseif($_REQUEST['sb']=="REISSUE")
	{
				
		$date1=$date;
		echo $date1."<br>";
		$date2=date('Y-m-d', strtotime($date. ' + 15 days'));
		echo $date1."<br>";
		echo $date2;
		$sql="update borrow set d_br='".$date1."',d_ret='".$date2."' where bid='".$bid."' and status='issued'";
		//echo $sql."<br>";
		mysqli_query($conn,$sql);	
	}
	elseif($_REQUEST['sb']=="RETURN")
	{
	
		$sql="select *from borrow where bid='".$bid."' and status='issued'";
		$flag=mysqli_query($conn, $sql);
		$row = mysqli_fetch_assoc($flag);
		$d2=$row["d_ret"];
		$brid=$row["br_id"];
		
		$diff = strtotime($d2) - strtotime($date);
		//echo $diff;
		if($diff<=0)
		{
		$days = abs(floor($diff/(60*60*24)));
		//echo "<br>".$days;
		}
		else
			$days=0;
		$sql="update book set availability='yes'";
		mysqli_query($conn,$sql);	
		echo "<br>".$days;
		echo "<br>your payable fine is ".$days;
		
		$sql="update student set fine= fine + '".$days."',n_bk = n_bk - 1 where s_id='".$uid."'";
		mysqli_query($conn,$sql);	
		
		$sql="update borrow set status='returned',return_d='".$date."',fine='".$days."' where br_id='".$brid."'";
		mysqli_query($conn,$sql);	
		
		
	}
	elseif($_REQUEST['sb']=="FINE")
	{
			
		$sql="update borrow set fine='0' where bid='".$bid."' and uid='".$uid."' and fine > 0";
		mysqli_query($conn,$sql);	
		
		$sql="update student set fine='0' where s_id='".$uid."'";
		mysqli_query($conn,$sql);	
		
	}
  }
  else
	  echo "wrong log in page";
}
	else
	{
	?>
	<h1 align="center">LIBRARIAN</h1>
	<form  method="post" action="lib_iss_s.php" align="center">
	enter the book id<input type="text" name="bid"><br><br>
	enter the student id<input type="text" name="uid"><br><br>
	<input type="date" name="dt">
	<input type="submit" name="sb" Value="ISSUE">
	<input type="submit" name="sb" Value="REISSUE">
	<input type="submit" name="sb" Value="RETURN">
	<input type="submit" name="sb" Value="FINE"><BR><BR>
	<h4 align='center'>ISSUE IS FOR ISSUEING THE BOOK</h4><BR>
	<h4 align='center'>REISSUE IS FOR REISSUEING THE BOOK</h4><BR>
	<h4 align='center'>RETURN IS FOR RETURNING THE BOOK</h4><BR>
	<h4 align='center'>FINE IS FOR MODIFING THE DATABASE(SET FINE=0) WHEN THE USER SHOWS THE FINE SLIP TO THE LIBRARIAN</h4><BR>
	
	</form>
	<?php
	}
	?>
</body>
</html>