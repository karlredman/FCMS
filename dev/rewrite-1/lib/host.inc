//include("globals.inc");
include("accessvars.inc");

include("db_class.inc");
include("site_class.inc");


class host_class 
{
  function host_class($host_id, $site_id)
    {
      //set id
      $this->$id = $host_id;

      //set database connection object
      $this->$db = $db;

      //get host data
     if(! ($this->sql_host=mysql_query("select * from site where site_id = $site_id")) )
     	error_quit("mysql_query()", "host_class::():site", TRUE );

     if(! ($this->$sql_host_obj=mysql_fetch_object($this->sql_host)) ) 
     	error_quit("mysql_fetch_object()", "host_class::():site_obj", TRUE );

      //$this->$site = new site_class($site_id);
    }


  global $fcms_host, $fcms_user, $fcms_passwd, $fcms_db_name;	//read only access
      
  var $id;				//id of host (passed in)

  var $db;				//database object
  var $sql_host;			//sql host row pointer
  var $sql_host_obj;			//sql host object

  var $site;				//site object
  //var $page;				//page object
  //var $component;			//compentent object
    

}