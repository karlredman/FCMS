<?

include_once("globals.inc");
include_once("error.inc");

include("accessvars.inc");

include("db_class.inc");
include("site_class.inc");




class host_class 
{
  function host_class($message)
    {
      //set authorization flag
      $GLOBALS["authorized"] = FALSE;

      //set id
      $this->id = $message->host_id;

      //register session data
      $this->register_session();


      //get host data
      if(! ($this->sql_host=mysql_query("select * from host where host_id = $this->id")) )
     	error_quit("mysql_query()", "host_class::():sql_host", TRUE );

      if(! ($this->sql_host_obj=mysql_fetch_object($this->sql_host)) ) 
	error_quit("mysql_fetch_object()", "host_class::():sql_host_obj", TRUE );

      //create a new site object so we can check site variables
      //		(including (db)
      $this->site = new site_class(&$message);

      //if the pump says pass it on, then do so
      if($this->pump(&$message))
	{
	  $this->site->run(&$message);
	}
    }

      
  var $id;				//id of host (passed in)

  var $db;				//database object
  var $sql_host;			//sql host row pointer
  var $sql_host_obj;			//sql host object

  var $site;				//site object
  //var $page;				//page object
  //var $component;			//compentent object
    
  function destroy()
    {
      //$this->site->destroy();
      mysql_free_result($this->sql_host);
    }

  function pump($message)
    {
      global $HTTP_POST_VARS, $HTTP_SESSION_VARS; 

      switch($message->mode)
	{
	case "authorize":
	  switch($message->action)
	    {
	    case "login_form":
	      return TRUE;
	      break;
	    case "login":
	      if($HTTP_POST_VARS["f_user"] == "parasyte")
		{
		  //start a session
		  session_start();

		  // register some session variables
		  session_register("session_id");
		  session_register("session_date");
		  session_register("session_user_name");
		  session_register("session_count");

		  // set session variables
		  $HTTP_SESSION_VARS["session_count"] = 1;
		  $HTTP_SESSION_VARS["session_date"] = 0;
		  $HTTP_SESSION_VARS["session_id"] = session_id();
		  $HTTP_SESSION_VARS["session_user_name"] = $HTTP_POST_VARS["f_user"];
 
		  $message->mode = "page";
		  $message->action = "display";

		  $GLOBALS["authorized"] = TRUE;
		}
	      break;
	    case "logout":
	      $HTTP_SESSION_VARS["session_count"] = 0;
	      $HTTP_SESSION_VARS["session_date"] = 0;
	      $HTTP_SESSION_VARS["session_id"] = session_id();
	      $HTTP_SESSION_VARS["session_user_name"] = "";
		      
	      $message->mode = "page";
	      $message->action = "display";
	      break;
	    default:
	      break;
	    } //end action switch
	default:
	  if(!$GLOBALS["authorized"])
	    {
	      if($HTTP_SESSION_VARS["session_user_name"] == "parasyte")
		{
		  $GLOBALS["authorized"] = TRUE;
		}
	    }
	  break;
	} //end mode switch
      return TRUE;
    }
      
  function register_session()
    {
      global $HTTP_SESSION_VARS;

      session_start();
      session_register("session_id");
      session_register("session_date");
      session_register("session_user_name");
      session_register("session_count");
    }
	


	  
	  
}//end class
?>