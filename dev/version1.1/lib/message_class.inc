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

  var $security_level;	//security level of user
  var $user_name;

  var $again;		//recursion used at the page level
  

  //  var $item;		//context of text (i.e. page_header)
  //var $text;		//text of item (i.e. "My Page Header")

  function message_class($host_id, $site_id, 
			 $page_id, $referp_id,
			 $component_id,
			 $mode, $action,
			 $security_level,
			 $user_name, 
			 $again)
    //$item, $text)
    {
      $this->host_id = $host_id;
      $this->site_id = $site_id;
      $this->page_id = $page_id;

      $this->referp_id = $referp_id;
      $this->component_id = $component_id;
      $this->mode = $mode;
      $this->action = $action;


      if(!$security_level)
	$this->security_level = 9; //lowest security level

      $this->user_name = $user_name;

      //always set again to FALSE 
      $this->again = FALSE;
    }

  function destroy()
    {}

  function dump()
    {
      print("<br>\n
      host_id = $this->host_id, <br>\n
	site_id = $this->site_id, <br>\n
	page_id = $this->page_id, <br>\n
	referp_id= $this->referp_id, <br>\n
	component_id= $this->component_id, <br>\n
	mode = $this->mode, <br>\n
	action= $this->action, <br>\n
	security_level= $this->security_level, <br>\n
	user_name= $this->user_name.<br>\n
<br>\n");
	}
}

?>
