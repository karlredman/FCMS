<?
//page-edit.php
?>

<?
/*

EDIT_PAGE

NOTE:
	to be included from something with variables:
	$access_host
	$access_user
	$access_password
	$db_name
	$host_id
	$site_id

REUSED VARIABLES:
	$id
*/
?>


<?
$debug=0;

$db_name="mycms";
$access_user="root";
$access_password="eertwfld";

$host_id=1;
$site_id=1;

	echo("<HTML>");
	echo("<HEAD>");


	/////////////////////////// CONNECT TO DB

	//connect 
	$db=mysql_connect("$access_host", "$access_user", "$access_password")
	or exit;

	//and select the database
	mysql_select_db($db_name, $db)
	or exit;


	/////////////////////////// GET HOME PAGE:

	//get home page
        $site=mysql_query(
		"select * from site where site_id = $site_id"
		,$db);

	$site_obj=mysql_fetch_object($site);


	//get home page header info
	$current_page=mysql_query(
	"select * from page where page_id = $id;"
	,$db) or exit;


///////////////////////////// DISPLAY
	//display stuff
	if($cur_page_obj = mysql_fetch_object($current_page))
	{
		echo("<TITLE>$cur_page_obj->page_title</TITLE>");
		//echo("<META>
		echo("</HEAD>");


		echo("<BODY>");
		//echo("<BODY bg=000000 fg=ffffff

	  //////////////////// editing buttons
	  echo("       
		<form    action=content-edit.php
        	method=post>
		<input  type=hidden
		        name=id
			value=$cur_page_obj->page_id>
		<input type=hidden
			name=content_ref
			value=$content_obj->content_id>
		<input  type=image
		        src=images/edit.gif>
		</form>      
	");

		if($cur_page_obj->title_align == "center")
		  echo("<center>");

		
		echo("<font size=+$cur_page_obj->title_font_size 
			face=$cur_page_obj->title_font_face>
			$cur_page_obj->page_title
			</font>");

		if($cur_page_obj->title_align == "center")
		  echo("</center>");

		echo("<hr>");

////////////

		if($debug)
		  {
		  echo("
		<center>
		<br>
		PAGE DATA:
		
		<br>
		id=$cur_page_obj->page_id
		<br>
		type=$cur_page_obj->type
		<br>
		page_title=$cur_page_obj->page_title
		<br>
		last_updated=$cur_page_obj->last_updated
		<br>
		email_contact=$cur_page_obj->email_contact
		<br>
		telephone_contact=$cur_page_obj->telephone_contact
		<br>
		code=$cur_page_obj->code
	
		<br>
		</center>
		<br>
		<br>
		<br>
		<br>
		<br>
		<br>
		");
		  }
	}
	else
	exit;


///////////////////////////////// DISPLAY CONTENT

	//get page content items in order of ref_id;
        $content=mysql_query(
	"select * from content where page_id = $cur_page_obj->page_id order by ref_id;"
	,$db) or exit;

	//display content items

	while($content_obj = mysql_fetch_object($content))
	{
	  //print title
	  echo("<p>");

	  //////////////////// editing buttons
	  echo("       
		<form    action=content-edit.php
        	method=post>
		<input  type=hidden
		        name=id
			value=$cur_page_obj->page_id>
		<input type=hidden
			name=content_ref
			value=$content_obj->content_id>
		<input  type=image
		        src=images/edit.gif>
		</form>      
	");
	  //////////////////// editing buttons
	  ////////////////////////////////////

	  if($content_obj->title_align == "center")
	    echo("<center>");
	  
	  
	  echo("<font size=+$content_obj->title_font_size 
			face=$content_obj->title_font_face>
			$content_obj->title
			</font>");
	  
	  if($content_obj->title_align == "center")
	    echo("</center>");

	    echo("<br>");

	  //print image

	  //print body
	  if($content_obj->body_align == "center")
	    echo("<center>");
	  
	  
	  echo("<font size=$content_obj->body_font_size 
			face=$content_obj->body_font_face>
			$content_obj->body
			</font>");


	  if($content_obj->body_align == "center")
	    echo("</center>");


	  echo("<hr>");
	}



	//insert footer stuff
echo("<br>");
echo("<hr>");



	//cleanup
mysql_free_result($site);
mysql_free_result($current_page);
mysql_free_result($content);

	//close page
	echo("</body>");
	echo("</html>");
?>

	
<?
/*
QUERY NOTES:
get the homepage_id from the site tables;
select homepage_id from site where site_id = $site_id;

get all content ordered by ref_id for a page:
select * from content where page_id = $id order by ref_id;
*/
?>
