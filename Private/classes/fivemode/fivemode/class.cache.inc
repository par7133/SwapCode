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
 * class.cache.inc
 * 
 * Cache class.
 *
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2016, 2024, 5 Mode
 * @license https://opensource.org/licenses/BSD-3-Clause 
 */

namespace fivemode\fivemode;

/**
 * Cache
 *
 * Cache class
 *
 * @package  Cache
 * @author   Daniele Bonini <my25mb@aol.com>
 * @version  2.0
 * @access   public
 */
final class Cache extends \Memcache 
{
  /**
   * The static instance of Cache
   *  
   * @access private
   * @var Cache
   */
  private static $_instance = null;

  /**
   * Get the static instance of Cache 
   * 
   * @return Cache
   */
  public static function &getInstance(): Cache
  {  
    if(!isset(self::$_instance)){
      self::$_instance = new Cache();
      self::$_instance->addServer(CACHE_HOST, CACHE_PORT, true);
    }  
    return self::$_instance;  
  }

  /**
   * Get the service status
   * 
   * @return bool
   */
  public static function getStatus(): bool
  {  
    if(isset($this)){
      if (!$this->getServerStatus(CACHE_HOST, CACHE_PORT)) {
        return false;
      } else {
        return true;
      }
    } else if(isset(self::$_instance)){
      if (!self::$_instance->getServerStatus(CACHE_HOST, CACHE_PORT)) {
        return false;
      } else {
        return true;
      }
    } else {
      return false;
    }  
  }
  
  /**
   * Check if the static instance is set
   * 
   * @return bool
   */
  public static function issetInstance(): bool
  {
    return isset(self::$_instance);
  }
  
  /**
   * Unset the static instance
   * 
   * @return void
   */
  public static function unsetInstance(): void
  {
    self::$_instance = null;
  }

  /**
   * Default constructor
   * 
   * @return void
   */
  private function __construct()
  {
  }
  
  /**
   * Retrieve item from the cache server (decoded by json_decode)
   * 
   * @param string $key the key to fetch
   * @param int $flags the flags
   * @return array the value stored in cache
   */
  public function getObj(string $key, ?int $flags = null) 
  {
    if (!isset($flags)) {
      return $this->get(CACHE_APP_PREFIX . $key);
    }
    return $this->get(CACHE_APP_PREFIX . $key, $flags);
  }
  
  /**
   * Store data in the cache server (encoded by json_encode)
   * 
   * @param string $key the key to associated with the item.
   * @param mixed $var the object to store
   * @param int $flags the flags
   * @param int $expire expiration time, in seconds
   * @return bool true on success or false on failure 
   */
  public function setObj(string $key, &$var, ?int $flags = null, ?int $expire = null): bool 
  {
    // cache insert
    if (!isset($flags)) {
      return $this->set(CACHE_APP_PREFIX . $key, $var);
    } else if (!isset($expire)) {
      return $this->set(CACHE_APP_PREFIX . $key, $var, $flags);
    }
    return $this->set(CACHE_APP_PREFIX . $key, $var, $flags, $expire);
  }
  
  /**
   * Retrieve item from the cache server (decoded by json_decode)
   * 
   * @param string $key the key to fetch
   * @param int $flags the flags
   * @return array the value stored in cache
   */
  public function getJ(string $key, ?int $flags = null) 
  {
    if (!isset($flags)) {
      return json_decode($this->get(CACHE_APP_PREFIX . $key), true);
    }
    return json_decode($this->get(CACHE_APP_PREFIX . $key, $flags), true);
  }
  
  /**
   * Store data in the cache server (encoded by json_encode)
   * 
   * @param string $key the key to associated with the item.
   * @param mixed $var the value to store
   * @param int $flags the flags
   * @param int $expire expiration time, in seconds
   * @return bool true on success or false on failure 
   */
  public function setJ(string $key, &$var, ?int $flags = null, ?int $expire = null): bool
  {
    // cache insert
    if (!isset($flags)) {
      return $this->set(CACHE_APP_PREFIX . $key, json_encode($var));
    } else if (!isset($expire)) {
      return $this->set(CACHE_APP_PREFIX . $key, json_encode($var), $flags);
    }
    return $this->set(CACHE_APP_PREFIX . $key, json_encode($var), $flags, $expire);
  }
  
  /**
   * Test the validity of the "global" cache expiration time
   * 
   * @param string $testText the text used to generate the key for the test
   * 
   * @return bool true if the caching expiration time is not gone
   */
  //public function testLastCached($testText) {
  //  return json_decode($this->get(md5($testText), 0), true);
  //}  
}
