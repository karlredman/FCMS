<?
/*
stuff that gets passed in
$id
$referp_id
$mode

$edit_yes
$authenticated_yes;
*/

//variables that should go somewhere else !!!!
$host_id=1;
$site_id=1;

//include functions from library
include("libmycms.inc");
include("libmycms-page.inc");


//just some globals
$page_display_file="index.php";
$password_check_file="index.php";

//////////////////////connect to database
common_db_connect($site_id, $id);


if($mode == "login") 
{ 
  //do login page
  html_begin();
  html_head_open("mycms login");
  html_head_close();
  
  print("<body>\n");

  print("This is a test page");
  
  //NOTE: buttons are turned off (because of a page 0 $id)
}
else if($mode == "edit")
{
  if($authenticated)
    {
      //show edit page
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
