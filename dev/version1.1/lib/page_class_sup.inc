<?
/* page_class_sup.inc
 */

include_once("componentSet_class.inc");
include_once("buttons_show.inc");

function PC_pump($message, $page_obj)
{
  switch($message->mode)
    {
    case authorize:
      switch($message->action)
	{
	case login_form:
	  //THIS SHOULD GRAB A LOGIN MODULE AND PUT IT ON A PAGE
	  //THAT IS DEFAULT MODE AND CONTAINES 1 COMPONENT

	  //should be a component !!!

	  //need login error handler !!!

	  print("<html>");
	  print("<body>");
	      
	  form_open(NULL);
	  form_std( $message->host_id, $message->site_id, 
		    $message->page_id, $message->referp_id,
		    $message->component_id,
		    "authorize", "login");
	  form_add_textbox("f_user", "fcms_host", NULL);
	  print("<br>\n");
	  form_add_passwd("f_pass", "passwd", NULL);
	  print("<br>\n");
	  form_add_submit_reset("Login");
	  form_close();
	      
	  print("</body>");
	  print("</html>");
	  exit;
	  break;
	case logout:
	  break;
	case site_admin:
	  break;
	case host_admin:
	  break;
	}
    case page:
      switch($message->action)
	{
	case admin:
	  break;
	case edit:
	  //display_page_heading("fcms: Edit Page");
	  $page_obj->componentSet = new componentSet_class(&$message);
	  $page_obj->display_contents_by_page_type(&$message);
	  break;
	case display:
	default:
	  //display_page_heading();
	  $page_obj->componentSet = new componentSet_class(&$message);
	  $page_obj->display_contents_by_page_type(&$message);
	  break;
	}
      break;
    case component:
      switch($message->action)
	{
	case admin:
	  break;
	case edit:
	      //display_page_heading();
	      $page_obj->componentSet = new componentSet_class(&$message);
	      $page_obj->display_contents_by_page_type(&$message);
	  break;
	case save:
	      //create a component
	      $page_obj->componentSet = new componentSet_class(&$message);

	      //save the content type component
	      $page_obj->componentSet->type_component->save_content(&$message);
	      
	      //redisplay page after save
	      $page_obj->pump(&$message);
	  break;
	}
      break;
    default:
      break;
    }
}


function PC_show_navigation($message, $homepage_id)
{
  ///////////////// page footer
  echo("<hr>");
          
  print("<table>\n");
  print("<tr>\n");

  //standard navigation
  back_button(&$message);
  home_button(&$message, $homepage_id);
  
  //authourized only navigation
  edit_buttons(&$message);

  //login and logout
  login_button(&$message);

  print("</tr>\n");
  print("</table>");
}


function PC_display_contents_by_theme($message, $theme, $page_obj)
{
  //display contents based on an internal standerdized theme


  /*
        NOTE: Themes may be one of the following:
        

        default = content-items are displayed straight down the page.

        noblocks = same as the 'default' theme

        doubled = a table is used to display 2 content-items per row.

        staggared = a table is used to display 2 content-items on
                even rows and 1 content-item on odd rows.

        staggared_reverse = a table is used to display 1 content-item on
                even rows and 2 content-items on odd rows.
  */
      
  //account for in page editing
  if(!$GLOBALS["in_page_editing"])
    $theme="default";

  $componentSet = $page_obj->componentSet;
  $type_obj = $componentSet->type_component;
  
  switch ($theme) {
  case "doubled":
    $type_obj->display_doubled(&$message);
    break;
  case "staggared":
    $type_obj->display_staggared(&$message, "");
  case "staggared_reverse":
    $type_obj->display_staggared(&$message, "reverse");
    break;
  case "default":
  case "noblocks":
  default:
    $type_obj->display_default(&$message);
    break;
  }
}

?>
