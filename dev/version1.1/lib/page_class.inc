<?

include_once("globals.inc");
include_once("error.inc");

include_once("supportFun.inc");

include_once("componentSet_class.inc");
include_once("page_class_sup.inc");

class page_class
{

  var $sql_page;
  var $sql_page_obj;
  
  var $componentSet;
  var $homepage_id;


  function page_class($message, $homepage)
    { 
      global $HTTP_POST_VARS, $HTTP_GET_VARS;

      $this->homepage_id = $homepage;

      //get page data
      if($HTTP_GET_VARS[page_name] && !$HTTP_POST_VARS[mode])
	{
	  //use page name for display instead

	  if(! ($this->sql_page=mysql_query("select * from page where file_name = ".
					    "'$HTTP_GET_VARS[page_name]'")) )
	    //"'SamplePageTitle2'")) )
	    error_quit("mysql_query()", "site_class::():sql_page_tans", TRUE );

	  $message->mode = "page";
	  $message->action = "display";

	  if($HTTP_GET_VARS[referp_id])
	    $message->referp_id = $HTTP_GET_VARS[referp_id];
	}
      else 
	{
	  if(!$message->page_id)
	    $message->page_id = $homepage;

	  if(! ($this->sql_page=mysql_query("select * from page ".
					    "where id = $message->page_id")) )
	    { error_quit("mysql_query()", "page_class::():sql_page", TRUE ); }
	  
	  if(! ($this->sql_page_obj=mysql_fetch_object($this->sql_page)) ) 
	    error_quit("mysql_fetch_object()", "page_class::():sql_page_obj", TRUE );
	}

      //set default mode if not set yet
      if(!$message->mode)
	{
	  $message->mode = "page";
	  $message->action = "display";
	}
      
      //pump
      $this->pump(&$message);
      
     $this->show_navigation(&$message);

     //shutdown

     //close body
     html_body_close();
     
     //close page
     html_end();

    }
  
  function destroy()
    { 
      if($this->sql_page)
	mysql_free_result($this->sql_page); 
    }

  
  function display_contents_by_theme($message, $theme) 
    { PC_display_contents_by_theme(&$message, $theme, &$this); }

  
  function display_contents_by_page_type($message)
    {
      //display contents based on the page->type from the database
      
      $obj = $this->sql_page_obj;
      $this->display_contents_by_theme(&$message, $obj->type);
    }

  function pump($message)
    { return(PC_pump(&$message, &$this)); }


  function show_navigation($message)
    { 
      PC_show_navigation(&$message, $this->homepage_id); 
    }


}// end page_class
?>
