<?

include("page_class.inc");

class site_class
{
  function site_class($id, $page_id)
    { 
      $this->id = $id; 

      //get site data
     if(! ($this->sql_site=mysql_query("select * from site where site_id = $this->id")) )
     	error_quit("mysql_query()", "site_class::():sql_site", TRUE );

     if(! ($this->sql_site_obj=mysql_fetch_object($this->sql_site)) ) 
       error_quit("mysql_fetch_object()", "site_class::():sql_site_obj", TRUE );

     if(!$page_id)
     $page_id=$this->sql_site_obj->homepage_id;

     $this->page = new page_class($id, $page_id) ;
     
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