<?
include_once("globals.inc");
include_once("error.inc");

include_once("supportFun.inc");

class component_class
{
  var $sql_component;
  var $sql_component_obj;

  var $id;				//component id
  var $action;				//component action

  function component_class($message)
    { 
      $this->id = $message->component_id;
      $this->mode = $message->mode;
      $this->action = $message->action;

      //get site data
      if(! ($this->sql_component=
	    mysql_query("select * from content where page_id = $message->page_id")) )
	{
	  error_quit("mysql_query()", "component_class::():sql_component", TRUE );
	}

      if(! ($this->sql_component_obj=mysql_fetch_object($this->sql_component)) ) 
	error_quit("mysql_fetch_object()", "component_class::():sql_component_obj", TRUE );


      //$this->display_default(&$message);
      //$thing = $this->sql_component_obj;
      //print("sql_component_obj->title = $thing->title<br>\n");
    }

  function destroy()
    {
      mysql_free_result($this->sql_component);
    }

  function display_default($message)
    {
      //display contents (default theme)
      
      $obj = $this->sql_component_obj;

      do{
	$this->show_content($message);
    
	print("<td></tr>\n");
    
	//err_out("$message->mode");

	if(strstr($this->mode, "page") &&
	   strstr($this->action, "edit") )
	  { 
	    print("<hr>\n"); 
	  }

      } while($this->sql_component_obj = mysql_fetch_object($this->sql_component));
    }

  function display_doubled($message)
    {
      //display contents (doubled theme)

      if(strstr($this->action, "edit") )
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
	$this->show_content(&$message);
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

      } while($this->sql_component_obj = mysql_fetch_object($this->sql_component));

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
      if(strstr($this->action, "edit") )
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
	    $this->show_content(&$message);
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
	    $this->show_content(&$message);
	    print("</td>\n");
	
	    print("</tr>\n");

	    $count++;
	  }
    
	
      } while($this->sql_component_obj = mysql_fetch_object($this->sql_component));
    
      print("</table>\n");

      if($debug)
	print("<hr>\n");
    }

  function show_content($message)
    {
      $obj = $this->sql_component_obj;

      if($this->mode == "page" &&
	 $this->action == "edit")
	{
	  //button_show_edit("edit_content_item", $this->sql_component_obj->content_id);

	  if(!($button = new button_class($message->host_id, $message->site_id, 
					  $message->page_id, $message->referp_id,
					  $obj->content_id,
					  "component", "edit",
					  "edit") ))
	    {
	      ////////////////////hmmmmmmmm.........
	      //error_quit("show_content()", "new button_class()", TRUE);
	    }
	}
  
      //display content title
      if($obj->title_align == "center")
	echo("<center>");
  
      //EDITING GOES HERE !!!

      echo("<font size=+$obj->title_font_size face=$obj->title_font_face> $obj->title </font>");

      if($obj->title_align == "center")
	echo("</center>\n");
  
      echo("<br>\n");
  
      //display content image

      //display content body
      if($obj->body_align == "center")
	echo("<center>\n");

      //convert body to html
      $body = txt2html($obj->body);
	  
      if(strstr($message->mode, "component") && 
	 strstr($message->action, "edit") && 
	 $message->component_id == $obj->content_id) 
	{
	  err_out("GOT TO COMPONENT EDIT");
	  //edit_content_item($this->sql_component_obj->title, $body);
	  form_open(NULL);
	  form_std($message->host_id, $message->site_id, 
		  $message->page_id, $message->referp_id,
		   $message->component_id,
		  $message->mode, "save");
	  form_add_textarea("component_body", $body, NULL, NULL);
	  form_add_submit_reset(NULL);
	  form_close();
	}
      else
	echo("<font size=$obj->body_font_size face=$obj->body_font_face> $body </font>\n");
  
      if($obj->body_align == "center")
	echo("</center>\n"); 
    }
}
?>