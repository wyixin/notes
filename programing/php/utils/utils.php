<?php

function dd($arr) {
    if(php_sapi_name() === 'cli') {
        print_r($arr);
        echo "\n";
    } else {
        print("<pre>".print_r($arr,true)."</pre>");
    }
}

function ddd() {
    $args = func_get_args();
    foreach($args as $arg) {
        dd($arg);
    }
}

function dddd() {
    $args = func_get_args();
    foreach($args as $arg) {
        dd($arg);
    }
    die();
}
