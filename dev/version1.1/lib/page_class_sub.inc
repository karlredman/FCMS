<?
/* page_class_sup.inc
 */

include("buttons_show.inc");

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
	  form_add_passwd("f_pass", "password", NULL);
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
	  $page_obj->display_contents_by_page_type();
	  break;
	case display:
	default:
	  //display_page_heading();
	  $page_obj->componentSet = new componentSet_class(&$message);
	  $page_obj->display_contents_by_page_type();
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
	      $page_obj->display_contents_by_page_type();
	  break;
	case save:
	      //create a component
	      $page_obj->componentSet = new componentSet_class(&$message);

	      //save the content type component
	      $page_obj->component->save_content(&$message);
	      
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
  editPage_button(&$message);
  editSite_button(&$message);
  editHost_button(&$message);

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
      
  switch ($theme) {
  case "doubled":
    $page_obj->componentSet->type_component->display_doubled(&$page_obj->message);
    break;
  case "staggared":
    $page_obj->componentSet->type_component->display_staggared(&$page_obj->message, "");
  case "staggared_reverse":
    $page_obj->componentSet->type_component->display_staggared(&$page_obj->message, "reverse");
    break;
  case "default":
  case "noblocks":
  default:
    $page_obj->componentSet->type_component->display_default(&$page_obj->message);
    break;
  }
}

?>
