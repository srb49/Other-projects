<form action="#" method="post">
<input type="checkbox" name="check_list[]" value="C/C++"><label>C/C++</label><br/>
<input type="checkbox" name="check_list[]" value="Java"><label>Java</label><br/>
<input type="checkbox" name="check_list[]" value="PHP"><label>PHP</label><br/>
<input type="submit" name="submit" value="Submit"/>
</form>
<?php
if(isset($_POST['submit'])){//to run PHP script on submit
if(!empty($_POST['check_list'])){
// Loop to store and display values of individual checked checkbox.
foreach($_POST['check_list'] as $selected){
echo $selected."</br>";
}
}
}
//date_default_timezone_set("Asia/India");
//echo "The time is " . date("h:i:sa");

//echo date("h:i:sa")."<br>";
//echo date("Y/m/d") ;

//print_r(localtime());
//echo "<br><br>";
//print_r(localtime(time(),true));


	$D = exec('date /T');
  $T = exec('time /T');
  echo $D;
  echo $T;
  $s=substr($T,0,2);
  echo $s;
  //$DT = strtotime(str_replace("/","-",$D." ".$T));
  //echo(date("Y-m-d H:i:s",$DT));
	//echo CURDATE();
  
  ?>


