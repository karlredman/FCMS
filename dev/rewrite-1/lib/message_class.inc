<?
/* message_class.inc
 */

class message_class
{

  //variables in message (order is important !!)
  var $host_id;		//the host id (for this host/database)
  var $site_id;		//the site id (for this site)
  var $page_id;		//the fcms page id (for this site)
  var $referp_id;	//the refering fcms page id (for this site)
  var $component_id;	//id of component (for use in forms)
  var $mode;		//noun (i.e. site/page/component)
  var $action;		//verb (i.e. edit/display/save)


  //  var $item;		//context of text (i.e. page_header)
  //var $text;		//text of item (i.e. "My Page Header")

  function message_class($host_id, $site_id, 
			 $page_id, $referp_id,
			 $component_id,
			 $mode, $action)
    //$item, $text)
    {
      $this->host_id = $host_id;
      $this->site_id = $site_id;
      $this->page_id = $page_id;

      $this->referp_id = $referp_id;
      $this->component_id = $component_id;
      $this->mode = $mode;
      $this->action = $action;
      //$this->item = $item;
      //$this->text = $text;
    }

  function destroy()
    {}

}

?>
