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

}
?>
