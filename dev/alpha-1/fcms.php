<?
//include functions from library
include("lib/libfcms.inc");

//initilize: connect to db and set variables 
fcms_init();

//set host and site headers
//do_host_header();
//do_site_header();


//hand off the functionality to the library based on $mode
fcms_run();

//insert footers (page, siteguide, host)
do_page_footer();
//do_site_footer();
//do_host_footer();
?>
