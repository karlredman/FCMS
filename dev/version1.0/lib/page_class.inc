<?

include_once("globals.inc");
include_once("error.inc");

include_once("supportFun.inc");

include("component_class.inc");

class page_class
{
  function page_class($message)
    { 
      global $HTTP_POST_VARS, $HTTP_GET_VARS;

      $this->id = $message->page_id; 
      $this->site_id = $message->site_id;
      $this->message = $message;
      
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
      
      if(!$message->mode)
	{
	  $message->mode = "page";
	  $message->action = "display";
	}
	

     //pump
     $this->pump(&$message);
    }

  var $sql_page;
  var $sql_page_obj;

  
  var $id;				//page id
  var $site_id;
  var $message;
  var $component;

  function destroy()
    {
      mysql_free_result($this->sql_page);
    }

  
  function display_contents_by_theme($theme)
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
	$this->component->display_doubled(&$this->message);
	break;
      case "staggared":
	$this->component->display_staggared(&$this->message, "");
      case "staggared_reverse":
	$this->component->display_staggared(&$this->message, "reverse");
	break;
      case "default":
      case "noblocks":
      default:
	$this->component->display_default(&$this->message);
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
	      form_std( $this->host_id, $this->site_id, 
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
	      if($GLOBALS[authorized])
	      {
		
	      }
	      break;
	    case edit:
	      if($GLOBALS[authorized])
	      {
		//display_page_heading("fcms: Edit Page");
		$this->component = new component_class(&$message);
		$this->display_contents_by_page_type();
	      }
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
	  switch($message->action)
	    {
	    case admin:
	      if($GLOBALS[authorized])
	      {
	      }
	      break;
	    case edit:
	      if($GLOBALS[authorized])
	      {
	      //display_page_heading();
	      $this->component = new component_class(&$message);
	      $this->display_contents_by_page_type();
	      }
	      break;
	    case save:
	      if($GLOBALS[authorized])
	      {
	      //create a component
	      $this->component = new component_class(&$message);

	      //save the content type component
	      $this->component->save_content(&$message);
	      
	      //redisplay page after save
	      $this->pump(&$message);
	      }
	      break;
	    }
	  break;
	default:
	  break;
	}
    }
}// end page_class
?>
