<?
include_once("globals.inc");
include_once("error.inc");

include_once("supportFun.inc");

class component_class
{
  var $sql_component;
  var $sql_component_obj;


  function init($message)
    {
      //get component data
      if(! ($this->sql_component=
	    mysql_query("select * from component where page_id = $message->page_id ".
			"order by ref_id")) )
	{
	  error_quit("mysql_query()", "component_class::():sql_component", TRUE );
	}

      unset($sql_component_obj);
      //$message->dump();
      if(! ($this->sql_component_obj=mysql_fetch_object($this->sql_component)) ) 
	error_quit("mysql_fetch_object()", "component_class::():sql_component_obj", TRUE );
    }

  function component_class($message)
    { 
      //get component data
      $this->init(&$message);
    }

  function destroy()
    {
      if($this->sql_component)
	mysql_free_result($this->sql_component);
    }

  function add($message, $ref_id, $type)
    {
      //NEEDS DATABASE LOCK HERE !!!

      //get last component (by ref_id)
      $query_str = "select * from component order by ref_id desc";
      
      if( ! $comp = mysql_query("$query_str") )
	error_quit("component_class", "select component", TRUE);

      if(! $compO = mysql_fetch_object($comp) )
	error_quit("component_class", "fetch component", TRUE);

      //add component
      $ref_id = ($compO->ref_id+1);

      $query_str = "insert into component set page_id = $message->page_id, ".
	"ref_id = $ref_id, last_updated = now(), type = \"".$type."\", ".
	"title = \"New Component Title\"";
      
	if(! ($result = mysql_query($query_str)) )
	  error_quit("component_class", "add:component", TRUE);
	
	$query_str = "select * from component order by ref_id desc";
	
	if(! ($result = mysql_query($query_str)) )
	  error_quit("component_class", "add:component", TRUE);

	if(! $compO = mysql_fetch_object($result) )
	  error_quit("component_class", "fetch component", TRUE);

	$message->component_id = $compO->id;
    }

  function delete($message)
    {
      $query_str = "delete from component where id = $message->component_id";

      if(! ($result = mysql_query($query_str)) )
	error_quit("component_class", "add:component", TRUE);
    }
}
?>
