<?
function error_quit($function, $message, $quit)
{
  if($quit)
    print("ERROR: FATAL: ");
  else
    print("ERROR: NON FATAL: ");

  print("$function: $message");

  if($quit)
    exit;
}

function err_out($s)
{
  echo("
	<br>
	<b>
	$s	
	</b>
	<br>
	");
	
}

function e()
{
  err_out("GOT HERE");
}
?>
