<?
/* test.pnp
 */

include("lib/accessvars.inc");
include("lib/error.inc");



class one
{
  function one($db)
    {
      $site_id = 1;


      if(! ($site=mysql_query("select * from site where site_id = \"$site_id\"")) )
        error_quit("mysql_query()", "common_db_connect():site", TRUE );

      if(! ($site_obj=mysql_fetch_object($site)) )
        error_quit("mysql_fetch_object()", "common_db_connect():site_obj", TRUE );
 
      print("site_obj->homepage_id = $site_obj->homepage_id\n<br>");


      $my_two = new two(&$db);
    }


}

class two
{
  function two()
    {
      $q_str = "select * from content where page_id=1 and ref_id=2";

      if(! ($content=mysql_query($q_str)) )
        error_quit("mysql_query()", "common_db_connect():site", TRUE );

      if(! ($content_obj=mysql_fetch_object($content)) )
        error_quit("mysql_fetch_object()", "common_db_connect():site_obj", TRUE );

      print("content_obj->body = <br>$content_obj->body\n<br>");
    }
      


}

class db
{
  function db()
    {
      //connect to the database
      if(! ($db = $this->db_connect($GLOBALS["fcm_host"], $GLOBALS["fcms_user"], 
					$GLOBALS["fcms_passwd"], $GLOBALS["fcms_db_name"])))
	{
		err_out("test");
		//err_out(GLOBAL[fcm_host]);
		err_out($GLOBAL);
//print($GLOBALS["fcms_user"]."<br>\n");
//print(php_info(INFO_ALL));

//echo phpinfo();
		error_quit("db_connect()", "get_page_data()", TRUE);
	}
    }

  function db_connect($host, $user, $password, $db_name)
    {
      if(! ($link = mysql_pconnect($host, $user, $password)) )
        error_quit("mysql_connect()", "db_connect():$db", TRUE );
      
      if(!$link || mysql_select_db($db_name))
	return $link;
      
      return(FALSE);
    }

}

///main


$my_db = new db();
$my_one = new one(&$my_db);

//$my_two = new two(&$my_db);



