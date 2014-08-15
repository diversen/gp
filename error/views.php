<?php

class error_views {
   /**
    * controller file for error/display/404
    *
    * @package    error
    */
    public static function error403 () {
        header("HTTP/1.1 403 Forbidden");
        template::setTitle(lang::translate('Error 403: Access Denied'));
        echo html::getHeadline(lang::system('Error 403: Access Denied')) ;
        if (isset(error_module::$message)) {
            echo '<p>' . error_module::$message . '</p>';
        }
        
        echo html::createImage('/templates/sharks/images/fail-panda.jpg');
        

    }
    
    /**
     * controller file for error/display/404
     *
     * @package    error
     */    
    public static function error404 () {

        header("HTTP/1.1 404 Not Found");
        template::setTitle(lang::translate('Error 404: Page was not found'));
        echo html::getHeadline(lang::system('Error 404: Page was not found')) ;
        echo html::createImage('/templates/sharks/images/fail-panda.jpg');
    }
}