<?
/* globals.inc 
*/

//debug mode (turn off for security !!!)
$debug = 1;

//authorization switch
$authorized;

//allow for in_page_editing (default is off)
/* Note: this feature if for the overall fcms infastructure. Stuff
like WAP and text browsers will be handled internally (probably using
this or another flag like this one
*/
$in_page_editing = 1;

//image files
/* Note: these are the fcms default images. The button_class offers a
way of using different images for different buttons if necessary
*/
$back_image="$fcms_images_path/back.gif";
$cancel_image="$fcms_images_path/cancel.gif";
$edit_image="$fcms_images_path/edit.gif";
$home_image="$fcms_images_path/home.gif";
$login_image="$fcms_images_path/login.gif";
$logout_image="$fcms_images_path/logout.gif";
$site_logo="$fcms_images_path/logo.gif";

$fcms_logo="$fcms_images_path/fcms_logo.gif";
?>
