<?

/*
 *
 ************** Database Functions
 *
*/

function db_connect()
{
  //declare globals
  global $db_name;
  global $access_host;
  global $access_user;
  global $access_password;

  $link = mysql_connect("$access_host", "$access_user", "$access_password");

  if($link && mysql_select_db($db_name))
    return $link;

  return(FALSE);
}

function common_db_connect()
{
  global $db, $site, $site_obj, $current_page, $current_page_obj, $content, $content_obj;
  global $host_id, $site_id, $id, $referp_id, $id, $mode, $action_code; 

if(! ($db = db_connect()) )
     error_quit("db_connect()", "common_db_connect()", TRUE );

     ////////////////////////get start page (home page for now)
     //get site
     $site=mysql_query("select * from site where site_id = $site_id" ,$db)
     or die ("mysql_query:site_id=$site_id");

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

     //check mode and get page content
     if($mode != "edit_content_item")
       $content=mysql_query( "select * from content where page_id = $current_page_obj->page_id order by ref_id;") or die ("mysql_query:content");
     else
       if($action_code)
	 $content= mysql_query( "select * from content where content_id = $action_code order by ref_id;") or die ("mysql_query:content:edit_content_item");
     
     $content_obj = mysql_fetch_object($content)
     or die ("mysql_fetch_object:content_obj");
     
}

function db_get()
{
}

function db_put()
{
}
?>