<?
include_once("globals.inc");

include_once("message_class.inc");
include("host_class.inc");

function fcms_run()
{
  global $HTTP_GET_VARS, $HTTP_POST_VARS;

  if(!isset($GLOBALS["host_id"]) ||
     !isset($GLOBALS["site_id"]) )
    error_quit("fcms_run()", "There is something wrong with your configuration!", TRUE);

  //set variables -for scopeing
  $host;
  $db;
  $message;

  //connect to the database
  $db = new db_class();

  //get the page_id (could be !isset())
  if($HTTP_POST_VARS["page_id"])
    {
      //set message
      $message = new message_class($GLOBALS["host_id"], $GLOBALS["site_id"], 
			     $HTTP_POST_VARS["page_id"], 
			     $HTTP_POST_VARS["referp_id"],
			     $HTTP_POST_VARS["component_id"],
			     $HTTP_POST_VARS["mode"], $HTTP_POST_VARS["action"],
			     $HTTP_POST_VARS["item"], $HTTP_POST_VARS["text"]);


      //set host (and start message pumps)
      $host = new host_class(&$message);

    }
  else
    {
      
      if($GLOBALS["debug"])
	{
	  //DEBUG -turn this off for production !!!
	  $message = new message_class($GLOBALS["host_id"], $GLOBALS["site_id"],
				       $HTTP_GET_VARS["page_id"],
				       $HTTP_GET_VARS["referp_id"],
				       $HTTP_GET_VARS["component_id"],
				       $HTTP_GET_VARS["mode"], $HTTP_GET_VARS["action"],
				       $HTTP_GET_VARS["item"], $HTTP_GET_VARS["text"]);

	  $host = new host_class(&$message);
	}
      else
	{
	  //production operation mode
	  //set default page display message (the buttons will do the
	  //rest)
	  $message = new message_class($GLOBALS["host_id"], $GLOBALS["site_id"], 
				       $HTTP_GET_VARS["page_id"], 
				       $HTTP_GET_VARS["referp_id"],
				       NULL, "page", "display", NULL, NULL);

	  $host = new host_class(&$message);
	}
    }

  if($host)
    { $host->destroy(); }

  if($message)
    { $message->destroy(); }
     
  if($db)
    { $db->destroy(); }
}
?>