<?
/* buttons_show.inc
 */

function back_button($message)
{
  if($message->referp_id ||
     strstr($message->action,"edit") )
    {
      //default button type
      $btn_type = "back";

      if($message->action == "edit" &&
	 $message->security_level <= 3)
	{
	  $page_id = $message->page_id;
	  $referp_id = $message->referp_id;

	  switch($message->mode)
	    {
	    case "component":
	      $mode = "page";
	      $action = "edit";
		    
	      //its a cancel button for this
	      $btn_type = "cancel";
		    
	      break;
		    
	    case "page":
	      //$mode = $message->page;
	      $mode = "page";
	      $action = "display";
	      break;
	    default:
	      //$mode = $message->page;
	      $mode = "page";
	      $action = $message->action;
	      break;
	    }
	}
      else
	{
	  //$mode = $message->referp_id;
	  $mode = "page";
	      
	  //$action = $message->action;
	  $action = "display";
		
	  //$page_id = $message->page_id;
	  $page_id = $message->referp_id;

	  $referp_id = $message->page_id;
	}
	  
	  
	  
	  
      print("<td>");
      $button = new button_class($message->host_id, $message->site_id, 
				 $page_id, $referp_id,
				 $message->content_id,
				 $mode, $action,
				 $btn_type);
      print("</td>\n");
    }
}

function home_button($message, $homepage_id)
{
  if($message->action == "edit" &&
     $message->page_id == $homepage_id)
    {
      print("<td>");
      $button = new button_class($message->host_id, $message->site_id, 
				 $obj->homepage_id, $message->referp_id,
				 $message->content_id,
				 "page", "display",
				 "home");
      print("</td>\n");
    }
  else if($message->page_id != $homepage_id)
    {
      print("<td>");
      $button = new button_class($message->host_id, $message->site_id, 
				 $obj->homepage_id, $message->page_id,
				 $message->content_id,
				 "page", "display",
				 "home");
      print("</td>\n");
    }

}


function edit_buttons($message)
{
  //show edit button
  if(!strstr($message->action, "edit") )
    {
      //edit host
      if($message->security_level == 0)
	{
	  print("<td>");
	  $button = new button_class($message->host_id, $message->site_id, 
				     $message->page_id, $message->referp_id,
				     $message->content_id,
				     "host", "edit",
				     "edit_host");
	  print("</td>\n");
	}

      if($message->security_level <= 1)
	{
	  print("<td>");
	  $button = new button_class($message->host_id, $message->site_id, 
				     $message->page_id, $message->referp_id,
				     $message->content_id,
				     "site", "edit",
				     "edit_site");
	  print("</td>\n");
	}

      if($message->security_level <= 2)
	{
	  print("<td>");
	  $button = new button_class($message->host_id, $message->site_id, 
				     $message->page_id, $message->referp_id,
				     $message->content_id,
				     "page", "edit",
				     "edit_page");
	  print("</td>\n");
	}

      err_out("security level: $message->security_level");
    }
}



function login_button($message)
{
  if($message->mode != authorize)
    {
      print("<td>\n");
      if($message->security_level > 2)
	{
	  //show login button
	  $button = new button_class($message->host_id, $message->site_id, 
				     $message->page_id, $message->referp_id,
				     $message->content_id,
				     "authorize", "login_form",
				     "login");
	}
      else
	{
	  //show logout button
	  $button = new button_class($message->host_id, $message->site_id, 
				     $message->page_id, $message->referp_id,
				     $message->content_id,
				     "authorize", "logout",
				     "logout");
	}
      print("</td>\n");
    }
}
?>
