<?
/***************************************************************/
/*
 *
 ************** HTML PAGE FUNCTIONS
 *
*/

function html_begin()
{
  print("<HTML>\n");
}

function html_end()
{
  print("</HTML>\n");
}

function html_head_open($title)
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
?>