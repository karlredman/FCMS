<?
/* mylib.inc
*/
?>

<?
##################################### GLOBAL DATA
//objects
$site;
$site_obj;
$current_page;
$current_page_obj;
$content;
$content_obj;

//access
$db_name="mycms";
$access_host="";
$access_user="root";
$access_password="eertwfld";

//images
$login_image="images/login";
$home_image="images/home.gif";

##################################### DATABASE FUNCTIONS

function db_connect()
{
  //declare globals
  global $db_name;
  global $access_host;
  global $access_user;
  global $access_password;

  $link = mysql_pconnect("$access_host", "$access_user", "$access_password");

  if($link && mysql_select_db($db_name))
    return $link;

  return(FALSE);
}

function db_get()
{
}

function db_put()
{
}

##################################### HTML PAGE FUNCTIONS

function html_begin()
{
  print("<HTML>\n");
}

function html_end()
{
  print("</HTML>\n");
}

function html_head_open($title, $header)
{
  print("<HEAD>\n");

  if($title)
    print("<TITLE>$title</TITLE>\n");
}

function html_head_close()
{
  print("</HEAD>\n");
}

function html_body_open($bg, $fg, $bg_img, $link, $vlink, $alink)
{
  print("<BODY ");

  if($bg)
    print("bgcolor=\"$bg\" ");

  if($fg)
    print("text=\"$fg\" ");

  if($bg_img)
    print("background=\"$bg_img\" ");

  if($link)
    print("link=\"$link\" ");

  if($vlink)
    print("vlink=\"$vlink\" ");

  if($alink)
    print("alink=\"$alink\" ");

  //end of body tag
  print(">\n");

  /*
    <body 
        bgcolor="#000000" 
	text="#FFFFFF"
        background="pix/watch.jpg" 
        link="#99FFFF" 
        vlink="#99CCFF" 
        alink="#99FFFF"
    >
  */
}


function html_body_close()
{
  print("</BODY>\n");
}


function error_quit($function, $message, $quit)
{
  if($quit)
    print("ERROR: FATAL: ");
  else
    print("ERROR: NON FATAL: ");

  print("$function: $message");

  if($quit)
    exit;
}

function get_homepage($host_id, $site_id, $database)
{
}

function button_show_login($site_obj, $current_page_obj)
{
  global $login_image;

	  //////////////////// login buttons
	  echo("<form    action=password_check.php
        	method=post>

		<input  type=hidden
			name=site_id
			value=$site_obj->site_id>

		<input  type=hidden
		        name=id
			value=$current_page_obj->page_id>

		<input  type=image
		        src=$login_image>


		</form>");
	  //////////////////// login buttons
	  ////////////////////////////////////
}

function button_show_home($site_obj, $current_page_obj)
{
  global $home_image;

  if($site_obj->homepage_id != $current_page_obj->page_id)
    print(" <form    action=test2.php
        	method=post>
		<input  type=hidden
			name=site_id
			value=$site_obj->site_id>
		<input  type=hidden
		        name=id
			value=$site_obj->homepage_id>
		<input  type=hidden
		        name=referid
			value=$current_page_obj->page_id>
		<input  type=image
		        src=images/home.gif>
		</form>");
}

//function button_show_back($site_obj, $current_page_obj)
function button_show_back($site_obj, $current_page_obj, $referid)
{
  if($referid)
    print("       
		<form    action=test2.php
        	method=post>
		<input  type=hidden
			name=site_id
			value=$site_obj->site_id>
		<input  type=hidden
		        name=referid
			value=$current_page_obj->page_id>
		<input  type=hidden
		        name=id
			value=$referid>
		<input  type=image
		        src=images/back.gif>
		</form>      
	");
}


function show_content($content_obj)
{
  //display content title
  if($content_obj->title_align == "center")
    echo("<center>");
  
  
  echo("<font size=+$content_obj->title_font_size 
			face=$content_obj->title_font_face>
			$content_obj->title
			</font>");
  
  if($content_obj->title_align == "center")
    echo("</center>");
  
  echo("<br>");
  
  //display content image

  //display content body
  if($content_obj->body_align == "center")
    echo("<center>");
  
	  
  echo("<font size=$content_obj->body_font_size 
			face=$content_obj->body_font_face>
			$content_obj->body
			</font>");
  
  if($content_obj->body_align == "center")
    echo("</center>");
  
}
?>
