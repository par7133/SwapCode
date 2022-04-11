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
 * headerContent.php
 * 
 * headerContent file.
 *
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2016, 2024, 5 Mode
 */

use fivemode\fivemode\CatUtil;


// VARIABLES AND FUNCTION DECLARATIONS

settype($q, "string");

// PARAMETERS VALIDATION AND NORMALIZATION

$q = (string)substr((string)filter_input1(INPUT_GET, "q", FILTER_SANITIZE_QM), 0, 100);
$catMaskedPath = (string)substr((string)filter_input(INPUT_GET, "catMaskedPath", FILTER_SANITIZE_STRING), 0, 100);
$platform = (string)substr((string)filter_input(INPUT_GET, "platform", FILTER_SANITIZE_STRING), 0, 1);

$styleTag = PHP_STR;

$cat1=PHP_STR;
$cat2=PHP_STR;
$cat3=PHP_STR;
$aCats=explode(PHP_TILDE, $catMaskedPath);
if(isset($aCats[0]) && ($aCats[0]!=="*")){
  $cat1=$aCats[0];
}
if(isset($aCats[1])){
  $cat2=$aCats[1];
}
if(isset($aCats[2])){
  $cat3=$aCats[2];
}

//echo("catMaskedPath=" . $catMaskedPath . "<br>");
//echo("cat1=" . $cat1 . "<br>");
//echo("cat2=" . $cat2 . "<br>");
//echo("cat3=" . $cat3 . "<br>");

$aCats1 = CatUtil::getCatsList();

$aCats2 = CatUtil::getSubCatsList($cat1);

?>

<script>

  // show/hide the image preview of the search results  
  //var bHideResultsPreview = false; 

  $(document).ready(function() {

    $("div#linkOpenGallery").on("click", function (e) {
      e.preventDefault();
      e.stopPropagation();
      window.open("http://5mode.com","_blank");
    });

  }); 

  //
  // SEARCH FORM
  //
  $(document).ready(function() {

    $("#cbCategory1").on("change", function() {
      if ($(this).val() === "") {
        $("#cbCategory2").val("");
        window.open("/<?php echo($platform);?>/*", "_self");
      } else {
        window.open("/<?php echo($platform);?>/" + $(this).val(), "_self");
      }
    });

    $("#cbCategory2").on("change", function() {
      if ($(this).val() !== "") {
        if ($("#cbCategory1").val()!=="") {
          window.open("/<?php echo($platform);?>/" + $(this).val().replace("~","/"), "_self");
        }  
      } else {
        window.open("/<?php echo($platform);?>/" + $("#cbCategory1").val(), "_self");
      }
    });

    $("input#q").on("keydown",function(e) {
      key = e.which;
      if (key===13) {
        e.preventDefault();
        $("#butSearch-addon").click();
      } 
    });  
    
    $("#butSearch-addon").on("click",function(e) {
      e.preventDefault();
      //filterKeysQ(document.getElementById("q"));
      if ($("input#q").val()!=="") {
        //frmSearch.submit();  
        if ($("#cbCategory2").val() !== "") {
          if ($("#cbCategory1").val()!=="") {
            if ($("input#q").val()!=="") {
              window.open("/<?php echo($platform);?>/" + $("#cbCategory2").val().replace("~","/") + "?q=" + $("input#q").val(), "_self");
            } else {
              window.open("/<?php echo($platform);?>/" + $("#cbCategory2").val().replace("~","/"), "_self");
            }  
          }  
        } else if ($("#cbCategory1").val() !== "") {
          if ($("input#q").val()!=="") {
            window.open("/<?php echo($platform);?>/" + $("#cbCategory1").val() + "?q=" + $("input#q").val(), "_self");
          } else {
            window.open("/<?php echo($platform);?>/" + $("#cbCategory1").val(), "_self");
          }  
        } else {  
          window.open("/<?php echo($platform);?>/*" + "?q=" + $("input#q").val(), "_self");
        }
      }  
    });
    
  });
   
</script>

<div class="header" style="height: fit-content;" role="navigation" align="center">

  <?php 

      $GET_SCRIPT_NAME = basename(filter_input(INPUT_GET, "SCRIPT_NAME"));

      if (stripos(APP_SCRIPTS_WITHOUT_SEARCH_MENU, "|". $GET_SCRIPT_NAME . "|") || (mb_strrchr($GET_SCRIPT_NAME, PHP_UNDERSCORE, false) === "_a")) { 
  ?>
                            <div class="col-xs-12 col-sm-12 col-md-12 col-lg-12 col-strd">
                              <table class="header-table" align="center">
                                <tr>
                                  <td class="col-burger-menu-icon">
                                      <div id="burgerMenuIco" onclick="popupMenu()" style="position: relative; left:0px; border:0px solid blue; width: 48px; display:none;"><a id="aBurger-Menu" class="navbar-brand-nml" href="#" title="Tap here for options"><img src="/res/burger-menu2.png" width="42px"></a></div>
                                      <div id="logo-div" style="width:180px; position:relative; top:-52; margin-left:46%; color:#ed6a43;"><a href="/" style="color:#ed6e48;font-size:30px;font-style:italic;font-weight:900;"><?php echo(strtoupper(APP_NAME));?></a></div> 
                                  </td>    
                                </tr>
                              </table>
                            </div>
  
  <?php } else { ?>

                          <div class="col-strd">

                            <table class="col-xs-12 col-sm-10 col-md-10 col-lg-10 header-table" align="center">
                              <tr>
                                <td class="col-burger-menu-icon">
                                   <div id="burgerMenuIco" onclick="popupMenu()" style="position: absolute; left:+10px; top:+4px; border:0px solid blue; width: 46px; display:none;"><a id="aBurger-Menu" class="navbar-brand-nml" href="#" title="Tap here for options"><img src="/res/burger-menu2<?php echo($styleTag);?>.png" width="42px"></a></div>
                                </td>    
                                <td align="left" style="text-align:center;">

                                    <div id="logo-div" style="width:180px; position:relative; top:-55; left:-44px; margin-left:46%; color:#ed6a43;"><a href="/" style="color:#ed6e48;font-size:30px;font-style:italic;font-weight:900;"><!--<?php echo(APP_NAME);?>--></a></div>
                                  
                                      <form id="frmSearch" style="width:200px; float:left; position:relative; top:+15px; left:+25px; " role="search" method="get" action="/search" target="_self">
                                                                           
                                                <select id="cbCategory1" class="form-control input-search" style="width:200px; position:relative; top:+1px;">
                                                    <option value=""></option>
                                                    <?php foreach($aCats1 as $cat) { ?>
                                                    <option value="<?php echo($cat);?>" <?php echo($cat1 === $cat ? "selected": "");?>><?php echo($cat);?></option>
                                                    <?php } ?>
                                                </select> 

                                                <br>

                                                <select id="cbCategory2" class="form-control input-search" style="width:200px; position:relative; top:-10px;">
                                                    <option value=""></option>
                                                    <?php foreach($aCats2 as $cat) { 
                       $ipos=strripos($cat, PHP_TILDE);            
                       $displayText=substr($cat,$ipos+1); ?>
                                                    <option value="<?php echo($cat);?>" <?php echo($cat2 === strtolower($displayText) ? "selected": "");?>><?php echo($displayText);?></option>
                                                    <?php } ?>
                                                </select> 
                                        
                                               <div class="input-group">

                                                  <input id="q" name="q" type="search" class="form-control input-search" style="font-style: italic;" value="<?php echo $q;?>" maxlength="100" placeholder="SEARCH" title="Type here the search text" autocomplete="off" spellcheck="false" aria-describedby="butSearch-addon">
                                                  <span id="butSearch-addon" class="input-group-addon btn-search-addon btn-blue" title="Search"><span class="glyphicon glyphicon-search"></span></span>

                                                </div>
                                        
                                      </form> 
                                    
                                    <div id="form-ori-sep1" style="display:none;"><br><br></div>
                                    
                                     <img id="form-vert-bar" src="/res/pxl.gif" style="width:1px;height:160px;float:left;position:relative;left:+55px;background-color:gray;">
                                    
                                     <div id="catList" style="width:70%;float:left;position:relative;top:14px;left:75px;">
                                      <?php
                    $i=1;                   
                    if ($cat1===PHP_STR) {
                      foreach($aCats1 as $cat) { ?>
                                                              <div id="linkCat<?php echo($i);?>" class="cat-div"><a href="/<?php echo($platform);?>/<?php echo($cat);?>"><?php echo($cat);?></a></div>
                                                            <?php $i++; ?>  
                                            <?php } ?>
                                      <?php } else if ($cat2===PHP_STR) {
                      if (Empty($aCats2)) {
                        echo("<div  class=\"cat-div\" style=\"width:200px;background-color:transparent;\">no subcat found.</div>");
                      } else {                 
                        foreach($aCats2 as $cat) { 
                          $ipos=strripos($cat, PHP_TILDE);            
                          $displayText=substr($cat,$ipos+1); 
                          $link=PHP_SLASH . $platform . PHP_SLASH . str_replace(PHP_TILDE, PHP_SLASH, $cat);?>
                                                                <div id="linkCat<?php echo($i);?>" class="cat-div"><a href="<?php echo($link);?>"><?php echo($displayText);?></a></div>
                                                                <?php $i++; ?>
                                                <?php } ?>
                                           <?php } ?>                    
                                     <?php } else { 
                      echo("<div  class=\"cat-div\" style=\"width:200px;background-color:transparent;\">no subcat found.</div>");
                    } ?>
                                     </div>
                                     
                                </td>
                              </tr>
                            </table>

                          </div>

  <?php } ?>

</div>
