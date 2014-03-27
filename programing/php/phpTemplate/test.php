<?php
include "Template.php";
include "../utils/utils.php";

$tpl = Template::getInstance();
$tpl->setConfig(array('debug' => true));
$tpl->show('data');

die();

$str = "a === 'b'";
$php_var_reg = "#(".PHP_VAR.")#";

$php_var = preg_replace($php_var_reg, "\$$1", $str);
var_dump($php_var);
die();



$str = "
{if a === 1}
<h1>One</h1>
{else if b === 2}
<h1>One</h1>
<h1>Two</h1>
{else}
<h1>One</h1>
<h1>Two</h1>
<h1>Three</h1>
{/if}
";
/*
$tostr = "
<?php if ($a === 1) {?>
<h1>One</h1>
<?php }else if ($b === 2){?>
<h1>One</h1>
<h1>Two</h1>
<?php }else {?>
<h1>One</h1>
<h1>Two</h1>
<h1>Three</h1>
<?php}?>
";
*/
$php_var_reg = "#\{if(.*)\}(.*)(\{/if\})#imsU";

$php_var = preg_replace($php_var_reg, "<?php if($1){?>$2<?php}?>", $str);
dddd($php_var);

$tpl = Template::getInstance();
$tpl->setConfig(array('debug' => true));
$tpl->show('data');

die();
$str = "{loop users}<h1>{V}</h1>{/loop}{loop users}<h1>{V}</h1>{/loop}";
$php_var_reg = "#\{loop (".PHP_VAR_REG.")\}(.*)(\{/loop\})#imU";
//preg_match($php_var_reg, $str, $matches);
//var_dump($matches);die();
$php_var = preg_replace($php_var_reg, "<?php foreach(\$$1 as \$K => \$V) {\$2} <?php }?>?>", $str);
var_dump($php_var);
die();


$str = "<h1>{data}</h1><div>{vb}";
$php_var_reg = "#\{([a-zA-Z_][a-zA-Z0-9_]*)\}#im";
$php_var = preg_replace($php_var_reg, "<?php echo \$$1;?>",$str);
var_dump($php_var);
die();

//{loop users}<h1>{V}</h1>{/loop} =>
//<?php foreach($users as $K => $V){?>
//<h1><?php echo $V;?></h1>
//<?php}?>
$tpl = Template::getInstance();
$tpl->show('data');
