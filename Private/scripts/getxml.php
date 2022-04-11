<?php

/**
 * Copyright 2021, 2024 5 Mode
 *
 * This file is part of MacSwap.
 *
 * MacSwap is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MacSwap is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.  
 * 
 * You should have received a copy of the GNU General Public License
 * along with MacSwap. If not, see <https://www.gnu.org/licenses/>.
 *
 * getxml.php
 * 
 * Read an xml file from the data folder.
 *
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2016, 2024, 5 Mode
 */

header("Content-type: text/xml");

//
// PARAMETER VALIDATION
//
$filename = filter_input(INPUT_GET, "f");
$filename2 = $filename . ".xml";

//if (preg_match("/snip\d\d\d/", $filename)) {
//  $filename = $filename . ".xml";
//} else {
//  exit(0);
//}

//if (is_readable(APP_DATA_PATH . PHP_SLASH . $filename)) {
//  $filepath = APP_DATA_PATH . PHP_SLASH . $filename;
//} else {
//  exit(0);
//}

if (is_readable(APP_DATA_PATH . PHP_SLASH . $filename)) {
  $filepath = APP_DATA_PATH . PHP_SLASH . $filename . PHP_SLASH . $filename2;
} else {
  exit(0);
}

echo(file_get_contents($filepath));