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
      //set id
      $this->id = $message->host_id;

      //get host data
     if(! ($this->sql_host=mysql_query("select * from host where host_id = $this->id")) )
     	error_quit("mysql_query()", "host_class::():sql_host", TRUE );

     if(! ($this->sql_host_obj=mysql_fetch_object($this->sql_host)) ) 
       error_quit("mysql_fetch_object()", "host_class::():sql_host_obj", TRUE );

     $this->site = new site_class(&$message);
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
      $this->site->destroy();
      mysql_free_result($this->sql_host);
    }

}
?>