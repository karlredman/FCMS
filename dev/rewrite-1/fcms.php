<?
include("lib/host_class.inc");

$db = new db_class();

$host = new host_class(1, 1, $HTTP_GET_VARS["page_id"]);
//$host = new host_class(1, 1, $HTTP_POST_VARS["page_id"]);

$host->destroy();

//$site = new site_class(1);
     
?>