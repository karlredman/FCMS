<?
/* componentSet_class.inc
 */

//class wraper to handle components

include("content_component_class.inc");

class componentSet_class
{
  var $component;
  var $type_component;

  function componentSet_class($message)
    {
      $this->component = new component_class(&$message);

      $obj = $this->component->sql_component_obj;

      switch ($obj->type)
	{
	case content:
	  $this->type_component = new content_component_class(&$message, &$this->component);
	  break;
	default:
	  break;
	}
    }

  function destroy()
    { 
      $this->type_component->destroy();
      $this->component->destroy();
    }

  function add($message)
    {
      //add a new component and open the page for edit
      //creates a content component by default
      
      //get last component (by ref_id)
      $query_str = "select * from component order by ref_id desc";
      
      if( ! $comp = mysql_query("$query_str") )
	error_quit("componentSet_class", "select component", TRUE);

      if(! $compO = mysql_fetch_object($comp) )
	error_quit("componentSet_class", "fetch component", TRUE);

      //add component
      $ref_id = ($compO->ref_id+1);

      $query_str = "insert into component set page_id = $message->page_id, ".
	"ref_id = $ref_id, last_updated = now(), type = \"content\", ".
	"title = \"New Component Title\"";
      
	if(! ($result = mysql_query($query_str)) )
	  error_quit("componentSet_class", "add:component", TRUE);


	$query_str = "select * from component order by ref_id desc";

	if(! ($result = mysql_query($query_str)) )
	  error_quit("componentSet_class", "add:component", TRUE);

	if(! $compO = mysql_fetch_object($result) )
	  error_quit("componentSet_class", "fetch component", TRUE);

	
	$message->component_id = $compO->id;

	//add content
	$query_str = "select * from content_component order by ref_id desc";
      
	if( ! $cont = mysql_query("$query_str") )
	  error_quit("componentSet_class", "select content", TRUE);

	if(! $contO = mysql_fetch_object($cont) )
	  error_quit("componentSet_class", "fetch content", TRUE);

	$query_str = "insert into content_component set page_id = $compO->page_id, ".
	  "component_id = $message->component_id, ref_id = $ref_id";

	if(! ($result = mysql_query($query_str)) )
	  error_quit("componentSet_class", "add:content", TRUE);

	//we'll go into component edit next
	$message->mode = "component";
	$message->action = "edit";

	//global $HTTP_POST_VARS;
	//$HTTP_POST_VARS["content_title"] = "New Component Title";
	//$HTTP_POST_VARS["content_body"] = "Some Sample Content Text";
	//$HTTP_POST_VARS["mode"] = $message->mode;
	//$HTTP_POST_VARS["action"] = $message->action;

	//$HTTP_POST_VARS["host_id"] = $message->host_id;
	//$HTTP_POST_VARS["site_id"] = $message->site_id;
	//$HTTP_POST_VARS["page_id"] = $message->page_id;
	//$HTTP_POST_VARS["referp_id"] = $message->referp_id;
	//$HTTP_POST_VARS["component_id"] = $message->component_id;
	}
}


?>