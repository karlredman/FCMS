<?
function button_show_login($site_obj, $current_page_obj, $password_file)
{
  global $mode, $autherized, $login_image, $logout_image;

  if($mode == "login")
    return;

  if($autherized)
    $auth_image = "$logout_image";
  else
    $auth_image = "$login_image";

	  //////////////////// login buttons
  //  echo("<form    action=$password_file
  echo("<form action=\"$PHP_SELF\" METHOD=POST>
		<input  type=hidden
			name=site_id
			value=$site_obj->site_id>

		<input  type=hidden
		        name=id
			value=$current_page_obj->page_id>

		<input type=hidden
			name=mode
			value=login>

		<input  type=image
		        src=$auth_image>


		</form>");
	  //////////////////// login buttons
	  ////////////////////////////////////
}

function button_show_home($site_obj, $current_page_obj, $page_display_file)
{
  global $mode, $home_image; //FIX!

  //print(" <form    action=$page_display_file

  //value=$site_obj->homepage_id>
  //echo("<form action=\"$page_display_file\" METHOD=POST>

  if($site_obj->homepage_id != $current_page_obj->page_id ||
     strrpos($mode, "edit") )
  echo("<form action=\"$PHP_SELF\" METHOD=POST>
		<input  type=hidden
			name=site_id
			value=$site_obj->site_id>
		<input  type=hidden
		        name=id
			value=0>
		<input  type=hidden
		        name=referp_id
			value=$current_page_obj->page_id>
		<input  type=image
		        src=images/home.gif>
		</form>");
}

function button_show_back($site_obj, $current_page_obj, $referp_id, $code)
{
  //home page is reference 0 always - so no button

  global $global, $action_code;


  if($referp_id)
  echo("<form action=\"$PHP_SELF\" METHOD=POST>

		<input  type=hidden
			name=site_id
			value=$site_obj->site_id>

		<input  type=hidden
		        name=referp_id
			value=$current_page_obj->page_id>

		<input  type=hidden
		        name=id
			value=$referp_id>

		<input  type=hidden
		        name=mode
			value=$mode>

		<input  type=hidden
		        name=action_code
			value=$code>

		<input  type=image
		        src=images/back.gif>
		</form>      
	");
}

function button_show_edit($site_obj, $current_page_obj, $referp_id, $page_display_file)
{


  //home page is reference 0 always - so no button
  echo("<form action=\"$PHP_SELF\" METHOD=POST>
		<input  type=hidden
			name=site_id
			value=$site_obj->site_id>

		<input  type=hidden
		        name=referp_id
			value=$referp_id

		<input  type=hidden
		        name=id
			value=$current_page_obj->page_id>

		<input  type=hidden
		        name=mode
			value=edit_page>

		<input type=hidden
			name=action_code
			value=$action_code>

		<input  type=image
		        src=images/edit.gif>
		</form>      
	");
}
?>