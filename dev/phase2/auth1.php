<?php
  function authenticate() {
    header( "WWW-Authenticate: Basic realm=\"Test Authentication System\"");
    header( "HTTP/1.0 401 Unauthorized");
    echo "You must enter a valid login ID and password to access this resource\n";
    exit;
  }
 
  if(!isset($PHP_AUTH_USER) || ($SeenBefore == 1 && !strcmp($OldAuth, $PHP_AUTH_USER)) ) {
   authenticate();
  } 
  else {
   echo "</p>Welcome: $PHP_AUTH_USER, $PHP_AUTH_PW<br>";
   echo "Old: $OldAuth, $OldPass";
   echo "<form action=\"$PHP_SELF\" METHOD=POST>\n";
   echo "<input type=\"hidden\" name=\"SeenBefore\" value=\"1\">\n";
   echo "<input type=\"hidden\" name=\"OldAuth\" value=\"$PHP_AUTH_USER\">\n";
   echo "<input type=\"hidden\" name=\"OldPass\" value=\"$PHP_AUTH_PW\">\n";
   echo "<input type=\"submit\" value=\"Re Authenticate\">\n";
   echo "</form></p>\n";
  }
?>
