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
 * init.inc
 * 
 * Initialization file.
 *
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2016, 2024, 5 Mode   
 */

//use fivemode\fivemode\Cache;
use fivemode\fivemode\Err;
use fivemode\fivemode\Page;
use fivemode\fivemode\Session;

$ctrlName = strtolower(rtrim(substr(filter_input(INPUT_GET, "url", FILTER_SANITIZE_STRING), 0, 300), "/"));
if ($ctrlName === "") {
  $ctrlName = "home";
}

error_reporting(E_ALL & ~ (E_WARNING | E_NOTICE | E_STRICT | E_DEPRECATED));  
ini_set('display_startup_errors',1);  
ini_set('display_errors',1);  
ini_set('log_errors',1); 


// CONFIGURATION
define("CONFIG_PATH", __DIR__ . DIRECTORY_SEPARATOR . ".." . DIRECTORY_SEPARATOR . "config");

require CONFIG_PATH . DIRECTORY_SEPARATOR . "config.inc";
require CONFIG_PATH . DIRECTORY_SEPARATOR . "const.php.inc";

define("FUNCTIONS_PATH", __DIR__ . DIRECTORY_SEPARATOR . ".." . DIRECTORY_SEPARATOR . "functions");

require FUNCTIONS_PATH . DIRECTORY_SEPARATOR . "func.file.inc";

// Checking a little the configuration..
if (!file_exists(APP_DATA_PATH)) {
  die("Data folder doesn't exist. You must create a data folder in your web app private path and configure it properly inside the config file.");
}	
if (!file_exists(APP_TEMPLATE_PATH)) {
  die("Template folder doesn't exist. You must have a tempate folder in your web app private path and configure it properly inside the config file.");
}	
if (EDITOR_PASSWORD === "" || (strlen(EDITOR_PASSWORD) < 64)) {
  die("Editor password must be set (with a sha256, 64 chars min length). You must generate an editor password and configure it properly inside the config file.");
}  

$pattern = APP_DATA_PATH . PHP_SLASH . "*";
$aPaths = glob($pattern);
if (count($aPaths) <= 1 ) {
  // Generating data from the template..

  for ($n=1;$n<=APP_MAX_DFT_NEW_SNIPS;$n++) { 

    if ($n<10) {
      $baseName = "snip" . "00" . $n;
    } else if ($n<100) {
      $baseName = "snip" . "0" . $n;
    } else {
      $baseName = "snip" . $n;
    }    
    
    $path = APP_DATA_PATH . PHP_SLASH . $baseName . PHP_SLASH . $baseName . ".xml";
    if (!is_readable($path)) {
      // -- generating snipNNN.xml
      
      mkdir(APP_DATA_PATH . PHP_SLASH . $baseName);

      $newTitle = $baseName;
      $newDesc = $baseName;
      //$newCode = "<![CDATA[function hello() {\nprintf('Hello world!');\n}]]>";
      $newCode = "<![CDATA[\n// Example code\nfunction hello() {\n  echo('Hello world!');\n}\n]]>";
      $newCats = "examples";
      $newTags = "hello helloworld";
      $newLabel = BUSINESS_DFT_LABEL;
      $newLink = BUSINESS_DFT_LINK;
      $newEmail = BUSINESS_DFT_EMAIL;
      $newGuid = mb_substr(hash("sha256", mt_rand() . mt_rand() . APP_SALT, false), 0, 32);
      $newPassword = EDITOR_PASSWORD; 
      
      // GNENERATING XML DATA
      copy(APP_TEMPLATE_PATH . "/snip.xml.amp.template", APP_DATA_PATH . PHP_SLASH . $baseName . PHP_SLASH . $baseName . ".xml");
      //chmod(APP_DATA_PATH . PHP_SLASH . $baseName . PHP_SLASH . $baseName . ".xml", 0777);
      
      $xmlStr = file_get_contents(APP_DATA_PATH . PHP_SLASH . $baseName . PHP_SLASH . $baseName . ".xml");
      
      $xmlStr = str_replace("<title></title>", "<title>" . $newTitle . "</title>", $xmlStr);
      $xmlStr = str_replace("<desc></desc>", "<desc>" . $newDesc . "</desc>", $xmlStr);
      $xmlStr = str_replace("<code><![CDATA[]]></code>", "<code>" . $newCode . "</code>", $xmlStr);
      $xmlStr = str_replace("<cats></cats>", "<cats>" . $newCats . "</cats>", $xmlStr);
      $xmlStr = str_replace("<tags></tags>", "<tags>" . $newTags . "</tags>", $xmlStr);
      $xmlStr = str_replace("<label></label>", "<label>" . $newLabel . "</label>", $xmlStr);
      $xmlStr = str_replace("<link></link>", "<link>" . $newLink . "</link>", $xmlStr);
      $xmlStr = str_replace("<email></email>", "<email>" . $newEmail . "</email>", $xmlStr);
      $xmlStr = str_replace("<guid></guid>", "<guid>" . $newGuid . "</guid>", $xmlStr);
      $xmlStr = str_replace("<password></password>", "<password>" . $newPassword . "</password>", $xmlStr);
      
      file_put_contents(APP_DATA_PATH . PHP_SLASH . $baseName . PHP_SLASH . $baseName . ".xml", $xmlStr);
    } else {
      
      die("Critical error. One or more example files exist. ");
    } 

    // GNENERATING FILESYSTEM DATA
    // if the snip data folder doesn'exist I create it with all the subfolders..
    //if (!is_readable(APP_DATA_PATH . PHP_SLASH . $baseName)) {
    //  mkdir(APP_DATA_PATH . PHP_SLASH . $baseName);
      mkdir(APP_DATA_PATH . PHP_SLASH . $baseName. PHP_SLASH . "data");
      mkdir(APP_DATA_PATH . PHP_SLASH . $baseName. PHP_SLASH . "data". PHP_SLASH . "title");
      mkdir(APP_DATA_PATH . PHP_SLASH . $baseName. PHP_SLASH . "data". PHP_SLASH . "desc");
      mkdir(APP_DATA_PATH . PHP_SLASH . $baseName. PHP_SLASH . "data". PHP_SLASH . "code");
      mkdir(APP_DATA_PATH . PHP_SLASH . $baseName. PHP_SLASH . "data". PHP_SLASH . "cats");
      mkdir(APP_DATA_PATH . PHP_SLASH . $baseName. PHP_SLASH . "data". PHP_SLASH . "tags");
      mkdir(APP_DATA_PATH . PHP_SLASH . $baseName. PHP_SLASH . "data". PHP_SLASH . "label");
      mkdir(APP_DATA_PATH . PHP_SLASH . $baseName. PHP_SLASH . "data". PHP_SLASH . "link");
      mkdir(APP_DATA_PATH . PHP_SLASH . $baseName. PHP_SLASH . "data". PHP_SLASH . "email");
      mkdir(APP_DATA_PATH . PHP_SLASH . $baseName. PHP_SLASH . "data". PHP_SLASH . "guid");
      mkdir(APP_DATA_PATH . PHP_SLASH . $baseName. PHP_SLASH . "data". PHP_SLASH . "password");
    //}      

    // Saving filesystem version of the data..
    $details = new SimpleXMLElement($xmlStr);

    storeFSData($details, $baseName, "title");
    storeFSData($details, $baseName, "desc");
    storeFSData($details, $baseName, "code");
    storeFSData($details, $baseName, "cats");
    storeFSData($details, $baseName, "tags");
    storeFSData($details, $baseName, "label");
    storeFSData($details, $baseName, "link");
    storeFSData($details, $baseName, "email");
    storeFSData($details, $baseName, "guid");
    storeFSData($details, $baseName, "password");
      
  }  
}  

mb_internal_encoding("UTF-8");


// AUTOLOADER

define("CLASSES_PATH", __DIR__ . DIRECTORY_SEPARATOR . ".." . DIRECTORY_SEPARATOR . "classes");
define("INTERFACES_PATH", __DIR__ . DIRECTORY_SEPARATOR . ".." . DIRECTORY_SEPARATOR . "interfaces");

/**
 * Autoloader.
 * 
 * @param string $construct the name of the construct to load
 */
function autoloader($construct) {
  
  // For third-party libraries, eg. Pear
  if (!defined("PHP_INCLUDE_PATH")) {
    define("PHP_INCLUDE_PATH", ini_get("include_path"));
  }
  
  $constructParts = explode('\\', $construct);
  
  // estrapolate the path from the construct name
  $count = count($constructParts);
  if ($count>1) {
    $i = 0;
    $constructPath = $constructParts[0];
    for ($i=1; $i<($count-1); $i++) {
      $constructPath .= DIRECTORY_SEPARATOR . $constructParts[$i];
    }
    $construct = $constructParts[$i];
  }
  
  if (!stripos($construct, "interface")) {
    // if it is a class
  
    switch ($construct) {
      case "special_case":
        $incPath = PHP_INCLUDE_PATH . DIRECTORY_SEPARATOR . "path/to/special_case.php";
        break;
      case "QRcode":
        $incPath = CLASSES_PATH . DIRECTORY_SEPARATOR . "phpqrcode/qrlib.php";
        //echo "incPath = $incPath" . PHP_BR;
        break;
      default:
      
        if (isset($constructPath)) {
          $incPath = CLASSES_PATH . DIRECTORY_SEPARATOR . $constructPath . DIRECTORY_SEPARATOR . "class." . strtolower($construct) . ".inc";
        } else {
          $incPath = CLASSES_PATH . DIRECTORY_SEPARATOR . "class." . strtolower($construct) . ".inc";
        }
        
        break;
    }
    
  } else {
    // if it is an interface
    if (isset($constructPath)) {
      $incPath = INTERFACES_PATH . DIRECTORY_SEPARATOR  . $constructPath . DIRECTORY_SEPARATOR . strtolower($construct) . ".inc";
    } else {
      $incPath = INTERFACES_PATH . DIRECTORY_SEPARATOR . strtolower($construct) . ".inc";
    }  
  }
  
  if (is_readable($incPath)) {
    //echo "$incPath is readable" . PHP_BR;
    require $incPath;
  }
  
}
spl_autoload_register("autoloader", true, true);


// FUNCTIONS

//define("FUNCTIONS_PATH", __DIR__.DIRECTORY_SEPARATOR."..".DIRECTORY_SEPARATOR."functions");

require FUNCTIONS_PATH . DIRECTORY_SEPARATOR . "func.string.inc";
require FUNCTIONS_PATH . DIRECTORY_SEPARATOR . "func.app.inc";
require FUNCTIONS_PATH . DIRECTORY_SEPARATOR . "func.various.inc";
//require FUNCTIONS_PATH . DIRECTORY_SEPARATOR . "func.file.inc";
require FUNCTIONS_PATH . DIRECTORY_SEPARATOR . "func.filter.inc";
require FUNCTIONS_PATH . DIRECTORY_SEPARATOR . "func.array.inc";


// SESSION
Session::start();

$now = time();
//if (Cookie::isEmpty("uid") || Cookie::isEmpty("uname")) {
  if (Session::exists("timeout") && $now > Session::get("timeout")) {;
    Session::destory();
    // Regenerate the session..
    Session::startWithNewContext();
  }
//}  
// Session should live at most for another half of hour
Session::set("timeout", ($now + SESSION_TIMEOUT));

$serverName = $_SERVER["SERVER_NAME"];
$qs = $_SERVER['QUERY_STRING'];

// If the Session starts for the first time I set the default
// values for 'lang','defLicense',etc..
if (!Session::exists("lang")) {
  Session::set("lang", APP_DEF_LANG);
}

Session::closeEditing();


// USER INFORMATION

// Check the user information present in the session and fill in the User static instance..
//$user = UserUtil::checkSessionUserInfo();


// ERROR HANDLING AND LOGGING

if (DEBUG) {
  error_reporting(E_ALL | E_STRICT);  
  ini_set('display_startup_errors',1);  
  ini_set('display_errors',1);
  ini_set('log_errors',1); 
} else {
  error_reporting(E_ALL & ~ (E_WARNING | E_NOTICE | E_STRICT | E_DEPRECATED));  
  ini_set('display_startup_errors',0);  
  ini_set('display_errors',0);  
  ini_set('log_errors',1); 
}

Err::setDefaultHandlers();


// HEADERS

if ($ctrlName === "search") {
  // Set public cache with 5 minutese expiration..
  //Page::setPublicCacheHeaders(300);
  Page::setNoCacheHeaders();
  
} else {
  // Disable the cache..
  Page::setNoCacheHeaders();

}


// SHUTDOWN 

/**
 * Shutdown callback.
 * 
 * @return void
 */
function shutdownCallback() {
  
  Err::setLogOnlyHandlers();

/*  
  if (Cache::issetInstance()) {  
    //For non-persistent connections only
    //$cache = &Cache::getInstance();
    //$cache->close();

    Cache::unsetInstance();
  }
*/
  
}
register_shutdown_function("shutdownCallback");

// ERROR PARAMETERS

//errNo
//define("ERR_NO", substr(filter_input1(INPUT_GET, "errNo", FILTER_SANITIZE_MD5TOKEN), 0, 100));
//if (ERR_NO!==PHP_STR && !filter_var1(ERR_NO, FILTER_VALIDATE_ERRNO)) {
//  Err::trigger_error1(ERR::ERR_ERR, "Invalid error number: " . ERR_NO, __FILE__, __LINE__);
//}

//errKey
//define("ERR_KEY", array_search(ERR_NO, Err::$A_ERR_NO));

//errMsg
//define("ERR_MSG", substr(filter_input1(INPUT_GET, "errMsg", FILTER_SANITIZE_ERRMSG), 0, 200));

//errScript
//define("ERR_SCRIPT", substr(filter_input(INPUT_GET, "errScript", FILTER_SANITIZE_STRING), 0, 255));

//errLine
//define("ERR_LINE",  substr(filter_input(INPUT_GET, "errLine", FILTER_SANITIZE_NUMBER_INT), 0, 5));

//errStack
//define("ERR_STACK", substr(filter_input1(INPUT_GET, "errStack", FILTER_SANITIZE_STRING_WITHBR), 0, 2000));

?>
