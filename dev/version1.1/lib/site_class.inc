<?

include_once("globals.inc");
include_once("supportFun.inc");

include_once("error.inc");

include("page_class.inc");
include("site_class_sup.inc");


class site_class
{
  var $sql_site;
  var $sql_site_obj;

  var $page;				//page object

  function site_class($message)
    { 

      //get site data
      if(! ($this->sql_site=mysql_query("select * from site where id = $message->site_id")) )
     	error_quit("mysql_query()", "site_class::():sql_site", TRUE );

      if(! ($this->sql_site_obj=mysql_fetch_object($this->sql_site)) ) 
	error_quit("mysql_fetch_object()", "site_class::():sql_site_obj", TRUE );

    }
  
  function run($message)
    {
      //handle site errors and such
      $this->pump(&$message);

      $obj = $this->sql_site_obj;
      //set default page if not set yet
      if(!$message->page_id)
	$message->page_id=$obj->$homepage_id;
      

      //do page stuff
      $this->page = new page_class(&$message, $obj->homepage_id);
    }


  function destroy()
    {
      $this->page->destroy();

      if($this->sql_site)
	mysql_free_result($this->sql_site);
    }

  function pump($message)
    { SC_pump(&$message); }

}//end class
?>
