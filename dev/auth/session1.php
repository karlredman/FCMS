<?php
session_register("count");

if(!$HTTP_SESSION_VARS["count"])
{
	echo "setting HTTP_SESSION_VARS...<BR>";
}

$HTTP_SESSION_VARS["count"]++;

?>

Hello visitor, you have seen this page <?php echo $HTTP_SESSION_VARS["count"]; ?> times.<p>

<php?
# the <?=SID?> is necessary to preserve the session id
# in the case that the user has disabled cookies
?>

To continue, <A HREF="session1.php?<?=SID?>">click here</A>


