<?
/* forms.inc
 */

function form_open($form_action)
{
  if(!$form_action)
    $form_action = $PHP_SELF;

  print("<form action=\"$form_action\" METHOD=POST>\n");
}

function form_std($host_id, $site_id, 
		  $new_page_id, $new_referp_id,
		  $component_id,
		  $new_mode, $new_action)
{
  print("
		<input  type=hidden
			name=host_id
			value=$host_id>\n

		<input  type=hidden
			name=site_id
			value=$site_id>\n

		<input  type=hidden
		        name=page_id
			value=$new_page_id>\n

		<input  type=hidden
		        name=referp_id
			value=$new_referp_id>\n

		<input  type=hidden
		        name=component_id
			value=$component_id>\n

		<input  type=hidden
		        name=mode
			value=$new_mode>\n

		<input  type=hidden
		        name=action
			value=$new_action>\n
	");
}

function form_add_textbox($name, $text, $size)
{
  
  print("
		<input  type=text
		        name=$name
			value=$text
			size=$size>\n
	");
}

function form_add_textarea($name, $text, $cols, $rows)
{
  if(!$cols)
    $cols = "50";

  if(!$rows)
    $rows = "12";

  print("
        <textarea    name=$name
                        cols=$cols
                        rows=$rows
                        wrap=virtual>$text</textarea>\n
	");
}

function form_add_submit_reset($submit_name)
{
  if(!$submit_name)
    $submit_name = "save";

  print("
        <input type=submit
                value=$submit_name>\n

        <input type=reset>\n
	");
}

function form_close()
{
  print("</form>\n");
}


function form_image_link($form_action,
			 $host_id, $site_id, 
			 $page_id, $referp_id,
			 $component_id,
			 $mode, $action,
			 $image_file)
{

  //used to create a button


  form_open($form_action);
  form_std( $host_id, $site_id, 
	    $page_id, $referp_id,
	    $component_id,
	    $mode, $action);

  print("<input  type=image
		src=$image_file>\n");    

  form_close();
}
?>
