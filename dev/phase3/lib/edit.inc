<?
/* edit.inc
 */

function edit_page_header($text)
{
  global $page_id, $mode, $action_code, $edit_image;
  
  form_open("text", NULL, NULL, "save_page_heading", NULL);
  echo("
	<font	size=1 color=#336666 face=arial,helvetica>Page Title</font><p>

	<input	type=text
                name=content_title
                value='$text'
                size=40><br>

	<input type=submit 
		value=save>

	<input type=reset>
	");

  form_close();
}

function edit_content_item($text)
{
  global $page_id, $mode, $action_code, $edit_image;
  global $content_obj;
  
  
  form_open("text", NULL, NULL, "save_content", $action_code);

  echo("
	<font     size=1 color=#336666
		face=arial,helvetica>Content Heading</font><br>



	<input type=text
		name=content_title
		value='$content_obj->title'
		size=30>
	<br>

	<font     size=1 color=#336666 face=arial,helvetica>Content Text</font><br>

	<textarea    name=content_body
	                cols=50
	                rows=12
			wrap=virtual>$content_obj->body</textarea>
	<br>
	<input type=submit 
		value=save>

	<input type=reset>
	");
  form_close();
}
?>
