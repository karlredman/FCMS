<?
/* content_class.inc 
 */

include("component_class.inc");

class content_component_class component_class
{
  var $sql_content;
  var $sql_content_obj;

  var $component;

  function content_class($message, $component)
    {
      $this->component = $component;

      //get content data
	  if( ! ($this->sql_content= 
		 mysql_query("select * from content_component where page_id = ".
			     "$message->page_id order by ref_id")) )
	    {
	      error_quit("mysql_query()", 
			 "component_class::():sql_content_component", TRUE );
	    }

	  if(! ($this->sql_content_obj= 
		mysql_fetch_object($this->sql_content_component)) ) 
	    {
	      error_quit("mysql_fetch_object()", 
			 "component_class::():sql_content_component_obj", TRUE );
	    }
    }

  function display_default($message)
    {
      //display contents (default theme)
      
      $obj = $(this->component)->sql_component_obj;

      do{

	//for in page editing switch
	if(strstr($message->mode, "component") && 
	   strstr($message->action, "edit") && 
	   !$GLOBALS["in_page_editing"])
	  {

	    if( $message->component_id == $obj->id) 
	      {
		$this->show_content(&$message, 1);
		return;
	      }
	    else 
	      continue;
	  }

	$this->show_content(&$message, 1);
    
	print("<td></tr>\n");
    
	//if(strstr($this->mode, "page") &&
	if(strstr($this->action, "edit") )
	  { 
	    print("<hr>\n"); 
	  }


      } while($(this->component)->sql_component_obj = 
	      mysql_fetch_object($(this->component)->sql_component) &&
	      $this->sql_content_obj= 
	      mysql_fetch_object($this->sql_content) 
	      );
    }

  function display_doubled($message)
    {
      //display contents (doubled theme)

      if(strstr($message->action, "edit") )
	print("<table border=1 cellspacing=0 cellpadding=0 width=100%>\n");
      else
	print("<table border=0 cellspacing=0 cellpadding=0 width=100%>\n");

      $col=1;

      do{


	if($col == 1)
	  {
	    print("<tr>\n");
	  }

	//display a content block
	print("<td>\n");
	$this->show_content(&$message,0);
	print("</td>\n");

	if($col == 2)
	  {
	    $col = 1;
	    print("</tr>\n");
	  }
	else
	  {
	    $col = 2;

	  }

      } while($(this->component)->sql_component_obj = 
	      mysql_fetch_object($(this->component)->sql_component));

      print("</table>\n");
    }

  function display_staggared($message, $command)
    {
      //display contents (default theme)
      /*
	$command can be:
		staggared = 2 content-items then one, then two, etc.
		staggared_reverse = 1 content-item then two, then one, etc.
      */

      //print("<table>\n");
      if(strstr($message->action, "edit") )
	print("<table border=1 cellspacing=10 cellpadding=10 width=100%>\n");
      else
	print("<table border=0 cellspacing=10 cellpadding=10 width=100%>\n");

      if($command == "reverse")
	$count = 2;
      else
	$count=1;

      $col=1;

      do{

	if($count%2)
	  {
	    //print two sql_component-items
	    if($col == 1)
	      print("<tr>\n");
	
	
	    //display a sql_component block
	    print("<td>\n");
	    $this->show_content(&$message, 0);
	    print("</td>\n");
	
	    if($col == 2)
	      {
		print("</tr>\n");
		$col = 1;
		$count++;
	      }
	    else
	      {
		$col = 2;
	      }
	  }
	else
	  {
	    //print one content-item
	    print("<tr>\n");
	
	    print("<td colspan=2>\n");
	    $this->show_content(&$message, 0);
	    print("</td>\n");
	
	    print("</tr>\n");

	    $count++;
	  }
    
	
      } while($(this->component)->sql_component_obj = 
	      mysql_fetch_object($this->sql_component));
    
      print("</table>\n");

    }

  function show_content($message, $wide)
    {
      //display a component of type content

      $obj = $(this->component)->sql_component_obj;
      $objc = $this->sql_content_obj;


      if($message->mode == "page" &&
	 $message->action == "edit" &&
	 $GLOBALS[authorized]) 
	{
	  //button_show_edit("edit_content_item", $this->sql_component_obj->content_id);

	  if(!($button = new button_class($message->host_id, $message->site_id, 
					  $message->page_id, $message->referp_id,
					  $obj->id,
					  "component", "edit",
					  "edit") ))
	    {
	      ////////////////////hmmmmmmmm......... !!!
	      //error_quit("show_content()", "new button_class()", TRUE);
	    }
	}
  
      if(strstr($message->mode, "component") && 
	 strstr($message->action, "edit") && 
	 $message->component_id == $obj->id &&
	 $GLOBALS[authorized]) 
	{
	  //tell user what we are doing
	  print("<b><font size=+2 >".
		"Editing component $obj->ref_id:".
		"<br>$obj->title".
		"</font></b><br><br>\n");
	}

      //display content title
      if($obj->title_align == "center")
	echo("<center>");
  
      //EDITING GOES HERE !!!

      if(strstr($message->mode, "component") && 
	 strstr($message->action, "edit") && 
	 $message->component_id == $obj->id &&
	 $message->user_level <= 2)
	{
	  //open a form around the content
	  form_open(NULL);
	  
	  //setup standard variables (save in the current mode)
	  form_std($message->host_id, $message->site_id, 
		   $message->page_id, $message->referp_id,
		   $message->component_id,
		   $message->mode, "save");
	  
	  form_add_textbox("content_title", $obj->title, NULL);
	}
      else
	print("<font size=+$obj->title_font_size face=$obj->title_font_face> ".
	      "$obj->title </font>\n");

      if($obj->title_align == "center")
	print("</center>\n");
  
      echo("<br>\n");
  
      //display content image

      //display content body
      if($objc->body_align == "center")
	echo("<center>\n");

      if(strstr($message->mode, "component") && 
	 strstr($message->action, "edit") && 
	 $message->component_id == $obj->id &&
	 $message->security_level <= 2)
	{
	  //show edit box for body
	  if($wide)
	    form_add_textarea("content_body", $objc->body, 
			      80, NULL);
	  else
	    form_add_textarea("content_body", $objc->body, 
			      NULL, NULL);

	  //put buttons below box
	  print("<br>\n");
	  
	  //close center -buttons go on the right
	  if($objc->body_align == "center")
	    print("</center>\n");

	  //show a submit button
	  form_add_submit_reset(NULL);

	  //open center if needed
	  if($obj->body_align == "center")
	    print("<center>\n");

	  //close the form
	  form_close();
	}
      else
	{
	  //convert body to html
	  $body = txt2html($objc->body);
	  print("<font size=$objc->body_font_size ".
		"face=$objc->body_font_face> $body </font>\n");
	}
  
      if($objc->body_align == "center")
	echo("</center>\n"); 
    }

  function save_content($message)
    {
      //save a content type component

      global $HTTP_POST_VARS;

      //make query string
      $title=$HTTP_POST_VARS["content_title"];
      $body=$HTTP_POST_VARS["content_body"];

      $query_str="update component set title='$title'".
	" where id=$message->component_id";

      if(! ($result = mysql_query($query_str)) )
	if(! ($result = mysql_query($query_str)) )
	  error_quit("component_class()", "save_content():mysql_query():1", TRUE);

      $query_str="update content_component set body='$body'".
	" where component_id=$message->component_id";

      if(! ($result = mysql_query($query_str)) )
	if(! ($result = mysql_query($query_str)) )
	  error_quit("component_class()", "save_content():mysql_query():2", TRUE);

      //change mode to page edit
      $message->mode = "page";
      $message->action = "edit";
    }

}
?>