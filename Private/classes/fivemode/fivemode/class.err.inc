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
 * class.err.inc
 * 
 * Err class.
 *
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2016, 2024, 5 Mode
 * @license https://opensource.org/licenses/BSD-3-Clause 
 */

namespace fivemode\fivemode;

/**
 * Err
 *
 * Err class
 *
 * @package  Error
 * @author   Daniele Bonini <my25mb@aol.com>
 * @version  2.0
 * @access   public
 */
final class Err 
{
  const ERR_REQMETHOD = "aL968iHaFEqRil8u6mFf1MpV1c681q3L";
  const ERR_Q = "pCgzogPXvWzVqqYxL62U7iqjUo8VQAL1";  
  const ERR_CSRFTOKEN = "830V0HWl2OInNb7Rm3KkK0wE07bpH43f";
  const ERR_RESETTOKEN = "VugoUE8c71mc5v9118Xx8lGF3g5Q6PJD";
  const ERR_ACTIVATIONTOKEN = "QN2CkNda9Q6LZ27muf4g79956ml6U4Y7";
  const ERR_USERNAME = "113MXP20HBNGlEPHHHX14QICDzOzojrU";  
  const ERR_EMAIL = "46XnbH6vr4j74myYnVTN05VtGmBjL6MQ";
  const ERR_PASSWORD = "M9F28Mb0zyNJb5PXm55Rdexm4J10rPaK"; 
  const ERR_CONFIRMPASSWORD = "03iKDr6sqM02jwc3tGeLvcL5f9qfjjVN";   
  const ERR_ERR = "ZB5R981mz24K29RgNn8uZMr1Vjs055x9";  
  const ERR_MAILER = "RolA9Gf6d24i9x7IO6iUbft666980L01";    
  const ERR_GENERAL = "uEh1RE49t6qn91101aZvS4xbZ9TlGLeF";
  const ERR_ACTIVATION_UNAFFECTED = "x8E68M61ts4y4C6vCUgBzYFo2xJ35k5j";
  const ERR_INPUT = "J1SfED4zF8zg3g5O5FwNwUv6se5Q575r";
  const ERR_USER_EXISTS = "914UgIj1duRGg128685BDSF6BX8xb9rE";  
  const ERR_EMAIL_EXISTS = "4q2It72ei9lc36CKWjo2o12aA6A4j0OX";
  const ERR_USERNAMEEMAIL = "PhKZ496q7YAWyDsxmu785Qqwq8KZZs5A";
  const ERR_LOGIN = "89OIg13286oOOg9xB0IpH5QJN7iq59E0";
  const ERR_NO_FILE1 = "FqkYQ1lC8T6aMeMW7RcP59186MqNr6eV";
  const ERR_INI_SIZE = "l4tjbCfQu8H62Z9DiIr44ACO4kC5iFaK";
  const ERR_FORM_SIZE = "U5L22gw2dXmN901G1IKGTVJ9O8dw19ea";
  const ERR_PARTIAL = "tUxsOG6lvd60U893C8aQB6Z72883M6S1";
  const ERR_NO_FILE2 = "8nUS01tMNreY2SC61g57V5E120a2f8wd";
  const ERR_NO_TMP_DIR = "4U4DfRK1JwWoyk6T9Qa4h773smDrhx78";
  const ERR_CANT_WRITE = "FSdmAd9TMeG7YKGcN8Vb4ooto78j94xQ";
  const ERR_EXTENSIONv = "vFrK8k1VnKw449Ftu3QJX32f7VLi0gkh";
  const ERR_UPLOAD = "axC6XDh5J38D9mtH6eC13fDAQeVh50gy";
  const ERR_FILE_NAME = "I25q7cDjr7hT9y9IeXTJRC6Al52kjTsj";
  const ERR_FILE_TYPE = "7nV9J44C1Ms3f31V0B33TNxW2C3yGlXa";
  const ERR_FILE_TMPPATH = "7p95KtqF0rpS9f5pgwaUJSe9gL1s482T";
  const ERR_FILE_SIZE = "QapHtKQJjv2m2kOVt5g5465126wd3I0y";
  const ERR_USER_SESSION = "0AcGK57R4bjfTI8k7Y0fZFE4ETQ1MBrX";
  const ERR_NAME = "x11exQg6Lygl4Yz47R78FRIw799quH5P";
  const ERR_CURRENTPAGE = "9V2QCOkw9CWPHrNGZin8Ms6WX96H64mL";
  const ERR_MAXVISIBLEPAGES = "Q6ttpCa69RW3YNE98ZT8E6ub62TW1Ci0";
  const ERR_ITEMSPERPAGE = "slTlreOPn10VU0I8eq5xeo6yu133rr1A";  
  const ERR_LANDINGPAGE = "oDsf279T556WuF0dWnI5Lep0rWb538x7";   
  const ERR_TOTITEMS = "2iW0vpAN1YcXBN5sHzu5BbqUY8cKf2C2";   
  const ERR_ID = "0OdS5agNpvMUb7S5K7JH4vRRkQ1Af75n";  
  const ERR_QUERYORDER = "rknXwuwe79bpJcl4b3HsdJuTKMXbeiA8";   
  const ERR_QUERYCOUNT = "l71XwgU1oQR80m8ad0c51771g84Tmfkj";
  const ERR_QUERYOFFSET = "Xt2yxZFvRJzjJR8i4rHPeUQWdjj64ni8";
  const ERR_LANGUAGE = "qXG07iz29D4139Dv82nyfidZ0rb3Nx55";
  const ERR_UPDATE_TYPE = "XXj4FfRg75x9G52drcuNn4wFN9PA5O68";
  const ERR_CLASS_PARAMETER = "mM6kv48j9YoRzxvoSghGjZzA81P7ZW6D";
  const ERR_SID = "yY2jO7dA34yN8l8XY4y6LvR562IKw8K3";
  const ERR_URL = "ji8tlwybgLIWXn39WjMr3Btjq55hO264";
  const ERR_URL_EXISTS = "E1W6hIt1NIvKKE5J4Ie4OMIS1w7guAaY";
  const ERR_LICENSE = "3n3eWwLS8O15B2hcENR1V9oEz6N1Urg7";
  const ERR_VALUE = "mfpf4YB51hwLRcbHCO75iOIjFLf62Adt";
  const ERR_SCRIPT = "FOv6rNC0zZ9hJAcQci203NfLxE5I1Dx5";
  const ERR_KEY = "a0r15FBV1sMkLSJjZPGNG4jfD1ZEZ8Bt";
  const ERR_DEFLANG_VALUE = "mt0ky5w877E1r61uPHR8Kyy3L2Qucap7";
  const ERR_DOUBLE_RESOURCE = "P8gDL50HN9953pGc10Is1nr6pZDIr928";
  const ERR_WORD = "sQ5zfY64zYjR06k4p11csawH1yTE497y";
  const ERR_DOUBLE_WORD = "rE7Y56ZoV40DjEn5hY20PWRBFItKdHG9";
  const ERR_WARNING = "PIzM4pxF3AaoO7H84bSCs4DMDQtmzqxE";
  const ERR_FILTER = "3yGn0aF50m4641P63IR5ZEhBtEi1THM3";
  const ERR_PRIMCAT = "4fdWHXEjlKNuPrv9avpr7I82iR8Hp5Yn";
  const ERR_SECONDCAT = "4299KiwIac5BjMt3tYF1XS9z1pLQ2c1X";
  const ERR_THIRDCAT = "94pQUGKmHa808R1R4w5Lw9xTl0kZdAf1";
  const ERR_FOURTHCAT = "p4PVCH3XWqZyFf4a9JZarb85Eyg9DeBm";
  const ERR_FIFTHCAT = "iYug27oaLzbkN4bblgvIsoXSn1LdHb3H";
  const ERR_NEWCAT = "75AR87Rb31V091498o8nZyF5YW38wac2";
  const ERR_NEWCAT_TEXT = "270k4NIym160Y7v04Xueq67Fiz1390Q7";
  const ERR_NEWSUBCATS = "Jf5r0xB5F94O0G1kHD961Eh7KJ0747Ct";
  const ERR_IMAGETYPE = "LreYdjhbuP9ZiooW7F1vhhLRtyS9cITq";
  const ERR_IMAGETYPE_CAT = "03C0uwNu9Y8Wp45SG5N5brPKUFRswdM8";
  const ERR_CLASSIFI_OP = "9beQuuTu0bb693naFr0pqSPXn416P9w5";
  const ERR_DEFAULT_CLASSIFI = "zkMvjN1CKDk8mDNKT1v4j2Iy8xuEhq0i";
  const ERR_MODIFIER = "71o01reqwGec1h8tC5URmLQxOo5SQ1Iw";
  const ERR_IMAGE_CAT = "gi17u1zT0Lu1r4HVRm9yBxn8dc1d0Gzv";
  const ERR_IMAGE = "S5KvIB5NJdv7b55Kj80CbdPZ8zV85t6e";
  const ERR_APPROVED = "40zz08totKa01oChY50Q5BpEgJiK52GZ";
  const ERR_DEBUG_INFO = "hDy3Fo92hJV5tV12GQc6dc8crSFu8Y4d";
  const ERR_REFERER = "bYNB81774j5kJuZUb6D06XmF8UupjRWJ";
  const ERR_USER = "7ZnLN90x4IPqZL4s51cRJB0564v557Os";
  const ERR_MEDIATYPE = "s3405pWyyg64d0aD6Q2WPZM8Z1R75XFg";
  const ERR_SUBJECT = "PDF79vr5D67dcGQvw9tBR7qw8NQ63121";
  const ERR_FROM = "ZrLvAPcWk1Do6lsMe0RKm8ObquXk2E9L";
  const ERR_TO = "PcThvAYl3Fp7JRsCVe4Lm9sM0CQe4GVi";
  const ERR_RTYPE = "GNpSauDWf1Hj5pJtNa1DSf5HWjr8KcvP";
  const ERR_EXPW = "01DSf5HWjMoQsg2ATI7EYpJtNaTgvAXI";
  
  public static $A_ERR_NO = [
    'ERR_REQMETHOD' => "aL968iHaFEqRil8u6mFf1MpV1c681q3L",
    'ERR_Q' => "pCgzogPXvWzVqqYxL62U7iqjUo8VQAL1",  
    'ERR_CSRFTOKEN' => "830V0HWl2OInNb7Rm3KkK0wE07bpH43f",
    'ERR_RESETTOKEN' => "VugoUE8c71mc5v9118Xx8lGF3g5Q6PJD",
    'ERR_ACTIVATIONTOKEN' => "QN2CkNda9Q6LZ27muf4g79956ml6U4Y7",
    'ERR_USERNAME' => "113MXP20HBNGlEPHHHX14QICDzOzojrU",  
    'ERR_EMAIL' => "46XnbH6vr4j74myYnVTN05VtGmBjL6MQ",
    'ERR_PASSWORD' => "M9F28Mb0zyNJb5PXm55Rdexm4J10rPaK", 
    'ERR_CONFIRMPASSWORD' => "03iKDr6sqM02jwc3tGeLvcL5f9qfjjVN",   
    'ERR_ERR' => "ZB5R981mz24K29RgNn8uZMr1Vjs055x9",  
    'ERR_MAILER' => "RolA9Gf6d24i9x7IO6iUbft666980L01",    
    'ERR_GENERAL' => "uEh1RE49t6qn91101aZvS4xbZ9TlGLeF",
    'ERR_ACTIVATION_UNAFFECTED' => "x8E68M61ts4y4C6vCUgBzYFo2xJ35k5j",
    'ERR_INPUT' => "J1SfED4zF8zg3g5O5FwNwUv6se5Q575r",
    'ERR_USER_EXISTS' => "914UgIj1duRGg128685BDSF6BX8xb9rE",  
    'ERR_EMAIL_EXISTS' => "4q2It72ei9lc36CKWjo2o12aA6A4j0OX",
    'ERR_USERNAMEEMAIL' => "PhKZ496q7YAWyDsxmu785Qqwq8KZZs5A",
    'ERR_LOGIN' => "89OIg13286oOOg9xB0IpH5QJN7iq59E0",
    'ERR_NO_FILE1' => "FqkYQ1lC8T6aMeMW7RcP59186MqNr6eV",
    'ERR_INI_SIZE' => "l4tjbCfQu8H62Z9DiIr44ACO4kC5iFaK",
    'ERR_FORM_SIZE' => "U5L22gw2dXmN901G1IKGTVJ9O8dw19ea",
    'ERR_PARTIAL' => "tUxsOG6lvd60U893C8aQB6Z72883M6S1",
    'ERR_NO_FILE2' => "8nUS01tMNreY2SC61g57V5E120a2f8wd",
    'ERR_NO_TMP_DIR' => "4U4DfRK1JwWoyk6T9Qa4h773smDrhx78",
    'ERR_CANT_WRITE' => "FSdmAd9TMeG7YKGcN8Vb4ooto78j94xQ",
    'ERR_EXTENSION' => "vFrK8k1VnKw449Ftu3QJX32f7VLi0gkh",
    'ERR_UPLOAD' => "axC6XDh5J38D9mtH6eC13fDAQeVh50gy",
    'ERR_FILE_NAME'=> "I25q7cDjr7hT9y9IeXTJRC6Al52kjTsj",
    'ERR_FILE_TYPE' => "7nV9J44C1Ms3f31V0B33TNxW2C3yGlXa",
    'ERR_FILE_TMPPATH' => "7p95KtqF0rpS9f5pgwaUJSe9gL1s482T",
    'ERR_FILE_SIZE' => "QapHtKQJjv2m2kOVt5g5465126wd3I0y",
    'ERR_USER_SESSION' => "0AcGK57R4bjfTI8k7Y0fZFE4ETQ1MBrX",
    'ERR_NAME' => "x11exQg6Lygl4Yz47R78FRIw799quH5P",
    'ERR_CURRENTPAGE' => "9V2QCOkw9CWPHrNGZin8Ms6WX96H64mL",
    'ERR_MAXVISIBLEPAGES' => "Q6ttpCa69RW3YNE98ZT8E6ub62TW1Ci0",
    'ERR_ITEMSPERPAGE' => "slTlreOPn10VU0I8eq5xeo6yu133rr1A",  
    'ERR_LANDINGPAGE' => "oDsf279T556WuF0dWnI5Lep0rWb538x7",   
    'ERR_TOTITEMS' => "2iW0vpAN1YcXBN5sHzu5BbqUY8cKf2C2",   
    'ERR_ID' => "0OdS5agNpvMUb7S5K7JH4vRRkQ1Af75n",  
    'ERR_QUERYORDER' => "rknXwuwe79bpJcl4b3HsdJuTKMXbeiA8",   
    'ERR_QUERYCOUNT' => "l71XwgU1oQR80m8ad0c51771g84Tmfkj",
    'ERR_QUERYOFFSET' => "Xt2yxZFvRJzjJR8i4rHPeUQWdjj64ni8",
    'ERR_LANGUAGE' => "qXG07iz29D4139Dv82nyfidZ0rb3Nx55", 
    'ERR_UPDATE_TYPE' => "XXj4FfRg75x9G52drcuNn4wFN9PA5O68",
    'ERR_CLASS_PARAMETER' => "mM6kv48j9YoRzxvoSghGjZzA81P7ZW6D",
    'ERR_SID' => "yY2jO7dA34yN8l8XY4y6LvR562IKw8K3",
    'ERR_URL' => "ji8tlwybgLIWXn39WjMr3Btjq55hO264",
    'ERR_URL_EXISTS' => "E1W6hIt1NIvKKE5J4Ie4OMIS1w7guAaY",
    'ERR_LICENSE' => "3n3eWwLS8O15B2hcENR1V9oEz6N1Urg7",
    'ERR_VALUE' => "mfpf4YB51hwLRcbHCO75iOIjFLf62Adt",    
    'ERR_SCRIPT' => "FOv6rNC0zZ9hJAcQci203NfLxE5I1Dx5",
    'ERR_KEY' => "a0r15FBV1sMkLSJjZPGNG4jfD1ZEZ8Bt",
    'ERR_DEFLANG_VALUE' => "mt0ky5w877E1r61uPHR8Kyy3L2Qucap7",
    'ERR_DOUBLE_RESOURCE' => "P8gDL50HN9953pGc10Is1nr6pZDIr928",  
    'ERR_WORD' => "sQ5zfY64zYjR06k4p11csawH1yTE497y",
    'ERR_DOUBLE_WORD' => "rE7Y56ZoV40DjEn5hY20PWRBFItKdHG9",
    'ERR_FILTER' => "3yGn0aF50m4641P63IR5ZEhBtEi1THM3",  
    'ERR_PRIMCAT' => "4fdWHXEjlKNuPrv9avpr7I82iR8Hp5Yn",
    'ERR_SECONDCAT' => "4299KiwIac5BjMt3tYF1XS9z1pLQ2c1X",
    'ERR_THIRDCAT' => "94pQUGKmHa808R1R4w5Lw9xTl0kZdAf1",
    'ERR_FOURTHCAT' => "p4PVCH3XWqZyFf4a9JZarb85Eyg9DeBm",
    'ERR_FIFTHCAT' => "iYug27oaLzbkN4bblgvIsoXSn1LdHb3H",  
    'ERR_NEWCAT' => "75AR87Rb31V091498o8nZyF5YW38wac2",
    'ERR_NEWCAT_TEXT' => "270k4NIym160Y7v04Xueq67Fiz1390Q7",
    'ERR_NEWSUBCATS' => "Jf5r0xB5F94O0G1kHD961Eh7KJ0747Ct",
    'ERR_IMAGETYPE' => "LreYdjhbuP9ZiooW7F1vhhLRtyS9cITq",  
    'ERR_IMAGETYPE_CAT' => "03C0uwNu9Y8Wp45SG5N5brPKUFRswdM8",
    'ERR_CLASSIFI_OP' => "9beQuuTu0bb693naFr0pqSPXn416P9w5",
    'ERR_DEFAULT_CLASSIFI' => "zkMvjN1CKDk8mDNKT1v4j2Iy8xuEhq0i",
    'ERR_MODIFIER' => "71o01reqwGec1h8tC5URmLQxOo5SQ1Iw",
    'ERR_IMAGE_CAT' => "gi17u1zT0Lu1r4HVRm9yBxn8dc1d0Gzv",
    'ERR_IMAGE' => "S5KvIB5NJdv7b55Kj80CbdPZ8zV85t6e",  
    'ERR_APPROVED' => "40zz08totKa01oChY50Q5BpEgJiK52GZ",
    'ERR_DEBUG_INFO' => "hDy3Fo92hJV5tV12GQc6dc8crSFu8Y4d",
    'ERR_REFERER' => "bYNB81774j5kJuZUb6D06XmF8UupjRWJ",
    'ERR_USER' => "7ZnLN90x4IPqZL4s51cRJB0564v557Os",  
    'ERR_MEDIATYPE' => "s3405pWyyg64d0aD6Q2WPZM8Z1R75XFg",
    'ERR_SUBJECT' => "PDF79vr5D67dcGQvw9tBR7qw8NQ63121",  
    'ERR_FROM' => "ZrLvAPcWk1Do6lsMe0RKm8ObquXk2E9L",
    'ERR_TO' => "PcThvAYl3Fp7JRsCVe4Lm9sM0CQe4GVi",
    'ERR_RTYPE' => "GNpSauDWf1Hj5pJtNa1DSf5HWjr8KcvP",
    'ERR_EXPW' => "01DSf5HWjMoQsg2ATI7EYpJtNaTgvAXI"
  ];

/*
  public static $A_ERR_MSG = [
    'ERR_REQMETHOD' => "Invalid request method.",
    'ERR_Q' => "Invalid search query.",
    'ERR_CSRFTOKEN' => "Page has expired.",
    'ERR_RESETTOKEN' => "Invalid reset token.", 
    'ERR_ACTIVATIONTOKEN' => "Invalid activation token.", 
    'ERR_USERNAME' => "Invalid username.",  
    'ERR_EMAIL' => "Invalid email address.",
    'ERR_PASSWORD' => "Invalid password (almost 8 chars long).", 
    'ERR_CONFIRMPASSWORD' => "Password doesn't match.",  
    'ERR_ERR' => "Invalid error.",
    'ERR_MAILER' => "Mailer error.",
    'ERR_GENERAL' => "Unexpected error happened.",
    'ERR_ACTIVATION_UNAFFECTED' => "Account already active.",
    'ERR_INPUT' => "Invalid input data.",
    'ERR_USER_EXISTS' => "User already exist.",  
    'ERR_EMAIL_EXISTS' => "Email already registred.",
    'ERR_USERNAMEEMAIL' => "Invalid username/email.",
    'ERR_LOGIN' => "Invalid login information.",    
    'ERR_NO_FILE1' => "No file uploaded.",
    'ERR_INI_SIZE' => "File exceeded size limit.",
    'ERR_FORM_SIZE' => "File exceeded size limit.",
    'ERR_PARTIAL' => "File only partially uploaded.",
    'ERR_NO_FILE2' => "One or more files are missing.",
    'ERR_NO_TMP_DIR' => "TMP dir doesn't exist.",
    'ERR_CANT_WRITE' => "Failed to write to disk.",
    'ERR_EXTENSION' => "Something stopped the file upload.",
    'ERR_UPLOAD' => "Invalid upload.",
    'ERR_FILE_NAME'=> "Invalid file name.",
    'ERR_FILE_TYPE' => "Invalid file type.",
    'ERR_FILE_TMPPATH' => "Invalid TMP path.",
    'ERR_FILE_SIZE' => "Invalid file size.",
    'ERR_USER_SESSION' => "Invalid user session.",
    'ERR_NAME' => "Invalid name.",
    'ERR_CURRENTPAGE' => "Invalid current page.",
    'ERR_MAXVISIBLEPAGES' => "Invalid max visible pages.",
    'ERR_ITEMSPERPAGE' => "Invalid items per page.",  
    'ERR_LANDINGPAGE' => "Invalid landing page.",   
    'ERR_TOTITEMS' => "Invalid total items.",   
    'ERR_ID' => "Invalid id.",
    'ERR_QUERYORDER' => "Invalid query order.",   
    'ERR_QUERYCOUNT' => "Invalid query count.",
    'ERR_QUERYOFFSET' => "Invalid query offset.",
    'ERR_LANGUAGE' => "Invalid language.",
    'ERR_UPDATE_TYPE' => "Invalid update type.",
    'ERR_PARAM1' => "Invalid first parameter.",
    'ERR_SID' => "Invalid search id.",
    'ERR_URL' => "Invalid url.",
    'ERR_URL_EXISTS' => "Url already registred.",
    'ERR_LICENSE' => "Invalid license.",
    'ERR_VALUE' => "Invalid value.",
    'ERR_SCRIPT' => "Invalid script.",
    'ERR_KEY' => "Invalid key.",
    'ERR_DEFLANG_VALUE' => "Invalid default language value.",
    'ERR_DOUBLE_RESOURCE' => "Resource already exists."  
  ];
  */
  public static $A_ERR_MSG = [];

  public static $A_ERR_EXTDES_MSG = [];
  
  /**
   * the instance of the object 
   * 
   * @access private 
   * @var Err
   */
  private static $_instance = null;  
  
  /**
   * Reference to the previous error handler
   * 
   * @access public
   * @var string  
   */
  private static $_old_error_handler;

  /**
   * Param1 of the previous error handler
   * 
   * @access public
   * @var string  
   */
  private static $_old_error_handler_param1 = null;

  /**
   * Param2 of the previous error handler
   * 
   * @access public
   * @var string  
   */
  private static $_old_error_handler_param2 = null;

  /**
   * Exception handler / trigger in the form of anonymous function
   * 
   * @access public 
   * @var function
   */
  private static $_throw1;

  /**
   * Error handler / trigger in the form of anonymous function
   * 
   * @access public 
   * @var function
   */
  private static $_trigger_error1;
  
  /**
   * Default constructor
   */
  private function __construct()
  {
    self::$_old_error_handler = PHP_STR;
    
    //if (User::issetInstance()) {
    //  $user = &User::getInstance();
    //  $lang = (string)$user->getLanguage();
    //} else {
      $lang = (string)Session::get("lang", APP_DEF_LANG);
    //}
    
    /*  
    $cache = &Cache::getInstance();
    
    // Read from the cache first
    $cacheKey = md5("CALL spGetErrResources('$lang','ERR')");
    $aErrResources = $cache->getJ($cacheKey);
    if (!$aErrResources) {

      $db = &DB::getInstance();
      
      $sSQL = "CALL spGetErrResources(?, ?)";

      $aErrResources = $db->select_SP($sSQL, [
          ["s", $lang],
          ["s", "ERR"]
      ]);
    }
    // Store the data into the cache
    $cache->setJ($cacheKey, $aErrResources, 0, CACHE_EXPIRE);

    if (!empty($aErrResources)) {
      foreach ($aErrResources as &$res) {    
        //echo "Loading.." . $res['key'] . " = " . $res['value'] . "<br>";
        self::$A_ERR_MSG[$res['key']] = $res['value']; 
      }
    }  

    // Read from the cache first
    $cacheKey = md5("CALL spGetErrResources('$lang','EXTDES')");
    $aErrResources = $cache->getJ($cacheKey);
    if (!$aErrResources) {

      $db = &DB::getInstance();
      
      $sSQL = "CALL spGetErrResources(?, ?)";

      $aErrResources = $db->select_SP($sSQL, [
          ["s", $lang],
          ["s", "EXTDES"]
      ]);
    }
    // Store the data into the cache
    $cache->setJ($cacheKey, $aErrResources, 0, CACHE_EXPIRE);

    if (!empty($aErrResources)) {
      foreach ($aErrResources as &$res) {    
        //echo "Loading.." . $res['key'] . " = " . $res['value'] . "<br>";
        self::$A_ERR_EXTDES_MSG[$res['key']] = $res['value']; 
      }
    } 
     * 
     */
      
  }

  /**
   * Get an instance of the resources object
   * 
   * @return object
   */
  private static function &getInstance(): Err 
  {
    if (!isset(self::$_instance)) {
      self::$_instance = new Err();
    }
    return self::$_instance;
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
    unset(self::$_instance);
  }

  /**
   * Load the error descriptions and other constants
   * 
   * @return void 
   */
  public static function load(): void
  {
      self::getInstance();
  }
  
  /**
   * Set the default error and exception handlers 
   *
   * @return void
   * @access public
   */ 
  public static function setDefaultHandlers(): void 
  {
    // Assigning the error handling function..
  
    // Load the error resources..
    self::load();

    // Saving reference to the current error handler..
    self::$_old_error_handler = "setDefaultHandlers";
    self::$_old_error_handler_param1 = null;
    self::$_old_error_handler_param2 = null;
    
    /**
     * Error handling function
     *
     * @param string $errNo the number of the error
     * @param string $errMsg the error message
     * @param string $errScript the script where the error happened
     * @param integer $errLine the line of code of the error
     * @return bool
     */
    self::$_trigger_error1 = static function ($errNo, ?string $errMsg, ?string $errScript, ?int $errLine): bool 
    {

      $errKey = array_search($errNo, self::$A_ERR_NO);

      // Log error
      //$logfilename = ini_get("error_log");
      //if (is_writable($logfilename)) {
       // $logdata = "";
       // date format: [18-Sep-2016 11:18:47 Europe/Rome]  
       // $logdata .= "[" . date("d-M-Y H:i:s e") . "]" . " " . strtoupper(APP_NAME) . " " . "+++ERROR ($errNo): $errMsg : in script $errScript, line $errLine\n";
       // $logdata .= "[" . date("d-M-Y H:i:s e") . "]" . " " . strtoupper(APP_NAME) . " " . "Ending script...\n";
       // file_put_contents($logfilename, $logdata, FILE_APPEND);
      //}  

      error_log(strtoupper(APP_NAME) . " " . "+++ERROR ($errNo): $errMsg : in script $errScript, line $errLine");

      // Logging the stack trace..
      $aDebugTrace = debug_backtrace();
      
      if (count($aDebugTrace)>0) {
        
        $aDebugTrace = array_reverse($aDebugTrace);
        array_pop($aDebugTrace); // "<-- closure()
        //array_pop($aDebugTrace); // "<-- trigger_error()
        
        error_log(strtoupper(APP_NAME) . " " . "+++Stack trace:");

        $i = 1;
        foreach ($aDebugTrace as $trace) {
          error_log(strtoupper(APP_NAME) . " " . "+++" . $i . " " . $trace['function'] . "()" . " " . ((isset($trace['file'])) ? $trace['file'] . ":" : "") . isset1($trace['line'], ""));
          $i=$i+1;
        }
      }

      error_log(strtoupper(APP_NAME) . " " . "+++Ending script...");


      // Display error
      if (DEBUG) {
        echo "ERROR ($errNo): "  . Page::HTMLencode($errMsg, true) . ": in script $errScript, line $errLine<br>";

        // Printing the stack trace..
        if (count($aDebugTrace)>0) {
        
          echo "Stack trace:" . "<br>";
          
          $i = 1;
          foreach ($aDebugTrace as $trace) {
            echo $i . " " . $trace['function'] . "()" . " " . ((isset($trace['file'])) ? $trace['file'] . ":" : "") . isset1($trace['line'], "") . "<br>";
            $i=$i+1;
          }
        }
        
      } else {
        if (isset(self::$A_ERR_MSG[$errKey])) { 
          echo Page::HTMLencode(self::$A_ERR_MSG[$errKey], true) . " in script " . basename($errScript) . ", line $errLine<br>";
        } else { 
          echo "Unexpected Error in script ".  basename($errScript) . ", line $errLine<br>";
        } 
      }
      echo "Ending script...<br>";
      
      if (!TESTING) {
        exit(1);
      } else {
        throw new Exception($errMsg);
      }
      
      return true;
    };

    // Registering the error handling function..
    set_error_handler(self::$_trigger_error1);
    
    
    // Assigning the exception handling function..
    
    /**
     * Exception handling function
     *
     * @param Exception $e the exception thrown
     * @return void
     */
    self::$_throw1 = static function (\Throwable $e): void 
    {
  
      $errNo=$e->getCode(); 
      $errMsg=$e->getMessage();
      $errScript=$e->getFile();
      $errLine=$e->getLine(); 

      $errKey = array_search($errNo, self::$A_ERR_NO);

      // Log error
      //$logfilename = ini_get("error_log");
      //if (is_writable($logfilename)) {
       // $logdata = "";
       // date format: [18-Sep-2016 11:18:47 Europe/Rome]  
        //$logdata .= "[" . date("d-M-Y H:i:s e") . "]" . " " . strtoupper(APP_NAME) . " " . "+++ERROR ($errNo): $errMsg : in script $errScript, line $errLine\n";
        //$logdata .= "[" . date("d-M-Y H:i:s e") . "]" . " " . strtoupper(APP_NAME) . " " . "Ending script...\n";
        //file_put_contents($logfilename, $logdata, FILE_APPEND);
      //}

      error_log(strtoupper(APP_NAME) . " " . "+++ERROR ($errNo): $errMsg : in script $errScript, line $errLine");

      // Logging the stack trace..
      $aDebugTrace = $e->getTrace();
      
      if (count($aDebugTrace)>0) {
 
        $aDebugTrace = array_reverse($aDebugTrace);
        
        error_log(strtoupper(APP_NAME) . " " . "+++Stack trace:");

        $i = 1;
        foreach ($aDebugTrace as $trace) {
          error_log(strtoupper(APP_NAME) . " " . "+++" . $i . " " . $trace['function'] . "()" . " " . ((isset($trace['file'])) ? $trace['file'] . ":" : "") . isset1($trace['line'], ""));
          $i=$i+1;
        }
      }

      error_log(strtoupper(APP_NAME) . " " . "+++Ending script...");

      // Display error
      if (DEBUG) {
        echo "ERROR ($errNo): " . Page::HTMLencode($errMsg, true) . ": in script $errScript, line $errLine<br>";

        // Printing the stack trace..
        if (count($aDebugTrace)>0) {
 
          echo "Stack trace:" . "<br>";
          
          $i = 1;
          foreach ($aDebugTrace as $trace) {
            echo $i . " " . $trace['function'] . "()" . " " . ((isset($trace['file'])) ? $trace['file'] . ":" : "") . isset1($trace['line'], "") . "<br>";
            $i=$i+1;
          }
        }
        
      } else {
        if (isset(self::$A_ERR_MSG[$errKey])) { 
          echo Page::HTMLencode(self::$A_ERR_MSG[$errKey], true) . " in script " . basename($errScript) . ", line $errLine<br>";
        } else { 
          echo "Unexpected Error in script ".  basename($errScript) . ", line $errLine<br>";
        } 
      }
      echo "Ending script...<br>";

      if (!TESTING) {
        exit(1);
      } else {
        throw new Exception($errMsg);
      }

    };
    
    // Registering the exception handling function
    set_exception_handler(self::$_throw1);
    
  }

  /**
   * Set the error handlers to redirect to a page 
   *
   * @param  string  $landingPage the landing page to redirect to
   * @param  string  $queryString additional query string to pass in the redirect
   * @return void
   * @access public
   */ 
  public static function setRedirectHandlers(string $landingPage, ?string $queryString = ""): void 
  {

    // Assigning the error handling function..
    
    // Load the error resources..
    self::load();

    // Saving reference to the current error handler..
    self::$_old_error_handler = "setRedirectHandlers";
    self::$_old_error_handler_param1 = $landingPage;
    self::$_old_error_handler_param2 = $queryString;

    /**
     * Error handling function
     *
     * @param string $errNo the number of the error
     * @param string $errMsg the error message
     * @param string $errScript the script where the error happened
     * @param integer $errLine the line of code of the error
     * @return bool
     */
    self::$_trigger_error1 = static function ($errNo, string $errMsg, ?string $errScript, ?int $errLine) use ($landingPage, $queryString): bool 
    {
      
      // Log error
      //$logfilename = ini_get("error_log");
      //if (is_writable($logfilename)) {
        //$logdata = "";
        // date format: [18-Sep-2016 11:18:47 Europe/Rome]        
        //$logdata .= "[" . date("d-M-Y H:i:s e") . "]" . " " . strtoupper(APP_NAME) . " " . "ERROR ($errNo): $errMsg : in script " . $errScript . ", line $errLine\n";
        //$logdata .= "[" . date("d-M-Y H:i:s e") . "]" . " " . strtoupper(APP_NAME) . " " . "Redirecting...\n";
        //file_put_contents($logfilename, $logdata, FILE_APPEND);
      //}

      error_log(strtoupper(APP_NAME) . " " . "ERROR ($errNo): $errMsg : in script " . $errScript . ", line $errLine");
      
      // Logging the stack trace..
      $aDebugTrace = debug_backtrace();
      
      if (count($aDebugTrace)>0) {
        
        $aDebugTrace = array_reverse($aDebugTrace);
        array_pop($aDebugTrace); // "<-- closure()
        //array_pop($aDebugTrace); // "<-- trigger_error()
        
        error_log(strtoupper(APP_NAME) . " Stack trace:");

        $i = 1;
        foreach ($aDebugTrace as $trace) {
          error_log(strtoupper(APP_NAME) . " " . $i . " " . $trace['function'] . "()" . " " . ((isset($trace['file'])) ? $trace['file'] . ":" : "") . isset1($trace['line'], ""));
          $i=$i+1;
        }
      }
      
      error_log(strtoupper(APP_NAME) . " " . "Redirecting...");

      //Redirect with error..
      if (DEBUG || ADMIN) { 
        
        //Buffering stack trace..
        $errStack = "";
        if (count($aDebugTrace)>0) {
        
          $errStack = "Stack trace:" . "<br>";
          
          $i = 1;
          foreach ($aDebugTrace as $trace) {
            $errStack .= $i . " " . $trace['function'] . "()" . " " . ((isset($trace['file'])) ? $trace['file'] . ":" : "") . isset1($trace['line'], "") . "<br>";
            $i=$i+1;
          }
        }
        
        Page::redirect($landingPage . (stripos($landingPage, "?")>0 ? "&" : "?") . "uid=" . uniqid(rand(), true) . ($queryString!="" ? "&". $queryString : "") . "&errNo=" . urlencode($errNo) . "&errMsg=" . urlencode($errMsg) . "&errScript=" . urlencode($errScript) . "&errLine=" . urlencode($errLine) . "&errStack=" . urlencode($errStack));
      } else {
        Page::redirect($landingPage . (stripos($landingPage, "?")>0 ? "&" : "?") . "uid=" . uniqid(rand(), true) . ($queryString!="" ? "&". $queryString : "") . "&errNo=" . urlencode($errNo));
      }  

      if (!TESTING) {
        exit(1);
      } else {
        throw new Exception($errMsg);
      }
      
      return true;
    };

    // Registering the error handling function..
    set_error_handler(self::$_trigger_error1);
    
    
    // Assigning the exception handling function..
    
    /**
     * Exception handling function
     *
     * @param Exception $e the exception thrown
     * @return void
     */
    self::$_throw1 = static function (\Throwable $e) use ($landingPage, $queryString): void
    {
  
      $errNo=$e->getCode(); 
      $errMsg=$e->getMessage();
      $errScript=$e->getFile();
      $errLine=$e->getLine(); 

      // Log error
      //$logfilename = ini_get("error_log");
      //if (is_writable($logfilename)) {
       // $logdata = "";
       // date format: [18-Sep-2016 11:18:47 Europe/Rome]  
       // $logdata .= "[" . date("d-M-Y H:i:s e") . "]" . " " . strtoupper(APP_NAME) . " " . "ERROR ($errNo): $errMsg : in script $errScript, line $errLine\n";
       // $logdata .= "[" . date("d-M-Y H:i:s e") . "]" . " " . strtoupper(APP_NAME) . " " . "Ending script...\n";
        //file_put_contents($logfilename, $logdata, FILE_APPEND);
      //}

      error_log(strtoupper(APP_NAME) . " " . "ERROR ($errNo): $errMsg : in script " . $errScript . ", line $errLine");
      
      // Logging the stack trace..
      $aDebugTrace = $e->getTrace();
      
      if (count($aDebugTrace)>0) {
 
        $aDebugTrace = array_reverse($aDebugTrace);
        
        error_log(strtoupper(APP_NAME) . " Stack trace:");

        $i = 1;
        foreach ($aDebugTrace as $trace) {
          error_log(strtoupper(APP_NAME) . " " . $i . " " . $trace['function'] . "()" . " " . ((isset($trace['file'])) ? $trace['file'] . ":" : "") . isset1($trace['line'], ""));
          $i=$i+1;
        }
      }
        
      error_log(strtoupper(APP_NAME) . " " . "Redirecting...");

      //Redirect with error..
      if (DEBUG || ADMIN) { 

        //Buffering stack trace..
        $errStack = "";
        if (count($aDebugTrace)>0) {
        
          $errStack = "Stack trace:" . "<br>";
          
          $i = 1;
          foreach ($aDebugTrace as $trace) {
            $errStack .= $i . " " . $trace['function'] . "()" . " " . ((isset($trace['file'])) ? $trace['file'] . ":" : "") . isset1($trace['line'], "") . "<br>";
            $i=$i+1;
          }
        }

        Page::redirect($landingPage . (stripos($landingPage, "?")>0 ? "&" : "?") . "uid=" . uniqid(rand(), true) . ($queryString!="" ? "&". $queryString : "") . "&errNo=" . urlencode($errNo) . "&errMsg=" . urlencode($errMsg) . "&errScript=" . urlencode($errScript) . "&errLine=" . urlencode($errLine) . "&errStack=" . urlencode($errStack));
      } else {
        Page::redirect($landingPage . (stripos($landingPage, "?")>0 ? "&" : "?") . "uid=" . uniqid(rand(), true) . ($queryString!="" ? "&". $queryString : "") . "&errNo=" . urlencode($errNo));
      }   

      if (!TESTING) {
        exit(1);
      } else {     
        throw new Exception($errMsg);
      }
    };
    
    // Registering the exception handling function
    set_exception_handler(self::$_throw1);
  }
  
  /**
   * Set the error handlers to json  
   *
   * @return void
   * @access public
   */ 
  public static function setJSONHandlers(): void 
  {

    // Assigning the error handling function..
    
    // Load the error resources..
    self::load();

    // Saving reference to the current error handler..
    self::$_old_error_handler = "setJSONHandlers";
    self::$_old_error_handler_param1 = null;
    self::$_old_error_handler_param2 = null;

    /**
     * Error handling function
     *
     * @param string $errNo the number of the error
     * @param string $errMsg the error message
     * @param string $errScript the script where the error happened
     * @param integer $errLine the line of code of the error
     * @return bool
     */
    self::$_trigger_error1 = static function ($errNo, string $errMsg, ?string $errScript, ?int $errLine): bool 
    {
      
      // Log error
      //$logfilename = ini_get("error_log");
      //if (is_writable($logfilename)) {
      //  $logdata = "";
        // date format: [18-Sep-2016 11:18:47 Europe/Rome]        
      //  $logdata .= "[" . date("d-M-Y H:i:s e") . "]" . " " . strtoupper(APP_NAME) . " " . "ERROR ($errNo): $errMsg : in script " . $errScript . ", line $errLine\n";
      //  $logdata .= "[" . date("d-M-Y H:i:s e") . "]" . " " . strtoupper(APP_NAME) . " " . "Redirecting...\n";
      //  file_put_contents($logfilename, $logdata, FILE_APPEND);
      //}

      error_log(strtoupper(APP_NAME) . " " . "ERROR ($errNo): $errMsg : in script " . $errScript . ", line $errLine");

      // Logging the stack trace..
      $aDebugTrace = debug_backtrace();
      
      if (count($aDebugTrace)>0) {
        
        $aDebugTrace = array_reverse($aDebugTrace);
        array_pop($aDebugTrace); // "<-- closure()
        //array_pop($aDebugTrace); // "<-- trigger_error()
        
        error_log(strtoupper(APP_NAME) . " Stack trace:");

        $i = 1;
        foreach ($aDebugTrace as $trace) {
          error_log(strtoupper(APP_NAME) . " " . $i . " " . $trace['function'] . "()" . " " . ((isset($trace['file'])) ? $trace['file'] . ":" : "") . isset1($trace['line'], ""));
          $i=$i+1;
        }
      }
      
      error_log(strtoupper(APP_NAME) . " " . "Ending Json...");
     
      //Json encode the error..
      if (DEBUG || ADMIN) { 
        
        //Buffering stack trace..
        $errStack = "";
        if (count($aDebugTrace)>0) {
        
          $errStack = "Stack trace:" . "<br>";
          
          $i = 1;
          foreach ($aDebugTrace as $trace) {
            $errStack .= $i . " " . $trace['function'] . "()" . " " . ((isset($trace['file'])) ? $trace['file'] . ":" : "") . isset1($trace['line'], "") . "<br>";
            $i=$i+1;
          }
        }
        
        echo json_encode([$errNo, $errMsg, $errScript, $errLine, $errStack]);
      } else {
        echo json_encode([$errNo]);
      }  

      if (!TESTING) {
        exit(1);
      } else {
        throw new Exception($errMsg);
      }
      
      return true;
    };
    
    // Registering the error handling function..
    set_error_handler(self::$_trigger_error1);
    
    
    // Assigning the exception handling function..
    
    /**
     * Exception handling function
     *
     * @param Exception $e the exception thrown
     * @return void
     */
    self::$_throw1 = static function (\Throwable $e): void 
    {
  
      $errNo=$e->getCode(); 
      $errMsg=$e->getMessage();
      $errScript=$e->getFile();
      $errLine=$e->getLine(); 

      // Log error
      //$logfilename = ini_get("error_log");
      //if (is_writable($logfilename)) {
      //  $logdata = "";
       // date format: [18-Sep-2016 11:18:47 Europe/Rome]  
      //  $logdata .= "[" . date("d-M-Y H:i:s e") . "]" . " " . strtoupper(APP_NAME) . " " . "ERROR ($errNo): $errMsg : in script $errScript, line $errLine\n";
      //  $logdata .= "[" . date("d-M-Y H:i:s e") . "]" . " " . strtoupper(APP_NAME) . " " . "Ending script...\n";
      //  file_put_contents($logfilename, $logdata, FILE_APPEND);
      //}

      error_log(strtoupper(APP_NAME) . " " . "ERROR ($errNo): $errMsg : in script " . $errScript . ", line $errLine");

      // Logging the stack trace..
      $aDebugTrace = $e->getTrace();
      
      if (count($aDebugTrace)>0) {
 
        $aDebugTrace = array_reverse($aDebugTrace);
        
        error_log(strtoupper(APP_NAME) . " Stack trace:");

        $i = 1;
        foreach ($aDebugTrace as $trace) {
          error_log(strtoupper(APP_NAME) . " " . $i . " " . $trace['function'] . "()" . " " . ((isset($trace['file'])) ? $trace['file'] . ":" : "") . isset1($trace['line'], ""));
          $i=$i+1;
        }
      }

      error_log(strtoupper(APP_NAME) . " " . "Ending Json...");

      //Json encode the error..
      if (DEBUG || ADMIN) { 

        //Buffering stack trace..
        $errStack = "";
        if (count($aDebugTrace)>0) {
        
          $errStack = "Stack trace:" . "<br>";
          
          $i = 1;
          foreach ($aDebugTrace as $trace) {
            $errStack .= $i . " " . $trace['function'] . "()" . " " . ((isset($trace['file'])) ? $trace['file'] . ":" : "") . isset1($trace['line'], "") . "<br>";
            $i=$i+1;
          }
        }

        echo json_encode([$errNo, $errMsg, $errScript, $errLine, $errStack]);
      } else {
        echo json_encode([$errNo]);
      }  

      if (!TESTING) {
        exit(1);
      } else {    
        throw new Exception($errMsg);
      }

    };
    
    // Registering the exception handling function
    set_exception_handler(self::$_throw1);
  
  }

  /**
   * Set the error handlers to log the error only  
   *
   * @return void
   * @access public
   */ 
  public static function setLogOnlyHandlers(): void 
  {

    // Assigning the error handling function..
    
    // Load the error resources..
    self::load();

    /**
     * Error handling function
     *
     * @param string $errNo the number of the error
     * @param string $errMsg the error message
     * @param string $errScript the script where the error happened
     * @param integer $errLine the line of code of the error
     * @return bool
     */
    self::$_trigger_error1 = static function ($errNo, string $errMsg, ?string $errScript, ?int $errLine): bool
    {
      
      // Log error
      //$logfilename = ini_get("error_log");
      //if (is_writable($logfilename)) {
      //  $logdata = "";
        // date format: [18-Sep-2016 11:18:47 Europe/Rome]        
      //  $logdata .= "[" . date("d-M-Y H:i:s e") . "]" . " " . strtoupper(APP_NAME) . " " . "ERROR ($errNo): $errMsg : in script " . $errScript . ", line $errLine\n";
      //  $logdata .= "[" . date("d-M-Y H:i:s e") . "]" . " " . strtoupper(APP_NAME) . " " . "Continuing...\n";
      //  file_put_contents($logfilename, $logdata, FILE_APPEND);
      //}
      
      error_log(strtoupper(APP_NAME) . " " . "ERROR ($errNo): $errMsg : in script " . $errScript . ", line $errLine");

      // Logging the stack trace..
      $aDebugTrace = debug_backtrace();
      
      if (count($aDebugTrace)>0) {
        
        $aDebugTrace = array_reverse($aDebugTrace);
        array_pop($aDebugTrace); // "<-- closure()
        //array_pop($aDebugTrace); // "<-- trigger_error()
        
        error_log(strtoupper(APP_NAME) . " Stack trace:");

        $i = 1;
        foreach ($aDebugTrace as $trace) {
          error_log(strtoupper(APP_NAME) . " " . $i . " " . $trace['function'] . "()" . " " . ((isset($trace['file'])) ? $trace['file'] . ":" : "") . isset1($trace['line'], ""));
          $i=$i+1;
        }
      }
      
      error_log(strtoupper(APP_NAME) . " " . "Continuing...");

      return true;
      
    };

    // Registering the error handling function..
    set_error_handler(self::$_trigger_error1);
    
    
    // Assigning the exception handling function..
    
    /**
     * Exception handling function
     *
     * @param Exception $e the exception thrown
     * @return void
     */
    self::$_throw1 = static function (\Throwable $e): void 
    {
  
      $errNo=$e->getCode(); 
      $errMsg=$e->getMessage();
      $errScript=$e->getFile();
      $errLine=$e->getLine(); 

      // Log error
      //$logfilename = ini_get("error_log");
      //if (is_writable($logfilename)) {
      //  $logdata = "";
       // date format: [18-Sep-2016 11:18:47 Europe/Rome]  
      //  $logdata .= "[" . date("d-M-Y H:i:s e") . "]" . " " . strtoupper(APP_NAME) . " " . "ERROR ($errNo): $errMsg : in script $errScript, line $errLine\n";
      //  $logdata .= "[" . date("d-M-Y H:i:s e") . "]" . " " . strtoupper(APP_NAME) . " " . "Ending script...\n";
      //  file_put_contents($logfilename, $logdata, FILE_APPEND);
      //}
      
      error_log(strtoupper(APP_NAME) . " " . "ERROR ($errNo): $errMsg : in script " . $errScript . ", line $errLine");

      // Logging the stack trace..
      $aDebugTrace = $e->getTrace();
      
      if (count($aDebugTrace)>0) {
 
        $aDebugTrace = array_reverse($aDebugTrace);
        
        error_log(strtoupper(APP_NAME) . " Stack trace:");

        $i = 1;
        foreach ($aDebugTrace as $trace) {
          error_log(strtoupper(APP_NAME) . " " . $i . " " . $trace['function'] . "()" . " " . ((isset($trace['file'])) ? $trace['file'] . ":" : "") . isset1($trace['line'], ""));
          $i=$i+1;
        }
      }
      
      error_log(strtoupper(APP_NAME) . " " . "Continuing...");
    };
    
    // Registering the exception handling function
    set_exception_handler(self::$_throw1);
  }

  /**
   * Set back the error handlers  
   *
   * @return void
   * @access public
   */ 
  public static function setPreviousHandlers(): void 
  {
    //restore_error_handler();
    //restore_exception_handler();
    
    // Restoring previous error handlers..
    if (self::$_old_error_handler === "setDefaultHandlers") {
      self::setDefaultHandlers();
    } else if (self::$_old_error_handler === "setRedirectHandlers") {
      self::setRedirectHandlers(self::$_old_error_handler_param1, self::$_old_error_handler_param2);
    } else if (self::$_old_error_handler === "setJSONHandlers") {
      self::setJSONHandlers();
    }
  }  
  
  /**
   * Error trigger 
   *
   * @param string $errNo the number of the error
   * @param string $errMsg the error message
   * @param string $errScript the script where the error happened
   * @param integer $errLine the line of code of the error
   * @return void
   * @access public
   */
  public static function trigger_error1($errNo, string $errMsg, ?string $errScript, ?int $errLine): bool 
  {
    $trigger_error1 = self::$_trigger_error1;
    
    $trigger_error1($errNo, $errMsg, $errScript, $errLine);
    
    return true;
  }
  
  /**
   * Exception trigger 
   *
   * @param Exception $e the exception to trigger
   * @return void
   * @access public
   */
  public static function throw1(\Throwable $e) 
  {
    $throw1 = self::$_throw1;
    
    $throw1($e);
  }
}
