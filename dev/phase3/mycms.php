<?
//include functions from library
include("lib/libmycms.inc");

//initilize: connect to db and set variables 
mycms_init();

//hand off the functionality to the library based on $mode
mycms_run();

//insert a siteguide footer
do_page_footer();
?>
