<?php

class Compile{

    function run($source, $dest){
        $content = file_get_contents($source);
        $content = preg_replace_callback("#\{([a-zA-Z_][a-zA-Z0-9_]*)\}#im", array($this, "_VAR"), $content);
        
        file_put_contents($dest, $content);
    }

    private function _VAR($matches){
        return '<?php echo $' . $matches[1] . ';?>';    
    }

    private function _IF(){}
    private function _FOREACH(){}
    private function _EVAL(){}
}