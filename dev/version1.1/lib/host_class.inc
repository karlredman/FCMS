<?

include_once("globals.inc");
include_once("error.inc");

include_once("accessvars.inc");

include_once("db_class.inc");
include_once("site_class.inc");
include_once("host_class_sup.inc");



class host_class 
{
  var $db_link;				//database link

  var $sql_host;			//sql host row pointer
  var $sql_host_obj;			//sql host object

  var $sql_user;			//sql user row pointer
  var $sql_user_obj;			//sql user object

  var $site;				//site object

  function host_class($message)
    {
      //register session data
      if($message->mode != "authorize")
	$this->register_session();

      //get host data
      if(! ($this->sql_host=mysql_query("select * from host where id = $this->id")) )
     	error_quit("mysql_query()", "host_class::():sql_host", TRUE );

      if(! ($this->sql_host_obj=mysql_fetch_object($this->sql_host)) ) 
	error_quit("mysql_fetch_object()", "host_class::():sql_host_obj", TRUE );

      //create a new site object so we can check site variables
      $this->site = new site_class(&$message);

      //if the pump says pass it on, then do so
      if($this->pump(&$message, &$this))
	{
	  $this->site->run(&$message);
	}
    }

  function destroy()
    {
      //$this->site->destroy();
      mysql_free_result($this->sql_host);
    }

  function pump($message)
    { HC_pump(&$message); }
      
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
