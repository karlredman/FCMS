<?
//include functions from library
include("libmycms.inc");

//variables that should go somewhere else !!!!
$host_id=1;
$site_id=1;
$autherized = 1;

//////////////////////connect to database
common_db_connect();


if($mode == "login") 
{ 
  //if($autherized)
    //stuff

  //do login page
  html_begin();
  html_head_open("mycms login");
  html_head_close();
  
  print("<body>\n");

  print("This is a test page");
  
  //NOTE: buttons are turned off (because of a page 0 $id)
}
else if($mode == "edit_content_item")
{

  html_begin();
  html_head_open("Edit Page Title");
  html_head_close();
  
  print("<body>\n");

  insert_form_content_item("text", NULL, NULL, $action_code);
  
}
else if($mode == "edit_heading")
{
  html_begin();
  html_head_open("Edit Page Title");
  html_head_close();
  
  print("<body>\n");

  insert_form_title("text", NULL, NULL, $current_page_obj->page_heading);
  
}
else if($mode == "edit_page")
{

  if($autherized)
    {
      //show edit page
      display_page_heading_by_theme($mode);
      display_contents_by_page_type();
    }
  else
    {
      //we shouldn't be here
      //display warning
    }

  
}
else
{
  /////////////////////start page
  display_page_heading_by_theme(NULL);

  ///////////////////page
  display_contents_by_page_type();
  //  display_contents_by_theme("doubled");
}

//display the footer
do_page_footer();


?>
