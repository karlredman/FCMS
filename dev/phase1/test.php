<?
$host_id=1;
$site_id=1;

//include functions from library
include("mylib.inc");

//connect to database
if(! ($db = db_connect()) )
  error_quit("db_connect()", "from main", TRUE );

//start page
html_begin();

//header
html_head_open("MyTitle", "Myheading");
html_head_close();

//body
html_body_open("#FFFFFF", "#000000", "pix/watch.jpg", "#99FFFF", "#99CCFF", "#99FFFF");

print("Here is some text\n");

html_body_close();


//close page
html_end();
