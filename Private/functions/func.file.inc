<?php

/**
 * Copyright (c) 2016, 2024, 5 Mode
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither Open Gallery nor the names of its contributors 
 *       may be used to endorse or promote products derived from this software 
 *       without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * func.file.inc
 * 
 * String related functions.
 *
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2016, 2024, 5 Mode
 * @license https://opensource.org/licenses/BSD-3-Clause 
 */

/**
 * Copy a source file
 * 
 * @param string $sourceFilePath the file to copy
 * @param string $destFilePath the destination file
 * @return void
 */
function cp(string $sourceFilePath, string $destFilePath): void 
{
  $dataLength = 300000;
  $hsfile = fopen($sourceFilePath, "r");
  $hdfile = fopen($destFilePath, "w");
  while ($data = fread($hsfile, $dataLength)) {
    fwrite($hdfile, $data);
  }
  fclose($hsfile);
  fclose($hdfile);
}

/**
 * Store FileSystem data version of an XML snip field 
 * 
 * @param string $details the SimpleXML base details collection
 * @param string $filename the basedir
 * @param string $field the field to save
 * @return void
 */
function storeFSData($details, $filename, $field) {

  $datapath = APP_DATA_PATH . PHP_SLASH . $filename . PHP_SLASH . "data" . PHP_SLASH . $field;
  chdir($datapath);
  $pattern = "*";
  $apath = glob($pattern);
  foreach($apath as $path) {
    unlink($path);
  }  
  switch($field) {
    case "title":
      file_put_contents($details->detail[0]->title, PHP_STR);
      break;
    case "desc":
      file_put_contents($details->detail[0]->desc, PHP_STR);
      break;
    case "code":
      file_put_contents("code.txt", $details->detail[0]->code);
      break;
    case "tags":
      $tags = trim($details->detail[0]->tags);
      $a = explode(" ", $tags);
      foreach($a as $f) {
        file_put_contents($f, PHP_STR);
      }  
      break;
    case "cats":
      $cats = trim($details->detail[0]->cats);
      $a = explode(" ", $cats);
      foreach($a as $f) {
        file_put_contents($f, PHP_STR);
      }  
      break;
    case "label":
      file_put_contents($details->detail[1]->label, PHP_STR);
      break;
    case "link":
      file_put_contents($details->detail[1]->link, PHP_STR);
      break;
    case "email":
      file_put_contents($details->detail[1]->email, PHP_STR);
      break;
    case "guid":
      file_put_contents($details->detail[2]->guid, PHP_STR);
      break;
    case "password":
      file_put_contents($details->detail[3]->password, PHP_STR);
      break;
  }
  
}
