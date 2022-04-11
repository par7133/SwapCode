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
 * class.catutil.inc
 * 
 * The CatUtil class.
 *
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2016, 2024, 5 Mode
 * @license https://opensource.org/licenses/BSD-3-Clause 
 */

namespace fivemode\fivemode;

/**
 * CatUtil
 *
 * CatUtil class
 *
 * @package  Category
 * @author   Daniele Bonini <my25mb@aol.com>
 * @version  1.0
 * @access   public
 */
final class CatUtil
{
  /**
   * Default constructor
   * 
   * @return void
   */
  private function __construct()
  {
  }

  public static function catExist($catMaskedPath): bool
  {
    $retval = false; 
    
    //chdir(APP_PATH . PHP_SLASH . $platform);
    chdir(APP_DATA_PATH);
    
    $pattern = "*/data/cats/" . $catMaskedPath;
    $aCatPaths = array_slice(glob($pattern), 0, 1);
    
    if(!Empty($aCatPaths)) {
      $retval = true;
    }
    
    return $retval;
  }

  public static function getCatsList(): array
  {
    $reta = [];

    // Reading from the cache first
    //$cache = &Cache::getInstance();
    
    //$cacheKey = md5("CALL spGetCatList();");
    //$reta = $cache->getJ($cacheKey);
    $reta = false;
    
    if (!$reta) {
    
      //chdir(APP_PATH . PHP_SLASH . $platform);
      chdir(APP_DATA_PATH);
    
      $pattern = "*/data/cats/*";
      $aCats = array_slice(glob($pattern), 0, 100);
    
      if(!Empty($aCats)) {

        foreach($aCats as &$cat) {
          $ipos=strripos($cat, PHP_SLASH);    
          $cat=substr($cat, $ipos+1);          
          $ipos=strripos($cat, PHP_TILDE);    
          if (!$ipos) {
            $reta[$cat] = $cat;
          }        
        }
      }
    
      if (!Empty($reta)) {
        sort($reta);
      }
    }

    if (Empty($reta)) {
      $reta = [];
    }

    // Caching the array just loaded
    //$cache->setJ($cacheKey, $reta, 0, CACHE_EXPIRE);

    return $reta;
  }

  
  public static function getSubCatsList($parentMaskedPath): array
  {
    $reta = [];
    
    // Reading from the cache first
    //$cache = &Cache::getInstance();

    //$cacheKey = md5("CALL spGetSubCatsList($parentMaskedPath);");
    //$reta = $cache->getJ($cacheKey);
    $reta = false;
    if (!$reta) {

      //chdir(APP_PATH . PHP_SLASH . $platform);
      chdir(APP_DATA_PATH);
    
      $pattern = "*/data/cats/" . $parentMaskedPath . PHP_TILDE . "*";
      $aSubCats = array_slice(glob($pattern), 0, 100);
    
      if(!Empty($aSubCats)) {

        foreach($aSubCats as &$cat) {
          $ipos=strripos($cat, PHP_SLASH);    
          $cat=substr($cat, $ipos+1);          
          $reta[$cat] = $cat;
        }
      }
      
      if (!Empty($reta)) {
        sort($reta);
      }

    }

    if (Empty($reta)) {
      $reta = [];
    }

    // Caching the array just loaded
    //$cache->setJ($cacheKey, $reta, 0, CACHE_EXPIRE);

    return $reta;
  }
  
}
