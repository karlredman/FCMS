<?
/* navigation.inc
 */

function button_show_back($new_mode, $new_code)
{
  //home page is reference 0 always - so no button

  global $current_page_obj;
  global $back_image, $referp_id, $mode;
  global $alt_edit;

  //don't show button if there is no refering page
  if($referp_id)
    {
      if(strstr($mode, "edit"))
	{
	  if(strstr($mode, "edit_page"))// || $alt_edit) //edit_page
	    {
	      form_image_link(NULL, $current_page_obj->page_id, $referp_id,
			      "normal", $new_code, $back_image);
	    }
	  else
	    {
	      form_image_link(NULL, $current_page_obj->page_id, $referp_id,
			      "edit_page", $new_code, $back_image);
	    }
	}
      else
	{
	  form_image_link(NULL, $referp_id, $current_page_obj->page_id, 
			  $new_mode, $new_code, $back_image);
	}
  
    }
}

function button_show_home() 
{
  global $mode, $referp_id, $site_obj, $current_page_obj, $home_image, $page_id;

  
  //if( !strstr($mode, "edit") && ($site_obj->homepage_id != $current_page_obj->page_id) 
  if( !strstr($mode, "edit") && $page_id != $site_obj->homepage_id)
    {
      form_image_link(NULL, $site_obj->homepage_id, $current_page_obj->page_id,
		      "normal", NULL, $home_image);
    }
  else if(strstr($mode, "edit") && $site_obj->homepage_id == $current_page_obj->page_id)
    {
    form_image_link(NULL, $site_obj->homepage_id, $referp_id,
		    "normal", NULL, $home_image);
    }
}

function button_show_edit($new_mode, $new_action_code)
{
  global $site_obj, $edit_image;
  global $current_page_obj, $page_id, $referp_id, $mode, $action_code;

  if(!$new_mode)
    $new_mode=$mode;

  if(!$new_action_code)
    $new_action_code=$action_code;

  form_image_link(NULL, $current_page_obj->page_id, $referp_id,
		  $new_mode, $new_action_code, $edit_image);
  
}
?>