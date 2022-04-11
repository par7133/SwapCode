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
 * class.errutil.inc
 * 
 * ErrUtil class.
 *
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2016, 2024, 5 Mode
 * @license https://opensource.org/licenses/BSD-3-Clause 
 */

namespace fivemode\fivemode;

/**
 * ErrUtil
 *
 * Error utilities class
 *
 * @package  Err
 * @author   Daniele Bonini <my25mb@aol.com>
 * @version  2.0
 * @access   public
 */
final class ErrUtil 
{
  
  /**
   * Default constructor
   * 
   * @return void
   */
  private function __construct()
  {
  }
  
  /**
   * Check if the given error is valid
   *
   * @param string $err the number of error
   * @param string $errKey the error key
   * @param string $errMsg the error message
   * @return boolean if the given error is valid or not
   */
  public static function isValidError(string $err, ?string &$errKey = null, ?string &$errMsg = null): bool 
  {
    if ($err==="") {
      return false;
    }

    if (isset($errKey) && isset($errMsg)) {
      $errKey = array_search($err, Err::$A_ERR_NO);
      if ($errKey) {
        $errMsg = Err::$A_ERR_MSG[$errKey];
        return true;
      } else {
        return false;
      }
    } else {
      if (array_search($err, Err::$A_ERR_NO, true)) {
        return true;
      } else {
        return false;
      }
    }
  }
}
