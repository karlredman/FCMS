<?
/* forms.inc
 */

function form_open($form_action, $new_page_id, $new_referp_id, $new_mode, $new_action_code)
{
  global $current_page_obj;

  global $site_obj;
  global $page_id, $referp_id, $mode, $action_code;
  
  if(!$formaction)
    $form_action = $PHP_SELF;

  if(!$new_mode)
    $new_mode = $mode;

  if(!$new_action_code)
    $new_action_code = $action_code;

  if(!$new_page_id)
    $new_page_id = $page_id;

  if(!$new_referp_id)
    $new_referp_id = $referp_id;
    
  print("
	<form action=\"$form_action\" METHOD=POST>
		<input  type=hidden
			name=site_id
			value=$site_obj->site_id>

		<input  type=hidden
		        name=referp_id
			value=$new_referp_id>

		<input  type=hidden
		        name=page_id
			value=$new_page_id>

		<input  type=hidden
		        name=mode
			value=$new_mode>

		<input  type=hidden
		        name=action_code
			value=$new_action_code>
	");
}

function form_close()
{
  print("\n</form>\n<br>\n");
}


function form_image_link($form_action, $new_page_id, $new_referp_id, 
			 $new_mode, $new_action_code, $image_file)
{
  form_open($form_action, $new_page_id, $new_referp_id, 
	    $new_mode, $new_action_code);
  echo("<input  type=image
		src=$image_file> ");    
  form_close();
}



?>
