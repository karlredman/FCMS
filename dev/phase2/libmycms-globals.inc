<?
/*
 *
 ************** Global Data
 *
*/

$mode;
/*
The various modes are:
	edit_content_item
	edit_heading
	edit_page
	login
	NULL
	preview
 */

/************** forms 
 */
//data
$action_code;
$content_title;
$content_body;


//Page Identifiers
$host_id=1;		//relative id of host (not used as of 3-23-03)
$site_id=1;		//relative id of the host site
$id;			//relative id of page (depreciating)
$page_id;		//relative id of page
$referp_id;		//the internal referal page

/******************************* db objects
 */
$db;
$site;
$site_obj;
$current_page;
$current_page_obj;
$content;
$content_obj;

/******************** authentication
 */
//access
$db_name="mycms";
$access_host="";
$access_user="root";
$access_password="eertwfld";

/*********************** configuration
 */
//program files
$page_display_file="index.php";
$password_check_file="index.php";

//images
$login_image="images/login.gif";
$logout_image = "images/logout.gif";
$home_image="images/home.gif";
$back_image="images/back.gif";
$edit_image="images/edit.gif";
$site_logo="images/logo.gif";


?>