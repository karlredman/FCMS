<?
// index.php - login form

session_register("SESSION");
session_register("LOGGEDIN");
session_register("ID");
session_register("SESSION_UNAME");

if($HTTP_SESSION_VARS["LOGGEDIN"])
	{
		//if($HTTP_SESSION_VARS["ID"] == ($sid = session_id()) )
		{
			print("You are logged in<br>\n");
			print("Your session ID is: $SID | $GLOBALS[SID] | $sid | $HTTP_SESSION_VARS[ID]<p>");
			print("Hello $HTTP_SESSION_VARS[SESSION_UNAME], ".
				"you have seen this page $HTTP_SESSION_VARS[SESSION] times.<p>");

			$HTTP_SESSION_VARS["SESSION"]++;
		}
	}
?>

<html>
<head>
<basefont face="Verdana">
</head>

<body>

<center>
<table border="0" cellspacing="5" cellpadding="5">
<form action="index.php" method="POST">
<tr>
        <td>Username</td>
        <td><input type="text" size="10" name="f_user"></td>
</tr>
<tr>
        <td>Password</td>
        <td><input type="password" size="10" name="f_pass"></td>
</tr>
<tr>
        <td colspan="2" align="center"><input type="submit"
name="submit" value="Log In"></td> </tr> </form> </table> </center>

<br>
To continue, <A HREF="index.php?<?=SID?>">click here</A>
</body>
</html>
