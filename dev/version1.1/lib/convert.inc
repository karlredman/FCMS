<?
/* convert.inc
 */

function txt2html($text)
{
    $xchange = array
        (
        "\r"    => '',
        "\n"    => '<br />',
        '  '    => '&nbsp; ',
	//  '<'        => '&lt;',
        //'>'        => '&gt;',
	'\\'	   => '\\\\',
        '"'        => '&quot;',
        '!'        => '&#33;',
        '#'        => '&#35;',
        '$'        => '&#36;',
        '%'        => '&#37;',
        '&'        => '&amp;',
        '?'        => '&#63;',
        '@'        => '&#64;',
	'\''	   => "'"
        );
    return strtr($text, $xchange);
}

function save_txt($text)
{
  //take care of double quotes
  $text = str_replace('"','\"', $text); 
  $text = str_replace('\'','\\\'', $text); 

  //$text = str_replace("\\","\\\\", $text); 
  //$text = str_replace('\\',"\\\\", $text); 
  //'\\'	   => '\\\\',
  
  return($text);
}
?>
