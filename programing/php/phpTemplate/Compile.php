<?php

class Compile{

    function run($source, $dest){
        file_put_contents($dest, file_get_contents($source));
    }
}