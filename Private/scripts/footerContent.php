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
 * footerContent.php
 * 
 * Content of the footer.
 *
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2016, 2024, 5 Mode
 */

use fivemode\fivemode\Page;

?>

<?php
  define("SCRIPT_NAME_FOOTER", pathinfo(__FILE__, PATHINFO_FILENAME));

?>  

<div id="footerCont">&nbsp;</div>
<div id="footer"><span style="background:#FFFFFF;opacity:0.7;">&nbsp;&nbsp;A <a id="linkOpenGallery" href="http://5mode.com">5 Mode</a> project and <a href="http://demo.5mode.com">WYSIWYG</a> system. Some rights reserved.</span></div>

</div>

<?php if (file_exists(APP_PATH . DIRECTORY_SEPARATOR . "skinner.html")): ?>
<?php include(APP_PATH . DIRECTORY_SEPARATOR . "skinner.html"); ?> 
<?php endif; ?>

<?php if (file_exists(APP_PATH . DIRECTORY_SEPARATOR . "metrics.html")): ?>
<?php include(APP_PATH . DIRECTORY_SEPARATOR . "metrics.html"); ?> 
<?php endif; ?>


   <?php Page::displayJSBuffer(); ?>
 
