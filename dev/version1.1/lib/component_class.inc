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

  function add($message, $ref_id, $type, $insert)
    {
      //NEEDS DATABASE LOCK HERE !!!

      //get last component (by ref_id)
      $query_str = "select * from component order by ref_id desc";
      
      if( ! $comp = mysql_query("$query_str") )
	error_quit("component_class", "select component", TRUE);

      if(! $compO = mysql_fetch_object($comp) )
	error_quit("component_class", "fetch component", TRUE);

      //add component
      if(!$insert)
	$ref_id = ($compO->ref_id+1);

      $query_str = "insert into component set page_id = $message->page_id, ".
	"ref_id = $ref_id, last_updated = now(), type = \"".$type."\", ".
	"title = \"New Component Title\"";

      
	if(! ($result = mysql_query($query_str)) )
	  error_quit("component_class", "add:component", TRUE);
	
	if(!$insert)
	  {
	    ////////////////////////////
	    $query_str = "select * from component order by ref_id desc";
	    
	    if(! ($result = mysql_query($query_str)) )
	      error_quit("component_class", "add:component", TRUE);
	    
	    if(! $compO = mysql_fetch_object($result) )
	      error_quit("component_class", "fetch component", TRUE);
	    
	    $message->component_id = $compO->id;
	    //////////////////////////////
	  }
	else
	  {
	    $message->component_id = mysql_insert_id();
	  }
	
    }

  function insert($message)
    {
      //get last component (by ref_id)
      $query_str = "select * from component order by ref_id";
      
      if( ! $comp = mysql_query("$query_str") )
	error_quit("component_class", "insert():select component", TRUE);

      if(! $compO = mysql_fetch_object($comp) )
	error_quit("component_class", "insert():fetch component", TRUE);


      //find this component, reorder the ref_id of each one
      //(inclusive)

      $go = 0;	//for scope
      $ref_id;

      do
	{
	  if($compO->id == $message->component_id)
	    {
	      $go = 1;
	      $ref_id = $compO->ref_id;
	    }

	  if($go)
	    {
	      $new_ref_id = $compO->ref_id+1;

	      $query_str="update component set ref_id=".$new_ref_id." ".
		"where id=".$compO->id;


	      if(! ($result = mysql_query($query_str)) )
		if(! ($result = mysql_query($query_str)) )
		  error_quit("component_class()", "insert():update", TRUE);
	    }
	} while($compO = mysql_fetch_object($comp));
      
      //add the new component (after setting message->component_id
      $this->add(&$message, $ref_id, "content", TRUE);
      
      return $ref_id;
      
    }

  function delete($message)
    {
      $query_str = "delete from component where id = $message->component_id";

      if(! ($result = mysql_query($query_str)) )
	error_quit("component_class", "add:component", TRUE);
    }
}
?>
