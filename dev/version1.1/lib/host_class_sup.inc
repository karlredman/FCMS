<?
/* host_class_sup.inc
 */



function HC_pump($message, $host_obj)
{
  global $HTTP_POST_VARS, $HTTP_SESSION_VARS; 

  switch($message->mode)
    {
    case "authorize":
      switch($message->action)
	{
	case "login_form":
	  //pass it on to the site (and then page)
	  return TRUE;
	  break;
	case "login":
	  //open user database and check for user info
	  if( ! ($this->sql_user= 
		 mysql_query("select * from users where user_name = ".
			     "$HTTP_POST_VARS[f_user] and password = ".
			     "$HTTP_POST_VARS[f_pass]")) )
	      { error_quit("mysql_query()", "host_class::():sql_user", TRUE ); }
		 
	  if(! ($this->sql_user_obj=mysql_fetch_object($this->sql_user)) ) 
	    error_quit("mysql_fetch_object()", "host_class::():sql_user_obj", TRUE );
	  
	  if($host_obj->sql_user_obj)
	    {
	      //start a session -erase the old one

	      $host_obj->register_session();

	      // set session variables -for new session
	      $HTTP_SESSION_VARS["session_count"] = 1;
	      $HTTP_SESSION_VARS["session_date"] = 0;
	      $HTTP_SESSION_VARS["session_id"] = session_id();
	      $HTTP_SESSION_VARS["session_user_name"] = $HTTP_POST_VARS["f_user"];
 
	      //setup message
	      $message->mode = "page";
	      $message->action = "display";
	      $message->user_name = $(host_obj->sql_user_obj)->user_name;
	      $message->security_level = $(host_obj->sql_user_obj)->user_name;
	    }
	  break;
	case "logout":
	  $HTTP_SESSION_VARS["session_count"] = 0;
	  $HTTP_SESSION_VARS["session_date"] = 0;
	  $HTTP_SESSION_VARS["session_id"] = session_id();
	  $HTTP_SESSION_VARS["session_user_name"] = "";
		      
	  $message->mode = "page";
	  $message->action = "display";
	  $message->user_name = "";
	  $message->security_level = 9; //lowest security
	  break;
	default:
	  break;
	} //end action switch
    default:
      //authenticate user from cookie (get by name and session id)
	  if( ! ($this->sql_user= 
		 mysql_query("select * from users where user_name = ".
			     "$HTTP_SESSION_VARS[session_user_name] and session_id = ".
			     "$HTTP_SESSION_VARS[session_id]")) )
	      { error_quit("mysql_query()", "host_class::():sql_user", TRUE ); }
		 
	  if(! ($this->sql_user_obj=mysql_fetch_object($this->sql_user)) ) 
	    error_quit("mysql_fetch_object()", "host_class::():sql_user_obj", TRUE );

      if($HTTP_SESSION_VARS[session_user_name] == $(host_obj->sql_user_obj)->user_name &&
	 $HTTP_SESSION_VARS[session_id] == $(host_obj->sql_user_obj)->session_id &&
	 $HTTP_SESSION_VARS[session_date] == $(host_obj->sql_user_obj)->session_date)
	{
	  //set message
	      $message->mode = "page";
	      $message->action = "display";
	      $message->user_name = $(host_obj->sql_user_obj)->user_name;
	      $message->security_level = $(host_obj->sql_user_obj)->user_name;

	      //update the session_date in the cookie and db
	      $date = 0;
	      $HTTP_SESSION_VARS[session_date] = date;
	      $query_str = "update users set session_date = $date ".
		"id = $(host_obj->sql_user_obj)->id";

	      if(! ($result = mysql_query($query_str)) )
		if(! ($result = mysql_query($query_str)) )
		  error_quit("host_class()", "pump():mysql_query():default", TRUE);
	}
      else
	{ //not authorized 
	}
      break;
    } //end mode switch
  return TRUE;
}

?>