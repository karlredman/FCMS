<?
/* display.inc
 */

function display_page_heading($title)
{
  global $site, $site_obj, $current_page, $current_page_obj, $content, $content_obj;
  global $edit_image, $mode;

  //start page
  html_begin();
     
  //header
  if(!$title)
    {
      $title = $current_page_obj->page_title;
      $do_edit = 1;
    }


  html_head_open("$title");
  html_head_close();
     
  //body
  html_body_open("$current_page_obj->body_color_fg", "$current_page_obj->body_color_bg", 
		 "$current_page_obj->body_image", "$current_page_obj->body_link", 
		 "$current_page_obj->vbody_link", "$current_page_obj->body_alink");

  //print the page heading


  if($current_page_obj->title_align == "center")
    echo("<center>");

    if($mode == "edit_page")
    {
      print("<table cellspacing=10> <tr> \n");
      print("<td><H1>$current_page_obj->page_heading</H1></td> ");
      print("<td VALIGN=MIDDLE >");
      //insert_form_image(NULL, "edit_heading", $edit_image, NULL);
      button_show_edit("edit_heading", $action_code);
      print("</td> </table>\n");
    }
  else
    {
	if($do_edit && $mode == "edit_heading")
	  {
	    print("<H1>$current_page_obj->page_heading</H1><BR>\n");
	    edit_page_header($current_page_obj->page_heading);
	  }
	else
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


?>