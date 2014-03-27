<?php
define('PHP_SUFFIX', '.php');

class Template {
    private $config = array(
        'suffix' => '.m',
        'template_dir' => 'template/',
        'compile_dir' => 'cache/',
        'cache_html' => FALSE,
        'suffix_cache' => '.html',
        'cache_time' => 7200,
        'debug' => FALSE
    );

    private $value = array();
    private $compile_tool = NULL;
    private static $instance = NUll;
    public $file = NULL;

    /********************
     *  private function *
     ********************/
    private function __clone(){}
    private function __construct() {
        if(self::$instance === NULL) {
            require 'Compile.php';
            $this->compile_tool = new Compile();
        }
        return self::$instance;
    }

    private function _path() { // get template file path by file name
        return $this->config['template_dir']. $this->file . $this->config['suffix'];
    }
    
    private function _get_compile_file_name(){
        return $this->config['compile_dir']. md5($this->file) .PHP_SUFFIX;
    } 
    /********************
     *  public function *
     ********************/
    static function getInstance() {
        if(self::$instance === NULL) {
            self::$instance = new Template();
        }
        return self::$instance;
    }
    
    function getConfig($key = NULL) {
        if($key === NULL) {
            return $this->config;
        } else if(in_array($key, array_keys($this->config))) {
            return $this->config[$key];
        }
        return FALSE;
    }

    function setConfig($config){
        $this->config = $config + $this->config;
        return TRUE;
    } 
    
    function assign($k, $v) {
        $this->value[$k] = $v;
    }

    function assignArray($array) {
        if(is_array($array)) {
            foreach($array as $k => $v) {
                $this->assign($k, $v);
            }
        }
    }

    function show($file) {
        $this->file = $file;
        $tpl_file = $this->_path(); 
        if(!is_file($tpl_file)) {
            die('template file is not exist');
        }

        $compile_file = $this->_get_compile_file_name();
        // if compile_file not exist or neet to refresh cache
        if(!is_file($compile_file) || $this->config['debug']) {
            $this->compile_tool->run($tpl_file, $compile_file);
        }
        readfile($compile_file);
    }
}
