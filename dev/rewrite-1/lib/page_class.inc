<?

include_once("globals.inc");
include_once("error.inc");

include_once("supportFun.inc");

include("component_class.inc");

class page_class
{
  function page_class($message)
    { 
      $this->id = $message->page_id; 
      $this->site_id = $message->site_id;

      //get page data
     if(! ($this->sql_page=mysql_query("select * from page where page_id = $message->page_id")) )
       {
	 error_quit("mysql_query()", "page_class::():sql_page", TRUE );
       }

     if(! ($this->sql_page_obj=mysql_fetch_object($this->sql_page)) ) 
       error_quit("mysql_fetch_object()", "page_class::():sql_page_obj", TRUE );

     //pump
     $this->pump(&$message);

     //$thing = $this->sql_page_obj;
     //print("sql_page_obj->page_title = $thing->page_title<br>\n");
    }

  var $sql_page;
  var $sql_page_obj;

  
  var $id;				//page id
  var $site_id;
  var $component;

  function destroy()
    {
      mysql_free_result($this->sql_page);
    }

  
  function display_contents_by_theme($theme)
    {
  //display contents based on an internal standerdized theme


  /*
        NOTE: Themes may be one of the following
        or your can write your own :)

        default = content-items are displayed straight down the page.

        noblocks = same as the 'default' theme

        doubled = a table is used to display 2 content-items per row.

        staggared = a table is used to display 2 content-items on
                even rows and 1 content-item on odd rows.
  */

  switch ($theme) {
  case "doubled":
    $this->component->display_doubled();
    break;
  case "staggared":
    $this->component->display_staggared("");
  case "staggared_reverse":
    $this->component->display_staggared("reverse");
    break;
  case "default":
  case "noblocks":
  default:
    $this->component->display_default();
    break;
  }
}

  function display_contents_by_page_type()
    {
      //display contents based on the page->type from the database
      
      $thing = $this->sql_page_obj;
      $this->display_contents_by_theme($thing->type);
    }


  function pump($message)
    {
      switch($message->mode)
	{
	case page:
	  switch($message->action)
	    {
	    case edit:
	      //display_page_heading("fcms: Edit Page");
	      $this->component = new component_class(&$message);
	      $this->display_contents_by_page_type();
	      break;
	    case display:
	    default:
	      //display_page_heading();
	      $this->component = new component_class(&$message);
	      $this->display_contents_by_page_type();
	      break;
	    }
	  break;
	case component:
	  break;
	default:
	  break;
	}
    }
}// end page_class
?>