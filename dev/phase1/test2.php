<?
/*
stuff that gets passed in
$id
$refer_id
*/

$host_id=1;
$site_id=1;

//include functions from library
include("mylib.inc");


//////////////////////connect to database
if(! ($db = db_connect()) )
     error_quit("db_connect()", "from main", TRUE );

     ////////////////////////get start page (home page for now)
     //get site
     $site=mysql_query("select * from site where site_id = $site_id" ,$db)
     or die ("mysql_query:site");

     $site_obj=mysql_fetch_object($site) 
     or die ("mysql_fetch_object:site_obj");

     //see if this is the first time where here
     if(!$id)
     $id=$site_obj->homepage_id;

     //get page for site
     $current_page=mysql_query( "select * from page where page_id = $id;" ,$db)
     or die ("mysql_query:current_page");

     $current_page_obj = mysql_fetch_object($current_page)
     or die ("mysql_fetch_object:current_page_obj");

     //get page content
     $content=mysql_query( "select * from content where page_id = $current_page_obj->page_id order by ref_id;" ,$db) or die ("mysql_query:content");
     
     $content_obj = mysql_fetch_object($content)
     or die ("mysql_fetch_object:content_obj");
     
     //start page
     html_begin();
     
     //header
     html_head_open("$current_page_obj->page_title", "$current_page_obj->page_heading");
     html_head_close();
     
     //body
     //html_body_open("#FFFFFF", "#000000", "pix/watch.jpg", "#99FFFF", "#99CCFF", "#99FFFF");
     html_body_open("$current_page_obj->body_color_fg", "$current_page_obj->body_color_bg", 
		    "$current_page_obj->body_image", "$current_page_obj->body_link", 
		    "$current_page_obj->vbody_link", "$current_page_obj->body_alink");

     //print the page heading
     print("<H1>$current_page_obj->page_heading</H1><BR>\n");

     //display contents
     do{
       //theme - template stuff here?
       
       //display a content block
       show_content($content_obj);
       echo("<hr>");
       
     } while($content_obj = mysql_fetch_object($content));

echo("<br>");
echo("<hr>");

button_show_login($site_obj, $current_page_obj); 
button_show_home($site_obj, $current_page_obj); 
button_show_back($site_obj, $current_page_obj, $referid); 

//close body
html_body_close();

//close page
html_end();

?>
