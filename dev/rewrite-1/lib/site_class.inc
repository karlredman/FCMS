<?

include_once("globals.inc");
include_once("supportFun.inc");
include_once("error.inc");

include("page_class.inc");

class site_class
{
  function site_class($message)
    { 
      $this->id = $message->site_id; 

      //get site data
      if(! ($this->sql_site=mysql_query("select * from site where site_id = $this->id")) )
     	error_quit("mysql_query()", "site_class::():sql_site", TRUE );

      if(! ($this->sql_site_obj=mysql_fetch_object($this->sql_site)) ) 
	error_quit("mysql_fetch_object()", "site_class::():sql_site_obj", TRUE );

      //setup default stuff for message variables
      if(!$message->page_id)
	$message->page_id=$this->sql_site_obj->homepage_id;

      if(!$message->mode)
	$message->mode = "page";

      if(!$message->action)
	$message->action = "display";

      //do
      //{
      //;//do it until we're done
      //;//pump()

      //do page stuff
      $this->page = new page_class(&$message);

      //show the site footer and close the page
      $this->site_footer(&$message);
	  
	  
      //} while(!$this->page->done());
	
     
      //$thing = $this->sql_site_obj;
      //print("sql_site_obj->homepage_id = $thing->homepage_id<br>\n");
    }

  var $sql_site;
  var $sql_site_obj;

  
  var $id;				//site id
  var $page;

  function destroy()
    {
      $this->page->destroy();
      mysql_free_result($this->sql_site);
    }

  function site_footer($message)
    {
      $obj = $this->sql_site_obj;

      ///////////////// page footer
      echo("<br>");
      echo("<hr>");
          
      print("<table>\n");
      print("<tr>\n");
          

      //add back button?
      if($message->referp_id ||
	 strstr($message->action,"edit") )
	{
	  //default button type
	  $btn_type = "back";

	  if($message->action == "edit")
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
		  $mode = $message->page;
		  $action = "display";
		  break;
		default:
		  $mode = $message->page;
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
          
      //show home button
      if($message->action == edit &&
	 $message->page_id == $obj->homepage_id )
	{
	  print("<td>");
	  $button = new button_class($message->host_id, $message->site_id, 
				     $obj->homepage_id, $message->referp_id,
				     $message->content_id,
				     "page", "display",
				     "home");
	  print("</td>\n");
	}
      else if($message->page_id != $obj->homepage_id)
	{
	  print("<td>");
	  $button = new button_class($message->host_id, $message->site_id, 
				     $obj->homepage_id, $message->page_id,
				     $message->content_id,
				     "page", "display",
				     "home");
	  print("</td>\n");
	}
      

      //show edit button
      $authorized = TRUE;

      if(!strstr($message->action, "edit") && 
	 $authorized == TRUE)
	{
	  print("<td>");
	  $button = new button_class($message->host_id, $message->site_id, 
				     $message->page_id, $message->referp_id,
				     $message->content_id,
				     "page", "edit",
				     "edit");

	  print("</td>\n");
	}

      print("</tr>\n");
      print("</table>");

      //close body
      html_body_close();

      //close page
      html_end();
    }
}
?>