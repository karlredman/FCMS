<?

// login.php - performs validation 

// authenticate using form variables
$status = authenticate($HTTP_POST_VARS["f_user"], $HTTP_POST_VARS["f_pass"]);

// if  user/pass combination is correct
if ($status == 1)
{
        // initiate a session
        session_start();
        
        // register some session variables
        session_register("LOGGEDIN");
        session_register("SESSION");
        session_register("ID");
        session_register("SESSION_UNAME");

	$HTTP_SESSION_VARS["SESSION"] = 1;
	$HTTP_SESSION_VARS["LOGGEDIN"] = 1;
	$HTTP_SESSION_VARS["ID"] = session_id();
        $HTTP_SESSION_VARS["SESSION_UNAME"] = $HTTP_POST_VARS["f_user"];

	//kill password field
//	$HTTP_POST_VARS["f_pass"] = "";
        
        // redirect to protected page
        header("Location: index.php");
        exit();
}
else
// user/pass check failed
{
        // redirect to error page
	session_start();

	$HTTP_SESSION_VARS["LOGGEDIN"] = 0;
	$HTTP_SESSION_VARS["SESSION"] = 0;
	$HTTP_SESSION_VARS["ID"] = 0;
	$HTTP_SESSION_VARS["SESSION_UNAME"] = "";

	header("Location: index.php");
        exit();
}


// authenticate username/password against /etc/passwd
// returns: -1 if user does not exist
//           0 if user exists but password is incorrect
//           1 if username and password are correct
function authenticate($user, $pass)
{
        $result = -1;

        // make sure that the script has permission to read this file!
        $data = file("passwd");

        // iterate through file
        foreach ($data as $line)
        {
                $arr = explode(":", $line);

                // if username matches password
                if ($arr[0] == $user)
                {
                        //if ($arr[1] == crypt($pass, $salt))
			if($arr[1] == $pass)
                        {
                        	// if match, user/pass combination is correct return 1
                                $result = 1;
                                break;
                        }
                        // otherwise return 0
                        else
                        {
                                $result = 0;
                                break;
                        }
                }

        }
        // return value
        return $result;
}

?>
