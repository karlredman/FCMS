<?

include_once("globals.inc");
include_once("error.inc");

include_once("supportFun.inc");

include("component_class.inc");

class page_class
{

  var $sql_page;
  var $sql_page_obj;
  
  var $id;				//page id
  var $componentSet;



  function page_class($message, $homepage)
    { 
      global $HTTP_POST_VARS, $HTTP_GET_VARS;

      $this->id = $message->page_id; 
      
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
	if(! ($this->sql_page=mysql_query("select * from page ".
					  "where id = $message->page_id")) )
	  { error_quit("mysql_query()", "page_class::():sql_page", TRUE ); }
      
      if(! ($this->sql_page_obj=mysql_fetch_object($this->sql_page)) ) 
	error_quit("mysql_fetch_object()", "page_class::():sql_page_obj", TRUE );

      if(!$message->page_id)
	$message->page_id = $this->sql_page_obj->page_id;
      
      //set default mode if not set yet
      if(!$message->mode)
	{
	  $message->mode = "page";
	  $message->action = "display";
	}
      
      //pump
      $this->pump(&$message);
      
     show_navigation(&$message);



     //shutdown

     //close body
     html_body_close();
     
     //close page
     html_end();

    }
  
  function destroy()
    { mysql_free_result($this->sql_page); }

  
  function display_contents_by_theme($message, $theme) 
    { PC_display_contents_by_theme(&$message, $theme, &$this); }

  
  function display_contents_by_page_type()
    {
      //display contents based on the page->type from the database
      
      $thing = $this->sql_page_obj;
      $this->display_contents_by_theme($thing->type);
    }

  function pump($message)
    { PC_pump(&$message, &$this); }


  function show_navigation($message)
    { PC_show_navigation($message); }


}// end page_class
?>
