<?
/* buttons_class.inc
 */
include_once("globals.inc");
include_once("error.inc");
include_once("forms.inc");

/* Note:
	Remember, a button is actually just a form with an image. All
	program flow buttons must send state information back to the
	program in order for fcms to work properly.

	This class is closely tied with the message_class in an effort
	to standardize program message for the various message-pumps.
*/
class button_class
{
  //forms based buttons
  
  function button_class($host_id, $site_id, 
			$page_id, $referp_id,
			$component_id,
			$mode, $action,
			$type)
    {
      switch($type)
	{
	case back:
	  $image = $GLOBALS["back_image"]; 
	  break; 
	case cancel:
	  $image = $GLOBALS["cancel_image"]; 
	  break;
	case edit:
	  $image = $GLOBALS["edit_image"]; 
	  break; 
	case home:
	  $image = $GLOBALS["home_image"]; 
	  break; 
	case login:
	  $image = $GLOBALS["login_image"]; 
	  break; 
	case logout:
	  $image = $GLOBALS["logout_image"]; 
	  break; 
	case site_logo:
	  $image = $GLOBALS["site_logo"]; 
	  break; 
	case fcms_logo:
	  $image = $GLOBALS["fcms_logo"]; 
	  //set variables to go to fcms homepage
	  break; 
	default:
	  error_quit("button_class", "no match on image $type", TRUE);
	}
  
      form_image_link(NULL,
		      $host_id, $site_id, 
		      $page_id, $referp_id,
		      $component_id,
		      $mode, $action, 
		      $image);
    }
}

?>
