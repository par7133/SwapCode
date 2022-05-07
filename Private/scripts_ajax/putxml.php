<?php

/**
 * Copyright 2021, 2024 5 Mode
 *
 * This file is part of MacSwap.
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
 * putxml.php
 * 
 * Write an xml file in the data folder.
 *
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2016, 2024, 5 Mode
 */

//
// VARIABLES AND FUNCTIONS DECLARATIONS
//


//
// PARAMETER VALIDATION
//
$filename = filter_input(INPUT_POST, "f");
$filename2 = $filename . ".xml";

$xmlStr = filter_input(INPUT_POST, "xml");


// if the snip data folder doesn'exist I create it
// with all the subfolders..
if (!is_readable(APP_DATA_PATH . PHP_SLASH . $filename)) {
  mkdir(APP_DATA_PATH . PHP_SLASH . $filename);
  mkdir(APP_DATA_PATH . PHP_SLASH . $filename. PHP_SLASH . "data");
  mkdir(APP_DATA_PATH . PHP_SLASH . $filename. PHP_SLASH . "data". PHP_SLASH . "title");
  mkdir(APP_DATA_PATH . PHP_SLASH . $filename. PHP_SLASH . "data". PHP_SLASH . "desc");
  mkdir(APP_DATA_PATH . PHP_SLASH . $filename. PHP_SLASH . "data". PHP_SLASH . "code");
  mkdir(APP_DATA_PATH . PHP_SLASH . $filename. PHP_SLASH . "data". PHP_SLASH . "cats");
  mkdir(APP_DATA_PATH . PHP_SLASH . $filename. PHP_SLASH . "data". PHP_SLASH . "tags");
  mkdir(APP_DATA_PATH . PHP_SLASH . $filename. PHP_SLASH . "data". PHP_SLASH . "label");
  mkdir(APP_DATA_PATH . PHP_SLASH . $filename. PHP_SLASH . "data". PHP_SLASH . "link");
  mkdir(APP_DATA_PATH . PHP_SLASH . $filename. PHP_SLASH . "data". PHP_SLASH . "email");
  mkdir(APP_DATA_PATH . PHP_SLASH . $filename. PHP_SLASH . "data". PHP_SLASH . "beauty");
  mkdir(APP_DATA_PATH . PHP_SLASH . $filename. PHP_SLASH . "data". PHP_SLASH . "guid");
  mkdir(APP_DATA_PATH . PHP_SLASH . $filename. PHP_SLASH . "data". PHP_SLASH . "password");
}


// Saving the XML file..
$filepath = APP_DATA_PATH . PHP_SLASH . $filename . PHP_SLASH . $filename2;
file_put_contents($filepath, $xmlStr);



// Saving filesystem version of the data..
$details = new SimpleXMLElement($xmlStr);

storeFSData($details, $filename, "title");
storeFSData($details, $filename, "desc");
storeFSData($details, $filename, "code");
storeFSData($details, $filename, "cats");
storeFSData($details, $filename, "tags");
storeFSData($details, $filename, "label");
storeFSData($details, $filename, "link");
storeFSData($details, $filename, "email");
storeFSData($details, $filename, "beauty");
storeFSData($details, $filename, "guid");
storeFSData($details, $filename, "password");

echo json_encode([200, 'OK']);