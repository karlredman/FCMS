<?

	/////////////////////////// CONNECT TO DB
	$db_name="mycms";
	$access_user="root";
	$access_password="eertwfld";
	$access_host="";
	$host_id=1;
//	$site_id=1;
	
//IMPORTED:	$id


	//connect 
	$db=mysql_connect("$access_host", "$access_user", "$access_password")
	or exit;
	   

	//and select the database
	mysql_select_db($db_name, $db)
	or exit;

	//get home page header info
	$current_page=mysql_query(
	"select * from page where page_id = $id;"
	,$db) or exit;


	if($cur_page_obj = mysql_fetch_object($current_page))
	{

echo("
<form action=page-edit.php method=post>
<font face=arial,helvetica>
Editing <font color=#ff0000><b>$cur_page_obj->page_title</b></font><br>
<font size=2>Enter Password: 
<input type=password name=entered_password 
size=8 maxlength=8></font>
<input type=hidden name=id value=$id>
<input type=hidden name=page_filename value=>
<input type=submit value=go>
</font>
</form>
");
}

	//mysql_free
?>


