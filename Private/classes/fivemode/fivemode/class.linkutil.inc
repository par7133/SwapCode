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
 * class.linkutil.inc
 * 
 * The LinkUtil class.
 *
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2016, 2024, 5 Mode
 * @license https://opensource.org/licenses/BSD-3-Clause 
 */

namespace fivemode\fivemode;

/**
 * LinkUtil
 *
 * LinkUtil class
 *
 * @package  Link
 * @author   Daniele Bonini <my25mb@aol.com>
 * @version  1.0
 * @access   public
 */
final class LinkUtil
{
  /**
   * DEBUG FLAG 
   */
  private const DEBUG_THIS = true;
  
  /**
   * Default constructor
   * 
   * @return void
   */
  private function __construct()
  {
  }
  
  /**
   * Clean the chunk of the tag path array
   *
   * @return void
   * @access private
   */
  private static function cleanTagPathArrayChunk(&$array): void 
  {
    foreach($array as $entry) {
      $ipos = mb_strrpos($entry, PHP_SLASH);
      $entry = left($entry, $ipos);
    }  
  }  
  
  
  public static function getLinkList($q, $catMaskedPath): array
  {
    $reta = [];
    
    $aLangs = [PHP_EN];
    
    $searchCriteria = trim(strtolower($q));
    
    if ($searchCriteria==="*" || $searchCriteria === "tutte" || $searchCriteria === "所有的") {
      $searchCriteria = "all";
    }

    $searchCriteria = str_cleanplurals($searchCriteria); 

    $aKeywords = explode(PHP_SPACE, $searchCriteria);

    // Cleaning words from the exclusion list..
    if ($searchCriteria !== "all") {

      foreach ($aLangs as & $langEntry) {
        $exclusionList = Config::get("SEARCH/WORD_EXCLUSION_LIST_" . $langEntry);

        $i=0;
        foreach($aKeywords as $word) {

          if (mb_stripos($exclusionList, "|" . $word . "|")) {
            //echo_ifdebug(self::DEBUG_this, "excluded word: " . $word . "<br>");

            $searchCriteria = str_replace(PHP_SPACE . $word . PHP_SPACE, PHP_SPACE, PHP_SPACE . $searchCriteria . PHP_SPACE);
            $searchCriteria = strtolower($searchCriteria);

            unset($aKeywords[$i]);
          }

          $i++;
        }      
      }

      $searchCriteria = str_cleanphrase_M($searchCriteria);
      
    }
        
    $aKeywords = explode(PHP_SPACE, $searchCriteria);
        
    $aRepoDataPaths = Array2::PHP_EMPTY;
    
    //chdir(APP_PATH . PHP_SLASH . $platform);
    chdir(APP_DATA_PATH);
        
    //echo("platform=" . $platform . "<br>");
    //echo("q=" . $q . "<br>");
    
    //if ($q!==PHP_STR) {
    //  $pattern = "*" . $q . "*/data/cats/" . $catMaskedPath;
    //} else {
    //  $pattern = "*/data/cats/" . $catMaskedPath;
    //}  
    //$aPaths = array_slice(glob($pattern), 0, 100);

    $pattern = "*/data/cats/" . $catMaskedPath;
    $aPaths = array_slice(glob($pattern), 0, 100);
    
    //echo_ifdebug(true, $pattern . "<br>");
    //var_dump_ifdebug(true, $aPaths);
    
    if(!Empty($aPaths)) {

      self::cleanTagPathArrayChunk($aPaths);
      
      //Processing the tags..     
      foreach ($aPaths as &$fsEntry) {

        $repoDataDir = PHP_STR;
        $ipos = mb_stripos1($fsEntry, PHP_SLASH);
        $ipos = mb_stripos1($fsEntry, PHP_SLASH, $ipos + 1);
        $repoDataDir = left($fsEntry, $ipos -1);

        $ipos = mb_strrpos($repoDataDir, PHP_SLASH);
        $repoFullPath = left($repoDataDir, $ipos);

        if (!is_link($repoFullPath)) {
        
          //echo_ifdebug(self::DEBUG_this, "Tags > first match:" . $repoDataDir . "<br>");

          $bMatchPhrase = true;
          foreach ($aKeywords as &$word) {
            
            $tagPattern1 = $repoDataDir . "/tags/" . $word;
            $tagPattern2 = $repoDataDir . "/tags/" . $word . "s";
            $tagPattern3 = $repoDataDir . "/tags/" . $word . "es";
            $tagPattern4 = "____";
            if (right($word,1) === "y") {
              $tagPattern4 = $repoDataDir . "/tags/" . left($word, strlen($word)-1) . "ies";
            }  
            
            //if (!glob($tagPattern)) {
            if (trim($searchCriteria)==="all") {
              
            } else if (!is_readable($tagPattern1) && !is_readable($tagPattern2) && !is_readable($tagPattern3) && !is_readable($tagPattern4)) {
              //echo_ifdebug(self::DEBUG_this, "$tagPattern1<br>");
              //echo_ifdebug(self::DEBUG_this, "$tagPattern2<br>");
              //echo_ifdebug(self::DEBUG_this, "$tagPattern3<br>");
              //echo_ifdebug(self::DEBUG_this, "$tagPattern4<br>");
              $bMatchPhrase = false;
              break;
            }
          }

          if ($bMatchPhrase) { 
            // Adding the tag path to the final array od data paths..
            //echo_ifdebug(self::DEBUG_this, "Tags > result: included!!<br>");
            $aRepoDataPaths[$repoDataDir] = $repoDataDir;
          } else {
            //echo_ifdebug(self::DEBUG_this, "Tags > result: Not included.<br>");
          }  
        }  
      }    
      
      $iresults = 0; 
      foreach($aRepoDataPaths as $path) {
        
        $iFields = 0;
        
        $name = PHP_STR;
        $title = PHP_STR;
        $link = PHP_STR;
        $label = PHP_STR;
        $desc = PHP_STR;
        $thumb = PHP_STR;
        $image = PHP_STR;
        $code = PHP_STR;
        $guid = PHP_STR;
        
        $ipos = mb_stripos($path, PHP_SLASH, 2);
        $basedir = substr($path, 0, $ipos);
        
        //name
        $name = trim($basedir, PHP_SLASH); 
        $iFields++;
        
        //title
        $pattern = $basedir . PHP_SLASH . "data". PHP_SLASH . "title" . PHP_SLASH . "*";
        $aTitlePaths = array_slice(glob($pattern), 0, 1);
        if (!Empty($aTitlePaths)) {
          $titlePath = $aTitlePaths[0];
          $ipos = strripos($titlePath, PHP_SLASH);
          $title = substr($titlePath, $ipos+1);
          $iFields++;
        } 
       
        //link        
        $pattern = $basedir . PHP_SLASH . "data". PHP_SLASH . "link" . PHP_SLASH . "*";
        $aLinkPaths = array_slice(glob($pattern), 0, 1);
        if (!Empty($aLinkPaths)) {
          $linkPath = $aLinkPaths[0];
          $ipos = strripos($linkPath, PHP_SLASH);
          $link = substr($linkPath, $ipos+1);
          $iFields++;
        } 
        
        //label
        $pattern = $basedir . PHP_SLASH . "data". PHP_SLASH . "label" . PHP_SLASH . "*";
        $aLabelPaths = array_slice(glob($pattern), 0, 1);
        if (!Empty($aLabelPaths)) {
          $labelPath = $aLabelPaths[0];
          $ipos = strripos($labelPath, PHP_SLASH);
          $label = substr($labelPath, $ipos+1);
          $iFields++;
        } 
        
        //desc
        $pattern = $basedir . PHP_SLASH . "data". PHP_SLASH . "desc" . PHP_SLASH . "*";
        $aDescPaths = array_slice(glob($pattern), 0, 1);
        if (!Empty($aDescPaths)) {
          $descPath = $aDescPaths[0];
          $ipos = strripos($descPath, PHP_SLASH);
          $desc = substr($descPath, $ipos+1);
          $iFields++;
        } 

        //thumb
        //$pattern = APP_PATH . PHP_SLASH . "static" . PHP_SLASH . "404". PHP_SLASH . $name . PHP_UNDERSCORE . "sm" . ".*";
        $pattern = APP_PATH . PHP_SLASH . "img". PHP_SLASH . $name . PHP_UNDERSCORE . "sm" . ".*";
        $aThumbPaths = array_slice(glob($pattern), 0, 1);
        if (!Empty($aThumbPaths)) {
          $thumbPath = $aThumbPaths[0];
          $ipos = strripos($thumbPath, PHP_SLASH);
          $thumb = substr($thumbPath, $ipos+1);
          $iFields++;
        } else {
          $thumb = "code_sm.png";
          $iFields++;
        } 
        
        //image
        //$pattern = APP_PATH . PHP_SLASH . "static" . PHP_SLASH . "404". PHP_SLASH . $name . ".*";
        $pattern = APP_PATH . PHP_SLASH . "img". PHP_SLASH . $name . ".*";
        $aImagePaths = array_slice(glob($pattern), 0, 1);
        if (!Empty($aImagePaths)) {
          $imagePath = $aImagePaths[0];
          $ipos = strripos($imagePath, PHP_SLASH);
          $image = substr($imagePath, $ipos+1);
          $iFields++;
        } else {
          $image = "code.png";
          $iFields++;
        } 

        //code
        $pattern = $basedir . PHP_SLASH . "data". PHP_SLASH . "code" . PHP_SLASH . "code.txt";
        $aCodePaths = array_slice(glob($pattern), 0, 1);
        if (!Empty($aCodePaths)) {
          $codePath = $aCodePaths[0];
          //$ipos = strripos($codePath, PHP_SLASH);
          //$image = substr($imagePath, $ipos+1);
          $code = file_get_contents(APP_DATA_PATH . PHP_SLASH . $codePath);
          $iFields++;
        } else {
          $code = PHP_STR;
          $iFields++;
        }
        
        //tags
        $pattern = $basedir . PHP_SLASH . "data". PHP_SLASH . "tags" . PHP_SLASH . "*";
        $aTagPaths = glob($pattern);
        if (!Empty($aTagPaths)) {
          $bFound = false;
          $tags = "";
          foreach($aTagPaths as $tagPath) {
            $ipos = strripos($tagPath, PHP_SLASH);
            $tags .= substr($tagPath, $ipos+1) . PHP_SPACE;
            $bFound = true;
          }  
          if ($bFound) {
            $tags = rtrim($tags, PHP_SPACE);
            $iFields++;
          }
        }         

        //guid
        $pattern = $basedir . PHP_SLASH . "data". PHP_SLASH . "guid" . PHP_SLASH . "*";
        $aGuidPaths = array_slice(glob($pattern), 0, 1);
        if (!Empty($aGuidPaths)) {
          $guidPath = $aGuidPaths[0];
          $ipos = strripos($guidPath, PHP_SLASH);
          $guid = substr($guidPath, $ipos+1);
          $iFields++;
        } 

        //cats
        $pattern = $basedir . PHP_SLASH . "data". PHP_SLASH . "cats" . PHP_SLASH . "*";
        $aCatPaths = glob($pattern);
        if (!Empty($aCatPaths)) {
          $bFound = false;
          $cats = "";
          foreach($aCatPaths as $catPath) {
            $ipos = strripos($catPath, PHP_SLASH);
            $cats .= substr($catPath, $ipos+1) . PHP_SPACE;
            $bFound = true;
          }  
          if ($bFound) {
            $cats = rtrim($cats, PHP_SPACE);
            $iFields++;
          }
        }  
        
        if ($iFields===11) {
          //for ($i=0;$i<=50;$i++) {
            if (!array_key_exists($name, $reta)) {
              $reta[$name] = ['name' => $name, 'title' => $title, 'desc' => $desc, 'label' => $label, 'link' => $link, 'thumb' => $thumb, 'image' => $image, 'code' => $code, 'tags' => $tags, 'guid' => $guid, 'cats' => $cats];
              $iresults++;
            }  
          //}  
        }  
        
        if ($iresults>=50) {
          break;
        }
      }
    }
    
    return $reta;
  }
}
