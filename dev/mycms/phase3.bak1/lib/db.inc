<?
/* db.inc
*/

function db_connect($host, $user, $password, $db_name)
{
  if(! ($link = mysql_connect($host, $user, $password)) )
     	error_quit("mysql_connect()", "db_connect():$db", TRUE );

  if(!$link || mysql_select_db($db_name))
    return $link;

  return(FALSE);
}


?>
