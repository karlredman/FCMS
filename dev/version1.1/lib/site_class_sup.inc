<?
/* site_class_sup.inc
 */


function SC_pump($message, $site_obj)
{
  global $HTTP_SERVER_VARS, $HTTP_GET_VARS; 

  //handler server errors
  switch($HTTP_SERVER_VARS[REDIRECT_STATUS])
    {
    case "404":
      SC_handle_404(&$site_obj);
    break;
    }
  
  switch($HTTP_GET_VARS[error])
    {
    case "404":
      //this should pass the error to page !!!
      err_out("The page you requested was not found");
      exit;
      
      $message->mode = "error";
      $message->action = $HTTP_GET_VARS[error];
      //continue on to page lookup for errors, etc.
      break;
    }
}

function SC_handle_404($site_obj)
{
  global $HTTP_SERVER_VARS, $HTTP_GET_VARS; 
  //get array from redirect
      $redirect = explode("/", $HTTP_SERVER_VARS[REDIRECT_URL]);
      $len = sizeof($redirect)-1;
	  
      //set page_name if valid
      $page_name = explode(".", $redirect[$len]);
	  

      //validate page_name with possible *.html or *.html extension 
      // -should handle shtml and shtm in the future
      if( $page_name[1] != "html" && $page_name[1] != "htm")  
	{ 
	  //bad file name -use custom 404 handler 
	  header("Location: index.php?error=404?$redirect[$len]");
	  exit;
	}

      $query_str = "";

      //page_name is set, continue on.
      if($page_name[0] == "home" || $page_name[0] == "index")
	{
	  //redirect these to site home page (by directory)
	  if($HTTP_SERVER_VARS[REDIRECT_QUERY_STRING])
	    $query_str = "?".$HTTP_SERVER_VARS[REDIRECT_QUERY_STRING];
	}
      else 
	{
	  if($HTTP_SERVER_VARS[REDIRECT_QUERY_STRING])
	    $query_str = "?page_name=$page_name[0]&".
	      $HTTP_SERVER_VARS[REDIRECT_QUERY_STRING];
	  else
	    $query_str = "?page_name=$page_name[0]";
	}

      //transfer execution through the main pump again
      header("Location: index.php"."$query_str");
      //$site_obj->run();
      exit;
}
?>
