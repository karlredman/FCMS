<?

include_once("globals.inc");
include_once("error.inc");

include_once("supportFun.inc");

include_once("componentSet_class.inc");
include_once("page_class_sup.inc");

class page_class
{

  var $sql_page;
  var $sql_page_obj;
  
  var $componentSet;
  var $homepage_id;


  function page_class($message, $homepage)
    { 
      global $HTTP_POST_VARS, $HTTP_GET_VARS;

      $this->homepage_id = $homepage;

      //get page data
      if($HTTP_GET_VARS[page_name] && !$HTTP_POST_VARS[mode])
	{
	  //use page name for display instead

	  //if( ($this->sql_page=mysql_query("select * from page where file_name = ".
					   //"\"$HTTP_GET_VARS[page_name]\"")) )

	  ///bug !!! quick fix here !!!
	  $thing = explode("\"", $HTTP_GET_VARS[page_name]);
	  $x = $thing[1];

	  if(!$x)
	    $x=$thing[0];

	  err_out("page name =                    <br> ".$x);

	  if(! ($this->sql_page=mysql_query("select * from page where file_name = ".
					    "'$x'")) )
	    //"'".$HTTP_GET_VARS[page_name]."'")) )
	    error_quit("mysql_query()", "site_class::():sql_page_trans", TRUE );

	  $message->mode = "page";
	  $message->action = "display";

	  if($HTTP_GET_VARS[referp_id])
	    $message->referp_id = $HTTP_GET_VARS[referp_id];

	  //if( !$this->sql_page_obj=mysql_fetch_row($this->sql_page))
	    //{
	  if(! ($this->sql_page_obj=mysql_fetch_object($this->sql_page)) ) 
	    {
	      err_out("got here:".$this->sql_page_obj[0].":".$HTTP_GET_VARS[page_name]);
	      //$message->dump();
	      error_quit("mysql_fetch_object()", "page_class::():sql_page_obj", TRUE );
	      exit;
	    }
	  else
	    $message->page_id = $this->sql_page_obj->id;

	  //set for a redirect (for bookmarkable pages)
	  //handles back button problems too

	}
      else 
	{
	  if(!$message->page_id)
	    $message->page_id = $homepage;

	  $thing = explode("\"", $message->page_id);
	  $message->page_id = $thing[0];
	  err_out("select * from page "."where id = ".$message->page_id);

	  if(! ($this->sql_page=mysql_query("select * from page ".
					    "where id = ".$message->page_id)) )
	    { error_quit("mysql_query()", "page_class::():sql_page", TRUE ); }
	  
	  if(! ($this->sql_page_obj=mysql_fetch_object($this->sql_page)) ) 
	    error_quit("mysql_fetch_object()", "page_class::():sql_page_obj", TRUE );
	}

      //set default mode if not set yet
      if(!$message->mode)
	{
	  $message->mode = "page";
	  $message->action = "display";
	}
      
      //pump
      $message->again = FALSE;
      do {
	$this->pump(&$message);
      } while($message->again);
      
      $this->show_navigation(&$message);
      
      if($GLOBALS[debug])
	$message->dump();

     //shutdown

     //close body
     html_body_close();
     
     //close page
     html_end();

    }
  
  function destroy()
    { 
      if($this->sql_page)
	mysql_free_result($this->sql_page); 
    }

  
  function display_contents_by_theme($message, $theme) 
    { PC_display_contents_by_theme(&$message, $theme, &$this); }

  
  function display_contents_by_page_type($message)
    {
      //display contents based on the page->type from the database
      
      $obj = $this->sql_page_obj;
      $this->display_contents_by_theme(&$message, $obj->type);
    }

  function pump($message)
    { return(PC_pump(&$message, &$this)); }


  function show_navigation($message)
    { 
      PC_show_navigation(&$message, $this->homepage_id); 
    }

  function add($message)
    {
      //save the referp_id (for later use);
      //referp_id = $message->referp_id;

      //add a page to the database

      //get last page
      $query_str = "select * from page where site_id = ".
	$message->site_id." order by ref_id desc";

      if( ! $p = mysql_query("$query_str") )
	error_quit("page_class", "add():select page", TRUE);

      if(! $pO = mysql_fetch_object($p) )
	error_quit("page_class", "add():fetch page", TRUE);

      $ref_id = ($pO->ref_id+1);
      
      $query_str = "insert into page set ".
	" ref_id = ".$ref_id.",".
	" parent = ".$pO->ref_id;
	//" last_updated = 0".","

      err_out(" ref_id = ".$ref_id." parent = ".$pO->ref_id);

	if(! ($result = mysql_query($query_str)) )
	  error_quit("page_class", "add():insert page", TRUE);

	$message->page_id = mysql_insert_id();
	

      //add a component to the database
      $this->componentSet->add(&$message);

      //if($GLOBALS[debug])
	//$message->dump();
      
      //set message
      //$message->mode= "page";
      //$message->action = "admin";
    }


}// end page_class
?>
