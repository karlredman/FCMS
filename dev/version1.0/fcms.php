<?
/* NOTE:
	0nly this file should be in your website directory (i.e. public_html).
	everything else (except maybe the images directory) should go into
	some directory that is not accessable from a browser -otherwise
	people will be able to browse the source code and stuff.

	And actually, you should keep this file away from the public_html
	directory as well and just include it from your index.php file.
*/


// Edit these for paths (absolute or relative to fcms.php directory)
$fcms_base_path="/home/parasyte/sandbox/Ankh/fcms/dev/version1.0";
$fcms_lib_path="$fcms_base_path/lib";
$fcms_images_path="images";

// Run fcms program
include("$fcms_lib_path/fcms.inc");
fcms_run();
?>
