<?
/* libmycms.inc
*/
?>

<?



/***************************************************************/

function error_quit($function, $message, $quit)
{
  if($quit)
    print("ERROR: FATAL: ");
  else
    print("ERROR: NON FATAL: ");

  print("$function: $message");

  if($quit)
    exit;
}


//text formatting
function textbox_insert_internal_link()
{
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
}


//these need to be in order

//include("libmycms.inc");
include("libmycms-globals.inc");
include("libmycms-db.inc");
include("libmycms-forms.inc");
include("libmycms-buttons.inc");
include("libmycms-html.inc");
include("libmycms-page.inc");

?>
