<?
/* content_class.inc 
 */

include("component_class.inc");

class content_component_class 
{
  var $sql_content;
  var $sql_content_obj;

  var $component;

  function content_component_class($message, $component)
    {
      $this->component = $component;
      
      //get content data
      $this->init(&$message);
    }

  function init($message)
    {
      if( ! ($this->sql_content= 
	     mysql_query("select * from content_component where page_id = ".
			 "$message->page_id order by ref_id")) )
	{
	  error_quit("mysql_query()", 
		     "component_class::():sql_content_component", TRUE );
	}
      
      if(! ($this->sql_content_obj= 
		mysql_fetch_object($this->sql_content)) ) 
	{
	  error_quit("mysql_fetch_object()", 
		     "component_class::():sql_content_component_obj", TRUE );
	}
    }

  function destroy()
    {
      if($this->sql_site)
	mysql_free_result($this->sql_site);
    }

  function xdisplay_default($message)
    {
      do{ 
	//$this->show_content(&$message,1);

	//$x = $this->component->sql_component_obj->title;
	//err_out("$x");

	err_out($this->component->sql_component_obj->title);
	err_out($this->sql_content_obj->body);

	$this->sql_content_obj= mysql_fetch_object($this->sql_content);

      } while($this->component->sql_component_obj = 
	      mysql_fetch_object($this->component->sql_component));
	  // && $this->sql_content_obj= mysql_fetch_object($this->sql_content) );
    }

  function display_default($message)
    {
      //display contents (default theme)

      $db;
      if($message->again)
	{
	  $message->again = FALSE;
	  
	  //$db &= $message->LINK;
	  //$db = new db_class();
	  
	  //$this->init($message);
	  //$this->component->init($message);
	}


      do{
	//for in page editing switch
	if(strstr($message->mode, "component") && 
	   strstr($message->action, "edit") && 
	   !$GLOBALS["in_page_editing"])
	  {

	    //err_out("display default():".$this->component->sql_component_obj->id); $message->dump(); //exit;
	    if( $message->component_id == $this->component->sql_component_obj->id) 
	      {
		$this->show_content(&$message, 1);
		return;
	      }
	    else 
	      {
		$this->sql_content_obj= mysql_fetch_object($this->sql_content);
		continue;
	      }
	  }

	//err_out("display default():"); $message->dump(); exit;
	$this->show_content(&$message, 1);
    
	print("<td></tr>\n");
    
	//if(strstr($this->mode, "page") &&
	if(strstr($message->action, "edit") )
	  { 
	    print("<hr>\n"); 
	  }

	///} while($comp_obj = 
	  	///    mysql_fetch_object($comp_sql) &&
	  	///    $this->sql_content_obj= mysql_fetch_object($this->sql_content) );


	$this->sql_content_obj= mysql_fetch_object($this->sql_content);
      } while($this->component->sql_component_obj = 
	      mysql_fetch_object($this->component->sql_component) );
      //&& $this->sql_content_obj= mysql_fetch_object($this->sql_content));
    }

  function display_doubled($message)
    {
      //display contents (doubled theme)

      if($message->again)
	  $message->again = FALSE;

      $component = $this->component;
      $comp_sql = $component->sql_component;
      $comp_obj = $component->sql_component_obj;

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

	$this->sql_content_obj= mysql_fetch_object($this->sql_content);
      } while($this->component->sql_component_obj = 
	      mysql_fetch_object($this->component->sql_component) );
      //} while($comp_obj = mysql_fetch_object($comp_sql) &&
	//      $this->sql_content_obj= mysql_fetch_object($this->sql_content) );

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

      if($message->again)
	  $message->again = FALSE;

      $component = $this->component;
      $comp_sql = $component->sql_component;
      $comp_obj = $component->sql_component_obj;

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
    
	
	$this->sql_content_obj= mysql_fetch_object($this->sql_content);
      } while($this->component->sql_component_obj = 
	      mysql_fetch_object($this->component->sql_component) );
      //} while($comp_obj = mysql_fetch_object($comp_sql) &&
	      //$this->sql_content_obj= mysql_fetch_object($this->sql_content) );
    
      print("</table>\n");

    }

  function show_content($message, $wide)
    {
      //display a component of type content
  //err_out("show_content():"); $message->dump(); exit;

      //table for buttons
      print("<table><tr>\n");

      if($message->mode == "page" &&
	 $message->action == "edit" &&
	 $message->security_level <= 3)
	{
	  print("<td>");
	  if(!($button = new button_class($message->host_id, $message->site_id, 
					  $message->page_id, $message->referp_id,
					  $this->component->sql_component_obj->id,
					  "component", "edit",
					  "edit") ))
	    {
	      ////////////////////hmmmmmmmm......... !!!
	      //error_quit("show_content()", "new button_class()", TRUE);
	    }
	  print("</td>");
	}
      if($message->mode == "page" &&
	 $message->action == "edit" &&
	 $message->security_level <= 2)
	{
	  print("<td>");
	  if(!($button = new button_class($message->host_id, $message->site_id, 
					  $message->page_id, $message->referp_id,
					  $this->component->sql_component_obj->id,
					  "component", "delete",
					  "delete") ))
	    {
	      ////////////////////hmmmmmmmm......... !!!
	      //error_quit("show_content()", "new button_class()", TRUE);
	    }
	  print("<td>");
	}

      if($message->mode == "page" &&
	 $message->action == "edit" &&
	 $message->security_level <= 2)
	{
	  print("<td>");
	  if(!($button = new button_class($message->host_id, $message->site_id, 
					  $message->page_id, $message->referp_id,
					  $this->component->sql_component_obj->id,
					  "component", "admin",
					  "settings") ))
	    {
	      ////////////////////hmmmmmmmm......... !!!
	      //error_quit("show_content()", "new button_class()", TRUE);
	    }
	  print("<td>");
	}

      print("</tr></table>\n");
  
      if(strstr($message->mode, "component") && 
	 strstr($message->action, "edit") && 
	 $message->component_id == $this->component->sql_component_obj->id &&
	 $message->security_level <= 3) 
	{
	  //err_out("show_content():"); $message->dump(); exit;
	  //tell user what we are doing
	  print("<b><font size=+2 >".
		"Editing component ".$this->component->sql_component_obj->ref_id.":".
		$this->component->sql_component_obj->title.
		"</font></b><br><br>\n");
	}

      if($this->component->sql_component_obj->title)
	//display content title
	if($this->component->sql_component_obj->title_align == "center")
	  echo("<center>");
  
      if(strstr($message->mode, "component") && 
	 strstr($message->action, "edit") && 
	 $message->component_id == $this->component->sql_component_obj->id &&
	 $message->user_level <= 2)
	{
	  //open a form around the content
	  form_open(NULL);
	  
	  //setup standard variables (save in the current mode)
	  form_std($message->host_id, $message->site_id, 
		   $message->page_id, $message->referp_id,
		   $this->component->sql_component_obj->id,
		   "component", "save");
	  //$message->mode, "save");
	  
	  form_add_textbox("content_title", 
			   $this->component->sql_component_obj->title, NULL);
	}
      else
	if($this->component->sql_component_obj->title)
	  print("<font size=+".$this->component->sql_component_obj->title_font_size." ".
		"face=".$compO->title_font_face."> ".
		$this->component->sql_component_obj->title." </font>\n");

      if($this->component->sql_component_obj->title)
	if($this->component->sql_component_obj->title_align == "center")
	  print("</center>\n");
  
      if($this->component->sql_component_obj->title)
	echo("<br>\n");
  
      //display content image

      //display content body
      if($this->sql_content_obj->body_align == "center")
	echo("<center>\n");

      if(strstr($message->mode, "component") && 
	 strstr($message->action, "edit") && 
	 $message->component_id == $this->component->sql_component_obj->id &&
	 $message->security_level <= 2)
	{
	  //show edit box for body
	  if($wide)
	    $width = 80;
	  else
	    $width = NULL;

	  //err_out("content id:".$this->sql_content_obj->id);

	  //$message->component_id == $this->component->sql_component_obj->id) 
	  if($this->sql_content_obj->body != NULL)
	    form_add_textarea("content_body", $this->sql_content_obj->body, 
			      $witdth, NULL);
	  else
	    form_add_textarea("content_body", "Sample Content text.",
			      $width, NULL);

	  //put buttons below box
	  print("<br>\n");
	  
	  //close center -buttons go on the right
	  if($this->sql_content_obj->body_align == "center")
	    print("</center>\n");

	  //show a submit button
	  form_add_submit_reset(NULL);

	  //open center if needed
	  if($this->sql_content_obj->body_align == "center")
	    print("<center>\n");

	  //close the form
	  form_close();
	}
      else
	{
	  //convert body to html
	  //err_out("id:".$this->sql_content_obj->id);
	  $body = txt2html($this->sql_content_obj->body);
	  print("<font size=".$this->sql_content_obj->body_font_size." ".
		"face=".$this->sql_content_obj->body_font_face."> ".$body." </font>\n");
	}
  
      if($this->sql_content_obj->body_align == "center")
	echo("</center>\n"); 

      //$this->sql_content_obj= mysql_fetch_object($this->sql_content);

    }

  function save_content($message)
    {
      //save a content type component

      global $HTTP_POST_VARS;

      //make query string
      $title=$HTTP_POST_VARS["content_title"];
      $body=$HTTP_POST_VARS["content_body"];

      $query_str="update component set title='".$title."'".
	" where id=".$message->component_id."";

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

  function add($message, $ref_id)
    {
	$query_str = "select * from content_component order by ref_id desc";
      
	if( ! $cont = mysql_query("$query_str") )
	  error_quit("content_component_class", "select content", TRUE);

	if(! $contO = mysql_fetch_object($cont) )
	  error_quit("content_component_class", "fetch content", TRUE);

	$query_str = "insert into content_component set page_id = $message->page_id, ".
	  "component_id = $message->component_id, ref_id = $ref_id";

	if(! ($result = mysql_query($query_str)) )
	  error_quit("content_component_class", "add", TRUE);
    }

  function delete($message)
    {
      $query_str = "delete from content_component where component_id = ".
	"$message->component_id";

	if(! ($result = mysql_query($query_str)) )
	  error_quit("content_component_class", "delete", TRUE);
    }
}
?>