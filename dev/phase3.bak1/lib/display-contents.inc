<?
/* display-contents.inc 
 */

function display_contents_default()
{
  //display contents (default theme)

  global $mode, $alt_edit, $edit_image, $content_obj, $content;
  global $content_id, $action_code;
  
  
  if($mode == "edit_page")
    print("<table width=100%>\n");
  
  do{
    if($mode == "edit_page")
      print("<tr><td>\n");
    
    show_content($content_obj);
    
    print("<br>\n");
    
    
      if($mode == "edit_page")
      {
	print("<td VALIGN=MIDDLE >\n");
	//insert_form_image(NULL, "edit_content_item", $edit_image, $content_obj->content_id);
	button_show_edit("edit_content_item", $content_obj->content_id);
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
	//insert_form_image(NULL, "edit_content_item", $edit_image, $content_obj->content_id);
	button_show_edit("edit_content_item", $content_obj->content_id);
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
	    //insert_form_image(NULL, "edit_content_item", $edit_image, $content_obj->content_id);
	    button_show_edit("edit_content_item", $content_obj->content_id);
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
	    //insert_form_image(NULL, "edit_content_item", $edit_image, $content_obj->content_id);
	    button_show_edit("edit_content_item", $content_obj->content_id);
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
  
	  
    //if($alt_edit && strstr($mode, "edit") && $action_code == $content_obj->content_id)
  global $alt_edit, $mode, $action_code; 
  if($alt_edit && strstr($mode, "edit_content_item") && 
     $action_code == $content_obj->content_id) 
    {
      edit_content_item($content_obj->title, $content_obj->body);
    }
  else
    echo("<font size=$content_obj->body_font_size face=$content_obj->body_font_face> $content_obj->body </font>\n");
  
  if($content_obj->body_align == "center")
    echo("</center>\n"); 
}
?>