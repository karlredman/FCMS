<?
//include functions from library
include("lib/libfcms.inc");

//initilize: connect to db and set variables 
fcms_init();

//hand off the functionality to the library based on $mode
fcms_run();

//insert a siteguide footer
do_page_footer();
?>
