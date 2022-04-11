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
 * func.app.inc
 * 
 * App related functions.
 *
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2016, 2024, 5 Mode    
 * @license https://opensource.org/licenses/BSD-3-Clause 
 */

use fivemode\fivemode\Config;


/**
 * Retrieve the list of the app hosts 
 * 
 * @return array the hosts array
 */
function getHostsArray(): array {
  $reta = [];
  $reta[] = APP_HOST;
  $i = 2;
  while (true && $i<=10) {
    if (defined("APP_HOST" . $i)) {
      $reta[] = Config::get("APP/HOST" . $i);
    } else {
      break;
    }  
    $i++;
  }
  return $reta;
}


/**
 * 
 * @return string
 */
function getQRCodeUri(string $styleTag): string {
  
  $retval = PHP_STR;
  
  $serverName = strtolower($_SERVER['HTTP_HOST']);
  
  if (mb_stripos1($serverName, "5mode.com") || mb_stripos1($serverName, "localhost")) {
    $retval = "qrcode_5mode" . $styleTag . ".png";
  }
  
  return $retval; 
}


function isSubdomainHost(string &$subdomain) {
  $hostname = str_replace("www.", PHP_STR, strtolower($_SERVER['HTTP_HOST']));    
  $ipos = mb_stripos($hostname, ".");
  $subdomain = left($hostname, $ipos);
  $noSubdomain = false;
  if (($subdomain==="5mode.com")) {
    $noSubdomain = true;
  }
  return !$noSubdomain;
}