<?
/* message_class.inc
 */

class message_class
{

  //variables in message (order is important !!)
  var $host_id;
  var $site_id;
  var $page_id;
  var $referp_id;
  var $component_id;
  var $mode;
  var $action;
  var $item;
  var $text;

  function message_class($host_id, $site_id, 
		   $page_id, $referp_id,
		   $component_id,
		   $mode, $action,
		   $item, $text)
    {
      $this->host_id = $host_id;
      $this->site_id = $site_id;
      $this->page_id = $page_id;

      $this->referp_id = $referp_id;
      $this->component_id = $component_id;
      $this->mode = $mode;
      $this->action = $action;
      $this->item = $item;
      $this->text = $text;
    }

  function destroy()
    {}

}

?>
