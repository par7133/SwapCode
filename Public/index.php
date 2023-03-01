<?php

/**
 * Copyright 2021, 2024 5 Mode
 *
 * This file is part of SnipSwap.
 *
 * SnipSwap is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SnipSwap is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.  
 * 
 * You should have received a copy of the GNU General Public License
 * along with SnipSwap. If not, see <https://www.gnu.org/licenses/>.
 *
 * index.php
 * 
 * The index file.
 *
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2016, 2024, 5 Mode     
 */

require "../Private/core/init.inc";

use fivemode\fivemode\CatUtil;


// FUNCTION AND VARIABLE DECLARATIONS

$scriptPath = APP_SCRIPT_PATH;

// PARAMETERS VALIDATION

$url = filter_input(INPUT_GET, "url")??"";
$url = strip_tags($url);
$url = strtolower(trim(substr($url, 0, 300), "/"));

switch ($url) {
  case "footercontent":
    define("SCRIPT_NAME", "footerContent");
    define("SCRIPT_FILENAME", "footerContent.php");   
    break; 
  case "getxml":
    define("SCRIPT_NAME", "getxml");
    define("SCRIPT_FILENAME", "getxml.php");
    break;  
  case "putxml":
    $scriptPath = APP_AJAX_PATH;
    define("SCRIPT_NAME", "putxml");
    define("SCRIPT_FILENAME", "putxml.php");
    break;      
  case "headercontent":
    define("SCRIPT_NAME", "headerContent");
    define("SCRIPT_FILENAME", "headerContent.php");   
    break;   
  default:

    $platform = filter_input(INPUT_GET, "platform")??"";
    $platform = strip_tags($platform);
    $platform = strtolower(substr($platform, 0, 1));
    
    $catPath = filter_input(INPUT_GET, "cat")??"";
    $catPath = strip_tags($catPath);
    $catPath = rtrim(substr($catPath, 0, 300), "/");
    
    $catMaskedPath = str_replace(PHP_SLASH, PHP_TILDE, $catPath);
    
    if (CatUtil::catExist($catMaskedPath)) {
      define("SCRIPT_NAME", "home");
      define("SCRIPT_FILENAME", "home.php");   
    } else {
      // In any other case, the category has no match..
      /*
       * $scriptPath = APP_ERROR_PATH;
      define("SCRIPT_NAME", "err-404");
      define("SCRIPT_FILENAME", "err-404.php");
       * 
       */
      $catMaskedPath = PHP_STR;
      define("SCRIPT_NAME", "home");
      define("SCRIPT_FILENAME", "home.php"); 
    }
}

if (SCRIPT_NAME==="err-404") {
  header("HTTP/1.1 404 Not Found");
}  

require $scriptPath . "/" . SCRIPT_FILENAME;


