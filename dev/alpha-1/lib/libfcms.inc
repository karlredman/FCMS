<?
/* libfcms.inc
*/
?>

<?
//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// NOTE: This stuff needs to stay in order
//////////////////////////////////////////////////////////////////////////////////////////

///////////////////// Program Files
//////////////////////////////////////////////////////////////////////////////////////////
$index_file="index.php";
$authenticate_file="index.php";

//image files
$login_image="images/login.gif";
$logout_image="images/logout.gif";
$home_image="images/home.gif";
$back_image="images/back.gif";
$edit_image="images/edit.gif";

$site_logo="images/logo.gif";
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

///////////////////// Library code
//////////////////////////////////////////////////////////////////////////////////////////
//these need to be in order

//include("libfcms.inc");		//this file

//level 1 (lowest level)
include("error.inc");			//error functions (basic)

//level 2
include("db.inc");			//database functions
include("forms.inc");			//forms API

//level 3
include("globals.inc");			//global variable declarations
include("navigation.inc");		//navigation logic (buttons...)
include("edit.inc");			//edit routines and such
include("display-page.inc");		//page display API
include("display-contents.inc");	//contents display API
include("manage-html.inc");		//html management

//////////////////////////
// SHOULD BE LAST ON THE LIST OF INCLUDES !!!
include("fcms.inc");			// main fcms entrypoint. 
//////////////////////////

//include("forms.inc");
//include("buttons.inc");
//include("html.inc");
//include("page.inc");
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////


///////////////////// DEBUG
//////////////////////////////////////////////////////////////////////////////////////////

//text formatting
//function textbox_insert_internal_link()
//{
  //if the link is a page then show a listbox of internal pages that
  //	can be linked to this may have to have authentication for user
  //	permissions levels.

  //if the link needs to be a file-link then choose from a list that
  //is uploaded by the user

  //if the link is an image-link then choose from a list of images
  //	(possibly use thumbnail indexs)

  //create a FORM tag group to put into the textbox for the link
  //	(we need to send the program the $id and the $referp_id)

  // the user can erase this code on his own if he wants too.
//}

?>
