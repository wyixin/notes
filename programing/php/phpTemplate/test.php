<?php
include "Template.php";

$str = "<h1>{data}</h1><div>{vb}";
$php_var_reg = "#\{([a-zA-Z_][a-zA-Z0-9_]*)\}#im";
$php_var = preg_replace($php_var_reg, "<?php echo \$$1;?>",$str);
//var_dump($php_var);
//die();

$tpl = Template::getInstance();
$tpl->show('data');
