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
 * func.array.inc
 * 
 * Array related functions.
 *
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2016, 2024, 5 Mode     
 * @license https://opensource.org/licenses/BSD-3-Clause 
 */

/**
 * Fix multiple file uploaded array ($_FILE)
 * 
 * @param array $f the $_FILE array
 * @return array the array fixed
 */
function fixMultipleFileUpload(&$f): array
{
    $files = array();
    $count = count($f['name']);
    $keys = array_keys($f);
   
    for($i=0;$i<$count;$i++)
    {
        foreach($keys as $key)
        {
            $files[$i][$key] = $f[$key][$i];
        }
    }
    return $files;
}

/**
 * Count the non zero elements of the given array
 * 
 * @param array $array
 */
function count_nonzeros(& $array): int 
{
  return count(array_filter($array));
}  
  
/**
 * Count the dimensions of the given array
 * 
 * @param array $array
 * @return int the dimensions of the array
 */
function array_dim(array $array): int
{
  if (is_array(reset($array))) {
    $retval = array_dim(reset($array)) + 1;
  } else {
    $retval = 1;
  }

  return $retval;
}

/**
 * Filter false array entries replacing them with nulls
 * 
 * @param array $array array to filter
 * @return array the resulting array
 */
function array_filter_tonull(array $array): array 
{
  foreach($array as & $val) {
    if (!$val) {
      $val = null;
    }
  }
  return $array;
}

/**
 * Return the values from a single column in the input array 
 * filtered for value between $min and $max..
 * 
 * @param array $array the array being filtered
 * @param string $column the column to filter on
 * @param mixed $min the min val of column
 * @param mixed $max the max val of column
 * @return array the filtered array
 */
function array_numcolumn(& $array, string $column, int $min = 0, int $max = 99999999999): array 
{
  $GLOBALS['min'] = $min;
  $GLOBALS['max'] = $max;
  $array = array_filter(array_column($array, $column), function($val) {
    if ($val>=$GLOBALS['min'] && $val<=$GLOBALS['max']) {
      return true;
    } else {
      return false;
    }
  });
  return $array;
}

/**
 * Count the keys of a given array
 * 
 * @param array $array
 * @return int the number of keys
 */
function array_keys_count(& $array): int
{
  return count(array_keys($array));
}

/**
 * Append a value to the right of array until the given length
 * 
 * @param array $array array to pad
 * @param mixed $val the value to the append to the array
 * @param int $len the final length of the padded array
 * @return void
 */
function array_rpad(& $array, $val, int $newlen): void 
{
  $i=count($array);
  if ($i>=$newlen) {
    return;
  }
  while($i<$newlen) {
    $array[] = $val; 
    $i++;
  }
}

/**
 * Searches the array for a given value and returns the corresponding key if successful
 * otherwise null, result safe (not 0)
 * 
 * @param mixed $needle the value to search 
 * @param array $array the array being searched
 * @return mixed the key associated to the value, or null
 */
function array_search2($needle, & $array) 
{
  $retval = null;
  foreach ($array as $key => $value) {
    if ($value === $needle) {
      $retval = $key;
      break;
    }
  }
  return $retval;
}