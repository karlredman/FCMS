<?
	class x
	{
		function x($i)
		{
			$this->n = $i;
			$i++;
			$this->o();
		}
		function o()
		{
			print("this->n = $this->n\n");
		}
	}

	$k = 0;
	
	$c1 = new x(&$k);
	print("k = $k");

	$c2 = new x(&$k);
	print("k = $k");

	$c1 = new x(9);
	print("k = $k");
?>
