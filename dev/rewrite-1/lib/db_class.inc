<?
class db_class
{
  function db_class()
    {
      if(! ($this->$connection = $this->db_connect($GLOBALS["fcm_host"], 
						   $GLOBALS["fcms_user"],
						   $GLOBALS["fcms_passwd"], 
						   $GLOBALS["fcms_db_name"])))
        {
	  error_quit("db_connect()", "get_page_data()", TRUE);
        }

      if(! ($sql_host=mysql_query("select * from host where host_id = 1", $this->$connection)) )
	err_out("mysql_query()". "host_class::():sql_host". TRUE );

     if(! ($sql_host_obj=mysql_fetch_object($sql_host)) ) 
     err_out("mysql_fetch_object()". "host_class::():sql_host_obj". TRUE );
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