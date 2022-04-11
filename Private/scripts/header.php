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
 * header.php
 * 
 * Header page.
 * 
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2016, 2024, 5 Mode     
 */

use fivemode\fivemode\Page;
use fivemode\fivemode\Session;

Page::clearJSBuffer();


//if (User::issetInstance()) {
//  $user = &User::getInstance();
//  $attrLang = $user->getLanguage();
//} else {
  $attrLang = Session::get("lang", APP_DEF_LANG);
//}

?>
 
<!DOCTYPE html>
<html lang="<?php echo $attrLang;?>" xmlns="http://www.w3.org/1999/xhtml">
<head>
	
  <meta charset="UTF-8"/>
    
  <meta name="viewport" content="width=device-width, initial-scale=1"/>
  
<!--
<?php echo APP_LICENSE; ?>
-->
  
  <?php 
    if (defined("PAGE_TITLE")) {
      $pageTitle = PAGE_TITLE;
    } else {  
      $pageTitle = APP_NAME;
    }  
  ?>
  
  <title><?php echo $pageTitle; ?></title>

  <link rel="shortcut icon" href="/favicon.ico?v=<?php echo time();?>" />

  <?php
    if (defined("PAGE_DESCRIPTION")) {
      $pageDescription = PAGE_DESCRIPTION;
    } else {  
      $pageDescription = "The 404 error's place.";
    }
  ?>  
	<meta name="description" content="<?php echo $pageDescription; ?>"/>
  <?php 
    $customKeywords = "";
    $pageKeywords = $pageTitle . PHP_SPACE . strtolower(str_replace(".", PHP_STR, $pageDescription)) . PHP_SPACE . $customKeywords . PHP_SPACE . APP_NAME;
    $pageKeywords = str_replace(PHP_HYPHEN, PHP_SPACE, $pageKeywords);
    $pageKeywords = str_replace(PHP_SPACE, ",", $pageKeywords);
    $pageKeywords = str_replace(",,,", ",", $pageKeywords);
    $pageKeywords = str_replace(",,", ",", $pageKeywords);
    //$pageKeywords = str_replace(".", PHP_STR, $pageKeywords);
  ?>
  <meta name="keywords" content="<?php echo $pageKeywords;?>"/>
  <meta name="author" content="5 Mode"/> 
  
  <script src="/js/jquery-3.6.0.min.js" type="text/javascript"></script>
    <script src="/js/common.js?v=<?php echo time();?>" type="text/javascript"></script>
   <script src="/js/bootstrap.min.js" type="text/javascript"></script>
  <script src="/js/sha.js" type="text/javascript"></script>
  <script src="/js/htmlencode.js" type="text/javascript"></script>
  <script src="/js/serialize-javascript.js" type="text/javascript"></script>
  
  <script src="/js/<?php echo SCRIPT_NAME; ?>.js" type="text/javascript" defer></script>
  
  <?php if (SCRIPT_NAME === "home"): ?>
  <script src="/js/cube-code.js" type="text/javascript"></script>
  <script src="/js/dragndrop-code.js" type="text/javascript"></script>
  <?php endif; ?>
  
  <link href="/css/bootstrap.min.css" type="text/css" rel="stylesheet">
  <link href="/css/style.css?v=<?php echo time();?>" type="text/css" rel="stylesheet">
    
  <script>
    <?php if (!stripos(APP_SCRIPTS_WITHOUT_HEADER, "|". SCRIPT_NAME . "|")): ?>
      window.addEventListener("load", function() {
        loadPageHeader("<?php echo SCRIPT_NAME; ?>", "<?php echo urlencode($q); ?>", "<?php echo urlencode($catMaskedPath); ?>", "<?php echo $platform; ?>");  
        loadPageFooter("<?php echo SCRIPT_NAME; ?>");
      }, true);
    <?php endif; ?>
  </script>    
    
</head>

  <body>

 <div id="HCsplash" style="padding-top: 40px; text-align:center;color:#d4b0dc;font-family:'Bungee Hairline';">
    <div id="myh1" style="position:relative; top:80px;"><H1>SnipSwap</H1></div><br><br><br><br>
    <img src="/res/code.png" style="width:310px;">
</div>

  <div class="header2" style="margin-top:18px; margin-bottom:18px; color:#000000; display:none;">
    &nbsp;&nbsp;<a href="http://snipswap.org" target="_self" style=" text-decoration: none;"><img src="/res/code.png" style="width:25px;">&nbsp;SnipSwap</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="https://github.com/par7133/SnipSwap" style=""><span style="">on</span> github</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="mailto:info@snipswap.org" style=""><span style="">for</span> feedback</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="tel:+39-331-4029415" style="font-size:13px;background-color:#15c60b;border:2px solid #15c60b;color:#000000;height:27px;text-decoration:none;">&nbsp;&nbsp;get support&nbsp;&nbsp;</a>&nbsp;&nbsp;&nbsp;<input type="password" id="Password" name="Password" placeholder="new password" style="font-size:11px;">&nbsp;&nbsp;<a href="#" onclick="showEncodedPassword();" style="position:relative; left:0px; top:0px; font-size:13px; font-weight:900; color:green;"><?php echo(getResource("Hash Me", $curLocale));?>!</a>
 </div>     
     
  <div class="body-area">

  <div class="header" style="height: fit-content; min-height: 250px;"><!-- Here is the content of the header --></div>
  
