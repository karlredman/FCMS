<?

include_once("globals.inc");
include_once("error.inc");

include("page_class.inc");

class site_class
{
  function site_class($message)
    { 
      $this->id = $message->site_id; 

      //get site data
     if(! ($this->sql_site=mysql_query("select * from site where site_id = $this->id")) )
     	error_quit("mysql_query()", "site_class::():sql_site", TRUE );

     if(! ($this->sql_site_obj=mysql_fetch_object($this->sql_site)) ) 
       error_quit("mysql_fetch_object()", "site_class::():sql_site_obj", TRUE );

     //setup default stuff for message variables
     if(!$message->page_id)
       $message->page_id=$this->sql_site_obj->homepage_id;

     if(!$message->mode)
	$message->mode = "page";

      if(!$message->action)
	$message->action = "display";

      $this->page = new page_class(&$message);
     
     //$thing = $this->sql_site_obj;
     //print("sql_site_obj->homepage_id = $thing->homepage_id<br>\n");
    }

  var $sql_site;
  var $sql_site_obj;

  
  var $id;				//site id
  var $page;

  function destroy()
    {
      $this->page->destroy();
      mysql_free_result($this->sql_site);
    }
}
?>