<?
function insert_form_content_item($action, $new_mode, $image, $code)
{
  global $site_id, $id, $referp_id, $mode;
  global $content, $content_obj, $current_page_obj;

  echo("<form action=\"$action\" METHOD=POST>
		<input  type=hidden
			name=site_id
			value=$site_id>

		<input  type=hidden
		        name=id
			value=$id>

		<input  type=hidden
		        name=referp_id
			value=$referp_id>

		<input type=hidden
		        name=mode
			value=$new_mode>

		<input type=hidden
			name=action_code
			value=$code>

<font     size=1 color=#336666
                face=arial,helvetica>Content Heading</font><br>

<input type=text
	name=content_title
	value='$content_obj->title'
	size=40>
<br>

<font     size=1 color=#336666 face=arial,helvetica>Content Text</font><br>

<textarea    name=content_body
                cols=70
                rows=12
		wrap=virtual>$content_obj->body</textarea>
	");
  
  if($image)
    echo("<input  type=image src=$image>");

  if($action == "text")
    echo("
	");

//<hr>
//<font    size=$page_title_size><b>$content_title_1</b></font><p>

  print("</form>\n");
}

function insert_form_image($action, $new_mode, $image, $action_code)
{
  global $site_id, $id, $referp_id, $mode;

  if(!new_mode)
    $new_mode = $mode;

  if(!$action)
    $action = $PHP_SELF;

  echo("<form action=\"$action\" METHOD=POST>
		<input  type=hidden
			name=site_id
			value=$site_id>

		<input  type=hidden
		        name=id
			value=$id>

		<input  type=hidden
		        name=referp_id
			value=$referp_id>

		<input type=hidden
		        name=mode
			value=$new_mode>

		<input type=hidden
			name=action_code
			value=$action_code>

	");
  
  if($image)
    echo("<input  type=image src=$image>");

  if($action_code)
    {
      echo("
	<input type=hidden
		name=action_code
		value=$action_code
	");
    }

  print("</form>\n");
		

}

function insert_form_title($action, $new_mode, $image, $text)
{
  global $site_id, $id, $db, $referp_id, $mode;
  
  echo("<form action=\"$action\" METHOD=POST>
		<input  type=hidden
			name=site_id
			value=$site_id>

		<input  type=hidden
		        name=id
			value=$id>

		<input  type=hidden
		        name=referp_id
			value=$referp_id>

		<input type=hidden
		        name=mode
			value=$new_mode>

		<input type=hidden
			name=action_code
			value=$action_code>
	");
  
  if($image)
    echo("<input  type=image src=$image>");

  if($action == "text")
    echo("
<font     size=1 color=#336666 face=arial,helvetica>Page Title</font><p>
<input    type=text
                name=content_title
                value='$text'
                size=40><br>
	");

//<hr>
//<font    size=$page_title_size><b>$content_title_1</b></font><p>

  print("</form>\n");
}
?>