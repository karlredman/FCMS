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

      $ref_id;
      
      //add component
      $this->component->add(&$message, &$ref_id, "content");
      
      //add content
      $this->type_component->add(&$message, $ref_id);

      //we'll go into component edit next
      $message->mode = "component";
      $message->action = "edit";
    }
  
  function delete($message)
    {
      //delete component
      $this->component->delete(&$message);

      //delete type_component
      $this->type_component->delete(&$message);

      //back to page edit mode
      $message->mode = "page";
      $message->action = "edit";
      $message->component_id = "";
    }
}


?>