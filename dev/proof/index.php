<? 
$db_name="mycms";
$access_user="root";
$access_password="eertwfld";

$host_id=1;
$site_id=1;

//echo("
//<HTML><HEAD><TITLE>FRED</TITLE></HEAD>
//<h1>THIS AND THAT</H1>
//");

//++FIGURE OUT BROWSER TYPE

//++SET BROWSER OPTIONS OR REDIRECTS

//++DISPLAY PRE-PAGE LAYOUT STUFF (frames, etc)

//DISPLAY SITE PAGE 0
$htmlredirect="page-display.php";
if (file_exists($htmlredirect)) 
	include ($htmlredirect);

//echo ("</html>");
exit;
?>
