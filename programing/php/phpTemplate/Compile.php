<?php

define('PHP_VAR', '(?<![^_\s])[a-zA-Z_][a-zA-Z0-9_]*');

class Compile{

    function run($source, $dest){
        $content = file_get_contents($source);
        $content = preg_replace_callback("#\{(".PHP_VAR.")\}#im", array($this, "_VAR"), $content);
        $content = preg_replace_callback("#\{loop (".PHP_VAR.")\}(.*)(\{/loop\})#imsU", array($this, "_FOREACH"), $content);
        $content = preg_replace_callback("#\{if(.*)\}(.*)(\{/if\})#imsU", array($this, "_IF"), $content);
        file_put_contents($dest, $content);
    }

    private function _VAR($matches){
        return '<?php echo $' . $matches[1] . ';?>';    
    }

    private function _IF($matches){
        $matches_1 = preg_replace("#(".PHP_VAR.")#", "\$$1", $matches[1]);
        $matches[2] = preg_replace_callback(
            "#\{else if(.*)\}#msU",
            function($m){
                $a = preg_replace("#(".PHP_VAR.")#", "\$$1", $m[1]);
                return "<?php }else if(".$a."){?>";},
            $matches[2]);
        $matches_2 = preg_replace("#\{else\}#m", "<?php}else{?>", $matches[2]);

        return "<?php if($matches_1){?>$matches_2<?php}?>";
    }
    
    private function _FOREACH($matches){
        return "<?php foreach(\${$matches[1]} as \$K => \$V) {?>".$matches[2]."<?php}?>";
    }
    private function _EVAL(){}
}