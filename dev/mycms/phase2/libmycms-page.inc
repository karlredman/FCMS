<?
/***************************************************************/
/*
 *
 ************** Theme Based Functions (Theme API)
 *
*/

function display_page_heading_by_theme($theme)
{
  global $site, $site_obj, $current_page, $current_page_obj, $content, $content_obj;
  global $edit_image;

  if(!$theme)
    { //do default theme below
    }

     //start page
     html_begin();
     
     //header
     html_head_open("$current_page_obj->page_title");
     html_head_close();
     
     //body
     html_body_open("$current_page_obj->body_color_fg", "$current_page_obj->body_color_bg", 
		    "$current_page_obj->body_image", "$current_page_obj->body_link", 
		    "$current_page_obj->vbody_link", "$current_page_obj->body_alink");

     //print the page heading


	 if($current_page_obj->title_align == "center")
	   echo("<center>");

     if($theme == "edit_page")
       {
	 
	 print("<table cellspacing=10> <tr> <td><H1>$current_page_obj->page_heading</H1></td> <td VALIGN=MIDDLE >");

	 insert_form_image(NULL, "edit_heading", $edit_image, NULL);

	 print("</td></table>\n");
       }
     else
       {

	 print("<H1>$current_page_obj->page_heading</H1><BR>\n");

       }
	 if($current_page_obj->title_align == "center")
	   echo("</center>");


}

function display_contents_by_page_type()
{
  //display contents based on the page->type from the database

  global $current_page_obj;

  display_contents_by_theme($current_page_obj->type);
}

function display_contents_by_theme($theme)
{
  //display contents based on an internal standerdized theme


  /*
	NOTE: Themes may be one of the following
	or your can write your own :)

	default = content-items are displayed straight down the page.

	noblocks = same as the 'default' theme

	doubled = a table is used to display 2 content-items per row.

	staggared = a table is used to display 2 content-items on
		even rows and 1 content-item on odd rows.
  */

  switch ($theme) {
  case "doubled":
    display_contents_doubled();
    break;
  case "staggared":
  case "staggared_reverse":
    display_contents_staggared("$theme");
    break;
  case "default":
  case "noblocks":
  default:
    display_contents_default();
    break;
  }
}

function display_contents_default()
{
  //display contents (default theme)

  global $mode, $edit_image, $content_obj, $content;

  if($mode == "edit_page")
    print("<table width=100%>\n");

  do{
    if($mode == "edit_page")
      print("<tr><td>\n");

    //display a content block
    show_content($content_obj);
    
    print("<br>\n");
    
    
    if($mode == "edit_page")
      {
	print("<td VALIGN=MIDDLE >\n");
	insert_form_image(NULL, "edit_content_item", $edit_image, $content_obj->content_id);
	print("</td></tr>\n");
      }
    else
    print("<td></tr>\n");

    if($debug)
      print("<hr>\n");

  } while($content_obj = mysql_fetch_object($content));

  if($mode == "edit_page")
    print("</table>\n");
  //print("<td VALIGN=MIDDLE ><img src=$edit_image></img></td></tr></table>\n");
}

function display_contents_doubled()
{
  //display contents (default theme)

  global $mode, $edit_image, $content_obj, $content;


  print("<table cellspacing=10 cellpadding=10 width=100%>\n");

  $col=1;

  do{


    if($col == 1)
      {
	print("<tr>\n");
      }

    //display a content block
    print("<td>\n");
    show_content($content_obj);
    print("</td>\n");

    if($mode == "edit_page")
      {
	//print("<td VALIGN=MIDDLE ><img src=$edit_image></img></td>\n");
	print("<td VALIGN=MIDDLE >\n");
	insert_form_image(NULL, "edit_content_item", $edit_image, $content_obj->content_id);
	print("</td>\n");
      }
    
    if($col == 2)
      {
	$col = 1;
	print("</tr>\n");
      }
    else
      {
	$col = 2;

      }

  } while($content_obj = mysql_fetch_object($content));

  print("</table>\n");

  if($debug)
    print("<hr>\n");
}

function display_contents_staggared($command)
{
  //display contents (default theme)
  /*
	$command can be:
		staggared = 2 content-items then one, then two, etc.
		staggared_reverse = 1 content-item then two, then one, etc.
  */

  global $mode, $edit_image, $content_obj, $content;


  //print("<table>\n");
  print("<table cellspacing=10 cellpadding=10 width=100%>\n");

  if($command == "staggared_reverse")
    $count = 2;
  else
    $count=1;

  $col=1;

  do{

    if($count%2)
      {
	//print two content-items
	if($col == 1)
	  print("<tr>\n");
	
	
	//display a content block
	print("<td>\n");
	show_content($content_obj);
	print("</td>\n");
	
	
	if($mode == "edit_page")
	  {
	    print("<td VALIGN=MIDDLE >\n");
	    insert_form_image(NULL, "edit_content_item", $edit_image, $content_obj->content_id);
	    print("</td>\n");
	  }

	if($col == 2)
	  {
	    print("</tr>\n");
	    $col = 1;
	    $count++;
	  }
	    else
	      {
		print("<td><td>\n");
		$col = 2;
	      }
      }
    else
      {
	//print one content-item
	print("<tr>\n");
	
	print("<td><td>\n");
	
	print("<td>\n");
	show_content($content_obj);
	print("</td>\n");
	
	if($mode == "edit_page")
	  {
	    print("<td VALIGN=MIDDLE >\n");
	    insert_form_image(NULL, "edit_content_item", $edit_image, $content_obj->content_id);
	    print("</td>\n");
	  }

	print("<td><td>\n");
	print("</tr>\n");

	$count++;
      }
    
	
  } while($content_obj = mysql_fetch_object($content));
    
  print("</table>\n");

  if($debug)
    print("<hr>\n");
}

function do_page_footer()
{
  global $site_obj, $current_page_obj, $referp_id, $page_display_file, $mode; 

  ///////////////// page footer
  echo("<br>");
  echo("<hr>");

print("<table>\n");
print("<tr>\n");

if(strrpos("edit", $mode))
  {
    print("<td>");
    button_show_back($site_obj, $current_page_obj, $referp_id, $action_code);
    print("</td>\n");
  }

print("<td>");
  button_show_home($site_obj, $current_page_obj, $page_display_file); 
print("</td>\n");

print("<td>");
  button_show_login($site_obj, $current_page_obj, $password_check_file); 
print("</td>\n");

 if($mode != "edit" && $mode != "edit_page" && 
    $mode != "login"&& $mode != "edit_content_item" &&
    $mode != "edit_heading")
   {
     print("<td>");
     button_show_edit($site_obj, $current_page_obj, $referp_id, $page_display_file); 
     print("</td>\n");
   }

print("</tr>\n");
print("</table>");

  //close body
  html_body_close();

  //close page
  html_end();
}

function show_content($content_obj)
{
  //display content title
  if($content_obj->title_align == "center")
    echo("<center>");
  
  echo("<font size=+$content_obj->title_font_size face=$content_obj->title_font_face> $content_obj->title </font>");
  
  if($content_obj->title_align == "center")
    echo("</center>\n");
  
  echo("<br>\n");
  
  //display content image

  //display content body
  if($content_obj->body_align == "center")
    echo("<center>\n");
  
	  
  echo("<font size=$content_obj->body_font_size face=$content_obj->body_font_face> $content_obj->body </font>\n");
  
  if($content_obj->body_align == "center")
    echo("</center>\n"); 
}

?>