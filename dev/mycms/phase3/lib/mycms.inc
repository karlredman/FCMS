<?
/* mycms.inc

	Main entry point for mycms
*/


function mycms_init()
{
  //set globals
  global $access_host, $access_user, $access_password, $db_name;

  //get page data
  if(!get_page_data($access_host, $access_user, $access_password, $db_name)) 
    error_quit("get_page_data()", "mycms_init()", TRUE);

  return;
}

function mycms_run()
{
  //figure out what to do for each mode

  global $mode, $db, $current_page_obj, $content_obj;
  global $access_host, $access_user, $access_password, $db_name;
  global $page_id, $content_title, $action_code, $content_body;
  global $alt_edit;

  $refresh = FALSE;

  if(!isSet($referp_id))
    {
      //// NEVER DO ANY OF THESE THINGS!!!!
      //$referp_id = $page_id;
      //$mode="normal";
      //$action_code=0;
    }

  //check for special action codes

  //check for saves
  switch($mode)
    {
    case save_content_title:
    case save_content_body:
    case save_content:
    case save_page_heading:
      //connect to database
      //$x="localhost";
      //if(! ($db = db_pconnect($x, $access_user, $access_password, $db_name)) )
      if(! ($db = db_connect($access_host, $access_user, $access_password, $db_name)) )
	error_quit("mycms_run()", "dbconnect()", TRUE);

      mysql_select_db($db_name,$db);


      //check save modes
      switch ($mode)
	{
	case save_page_heading:
	  //update table
	  $query_str="update page set page_heading='$content_title' where page_id = $page_id";
	  break;
      
	case save_content:
	  $query_str="update content set body=\"$content_body\",
		title=\"$content_title\" where content_id=$action_code";
	  //title=\"$content_title\" where content_id=\"$action_code\"";
	  break;

	case save_content_title:
	  $query_str="update content set title='$content_title' 
		where content_id = $action_code";
	  break;

	case save_content_body:
	  $query_str="update content set body='$content_body' 
		where content_id = $action_code";
	  break;
	}

      //err_out("
	//action_code=$action_code,<br>
	//$content_title,<br>
	//$content_body.<br>
	//");
      if(! ($result = mysql_query($query_str)) )
	if(! ($result = mysql_query($query_str)) )
	error_quit("mycms_run()", "mysql_query()", TRUE);

      //reload page with saved stuff and changed mode

      $mode="edit_page";	//go back to the edit page

      mycms_init();
      mycms_run();
      return;
      
      break;
    default:
      break;
    }

  
  switch($mode)
    {
    case edit_content_item:
      if($alt_edit)
	{
	  display_page_heading($current_page_obj->page_heading);
	  display_contents_by_page_type();
	}
      else
	{
	  display_page_heading("Edit Conetent Item");
	  edit_content_item($content_obj->title, $content_obj->body);
	}
      break;
      
    case edit_heading:
      if($alt_edit)
	{
	  display_page_heading(NULL);
	  display_contents_by_page_type();
	}
      else
	{
	  display_page_heading("mycms: Edit Page");
	  edit_page_header($current_page_obj->page_heading);
	}
      break;

    case edit_page:
      display_page_heading("mycms: Edit Page");
      display_contents_by_page_type();
      break;

    case login:
    case logout:
    case NULL:
    case preview:
    case normal:
    default:
      display_page_heading(NULL);
      display_contents_by_page_type();

      break;
    }
}

function do_page_footer()
{
  global $site_obj, $current_page_obj, $referp_id, $page_display_file, $mode; 
  global $alt_edit;

  ///////////////// page footer
  echo("<br>");
  echo("<hr>");

  print("<table>\n");
  print("<tr>\n");


  //add back button for edit mode ('quit editing')
  //if($alt_edit && strstr($mode, "edit"))
  //{
  print("<td>");
  button_show_back($mode, $action_code);
  print("</td>\n");
  //}

  print("<td>");
  button_show_home(); 
  print("</td>\n");

  print("<td>");
  //button_show_login($site_obj, $current_page_obj, $password_check_file); 
  print("</td>\n");

  if(!strstr($mode, "edit") )
    {
      print("<td>");
      button_show_edit("edit_page", $referp_id );
      print("</td>\n");
    }

  
  //debug
  //print("<td>");
  //global $login_image;
  //form_image_link(NULL, "0", "0", NULL, NULL, $login_image);
  //print("</td>\n");

  print("</tr>\n");
  print("</table>");

  //err_out("referp_id  = $referp_id");
  //global $page_id, $referp_id, $action_code, $mode;
  //err_out("page_id = $page_id");
  //err_out("referp_id = $referp_id");
  //err_out("mode = $mode");
  //err_out("action_code = $action_code");

  //close body
  html_body_close();

  //close page
  html_end();

  $mode = "normal";
}

//function get_page_data()
function get_page_data($host, $user, $password, $db_name)
{
  global $db, $site, $site_obj, $current_page, $current_page_obj, $content, $content_obj;
  global $host_id, $site_id, $page_id, $referp_id, $mode, $action_code, $alt_edit; 


  //connect to the database
  if(! ($db = db_connect($host, $user, $password, $db_name)) )
    error_quit("db_connect()", "get_page_data()", TRUE);


     ////////////////////////get start page 
     //get site
     if(! ($site=mysql_query("select * from site where site_id = $site_id")) )
     	error_quit("mysql_query()", "common_db_connect():site", TRUE );

     if(! ($site_obj=mysql_fetch_object($site)) ) 
     	error_quit("mysql_fetch_object()", "common_db_connect():site_obj", TRUE );

     //see if this is the first time where here
     if(!$page_id)
       $page_id=$site_obj->homepage_id;

     //get page for site
     if(! ($current_page=mysql_query( "select * from page where page_id = $page_id;" ,$db)) )
     	error_quit("mysql_query()", "common_db_connect():current_page", TRUE );

     if(! ($current_page_obj = mysql_fetch_object($current_page)) )
     	error_quit("mysql_fetch_object()", "common_db_connect():current_page_obj", TRUE );


/////////////////////////////////////////////// MOVE THIS !
     //check mode and get page content
     if($mode == "edit_content_item" && !$alt_edit)
       {
	 if(! ($content= mysql_query( "select * from content where content_id = $action_code order by ref_id;")) ) 
    	 	error_quit("mysql_query()", "common_db_connect():contentx", TRUE );
       }
     else
       {
	 if(! ($content=mysql_query( "select * from content where page_id = $current_page_obj->page_id order by ref_id;")) ) 
	   error_quit("mysql_query()", "common_db_connect():content", TRUE );
       }
     
     if(! ($content_obj = mysql_fetch_object($content)) )
    	 	error_quit("mysql_query()", "common_db_connect():content_obj", TRUE );


     mysql_close($db);

     return TRUE;
}

?>
