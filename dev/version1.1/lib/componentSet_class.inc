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

      $obj = $component->sql_component_obj;

      switch ($obj->type)
	{
	case content:
	  $this->type_component = new content_component_class(&$message, &$component);
	  break;
	default:
	  break;
	}
    }

  function destroy()
    { }
}


?>