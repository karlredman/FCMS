<?

include_once("globals.inc");
include_once("error.inc");

class db_class
{
  function db_class()
    {
      if(! ($this->connection = $this->db_connect($GLOBALS["fcm_host"], 
						   $GLOBALS["fcms_user"],
						   $GLOBALS["fcms_passwd"], 
						   $GLOBALS["fcms_db_name"])))
        {
	  error_quit("db_connect()", "get_page_data()", TRUE);
        }
    }

  function destroy()
    {
      mysql_close($this->connection);
    }

  function db_connect($host, $user, $password, $db_name)
    {
      if(! ($link = mysql_pconnect($host, $user, $password)) )
        error_quit("mysql_connect()", "db_connect():$db", TRUE );
      
      if(!$link || mysql_select_db($db_name))
        return $link;
      
      return(FALSE);
    }

  var $connection;
}

?>
