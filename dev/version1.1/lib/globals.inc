<?
/* globals.inc 
*/

//debug mode (turn off for security !!!)
$debug = 0;

//authorization switch -RETURED !!!
//$authorized;

//allow for in_page_editing (default is off)
/* Note: this feature if for the overall fcms infastructure. Stuff
like WAP and text browsers will be handled internally (probably using
this or another flag like this one)
*/
$in_page_editing = 1;

//image files
/* Note: these are the fcms default images. The button_class offers a
way of using different images for different buttons if necessary
*/
$home_image="$fcms_images_path/home.gif";
$back_image="$fcms_images_path/back.gif";

$cancel_image="$fcms_images_path/cancel.gif";
$delete_image="$fcms_images_path/delete.gif";

$add_component_image="$fcms_images_path/addComponent.gif";
$addPage_image="$fcms_images_path/addPage.gif";

$admnPage_image="$fcms_images_path/admnPage.gif";

$delete_component_image="$fcms_images_path/deleteComponent.gif";
$delete_page_image="$fcms_images_path/deletePage.gif";

$edit_image="$fcms_images_path/edit.gif";
$editHost_image="$fcms_images_path/editHost.gif";
$editSite_image="$fcms_images_path/editSite.gif";
$editPage_image="$fcms_images_path/editPage.gif";

$settings_image="$fcms_images_path/settings.gif";
$login_image="$fcms_images_path/login.gif";
$logout_image="$fcms_images_path/logout.gif";

$site_logo="$fcms_images_path/logo.gif";

$fcms_logo="$fcms_images_path/fcms_logo.gif";
?>
