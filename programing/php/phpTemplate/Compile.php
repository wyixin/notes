<?php

class Compile{

    function run($source, $dest){
        $content = file_get_contents($source);
        $content = preg_replace_callback("#\{([a-zA-Z_][a-zA-Z0-9_]*)\}#im", function($matches){return "<?php echo \$$matches[1];?>";}, $content);
        file_put_contents($dest, $content);
    }

}