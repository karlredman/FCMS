<?
//content-edit.php
?>

<?
//receive input or exit

//if(!$site_id)
  //exit;

//if(!$id)
  //exit;

//if(!$content_ref)
  //exit;


//connect to database
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


	/////////////////////////// GET PAGE:

	//get home page
        $site=mysql_query(
		"select * from site where site_id = $site_id"
		,$db);

	$site_obj=mysql_fetch_object($site);


	//get page header info
	$current_page=mysql_query(
	"select * from page where page_id = $id;"
	,$db) or exit;


//display stuff until we reach the edit field
	//display stuff
	if($cur_page_obj = mysql_fetch_object($current_page))
	{
		echo("<TITLE>$cur_page_obj->page_title</TITLE>");
		//echo("<META>
		echo("</HEAD>");


		echo("<BODY>");
		//echo("<BODY bg=000000 fg=ffffff

		if($cur_page_obj->title_align == "center")
		  echo("<center>");

		
		echo("<font size=+$cur_page_obj->title_font_size 
			face=$cur_page_obj->title_font_face>
			$cur_page_obj->page_title
			</font>");

		if($cur_page_obj->title_align == "center")
		  echo("</center>");


		//display edit area if appropriate
		if($content_ref == 0)
		  echo("
		<form    action = content-edit.php
		method = post>
		<input    type=text
                name=page_title
                value=\"$cur_page_obj->page_title\"
                size=40><br>
		<font     size=1
                color=#336666
                face=arial,helvetica>Page Title</font>
		<hr>"
		       );
	}


	//get page content items in order of ref_id;
        $content=mysql_query(
	"select * from content where page_id = $cur_page_obj->page_id order by ref_id;"
	,$db) or exit;

	//display content items

	while($content_obj = mysql_fetch_object($content))
	{
	  //print title
	  echo("");
	  if($content_obj->title_align == "center")
	    echo("<center>");
	  
	  
	  echo("<font size=+$content_obj->title_font_size 
			face=$content_obj->title_font_face>
			$content_obj->title
			</font>");
	  
	    echo("<br>");

	  if($content_obj->title_align == "center")
	    echo("</center>");

		//display edit area if appropriate
		if($content_ref == $content_obj->content_id)
		  echo("
		<form    action = content-save.php
		method = post>
		<input    type=text
                name=body
                value=\"$content_obj->title\"
                size=40><br>
		<font     size=1
                color=#336666
                face=arial,helvetica>Content Title</font>"
		       );

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

		//display edit area if appropriate
		if($content_ref == $content_obj->content_id)
		  echo("
		<br>
		<form    action = content-save.php
		method = post>
		<textarea    
		    name=body
                    cols=70
                    rows=12
                    wrap=virtual>$content_obj->body</textarea><br>
		<input type=submit>
		<font     size=1
                color=#336666
                face=arial,helvetica>Content Body</font>"
		       );


	  echo("<hr>");
	}


	  echo("<hr>");


	//insert footer stuff
	  //////////////////// buttons
/*
	  echo("       
		<form    action=index.php
        	method=post>
		<input  type=hidden
			name=site_id
			value=$site_obj->site_id>
		<input  type=hidden
		        name=id
			value=$cur_page_obj->page_id>
		<input  type=image
		        src=images/home.gif>
		</form>      
	");
*/

	  echo("       
		<a href=index.php><img src=images/home.gif alt=home></img></a>
	");

echo("
	<form action save-content.php
		method=post>
	<input type=hidden
		name=site_id
		value=site_obj->site_id>
	</form>
");
	  //////////////////// buttons
	  ////////////////////////////////////



	//cleanup
mysql_free_result($site);
mysql_free_result($current_page);
mysql_free_result($content);

	//close page
	echo("</body>");
	echo("</html>");
?>

