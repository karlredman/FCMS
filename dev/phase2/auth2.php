<?php
  if(!isset($PHP_AUTH_USER)) {
    header("WWW-Authenticate: Basic realm=\"My Realm\"");
    header("HTTP/1.0 401 Unauthorized");
    echo "Text to send if user hits Cancel button\n";
    exit;
  } else {
    echo "<p>Hello $PHP_AUTH_USER.</p>";
    echo "<p>You entered $PHP_AUTH_PW as your password.</p>";
  }
?>
