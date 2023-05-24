<?php

/**
 * Copyright 2021, 2024 5 Mode
 *
 * This file is part of SnipSwap.
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
 * home.php
 * 
 * Page Home.
 *
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2016, 2024, 5 Mode
 */

use fivemode\fivemode\LinkUtil;


define('PAGE_TITLE', "SwapCode - Home");


function echo_label(string $label) {
  if (mb_strlen($label) > 25) {
    echo(left($label, 25) . "...");
  } else {
    echo($label);
  }
}

$q = substr(filter_input1(INPUT_GET, "q", FILTER_SANITIZE_QM)??"", 0, 100);

$splash = filter_input(INPUT_GET, "splash")??"";
$splash = strip_tags($splash);

$curLocale = APP_LOCALE;

?>

<script>
<?PHP if ($splash === "1"):?>
  firstaccess = 1; 
<?PHP else: ?> 
  firstaccess = 0; 
<?PHP endif ?> 

</script>

<?php require APP_SCRIPT_PATH . "/header.php";?>

<div id="linkContainer" cat="<?PHP echo($catMaskedPath);?>" ondragover="onDragOver(event);" ondrop="onDrop(this, event);">
<?php 
  //echo($q."=q***"); 
  //echo($catMaskedPath."=cat***"); 

  $allLinks = LinkUtil::getLinkList(PHP_STR, "*");

  $iLinkjs = 1;  
  $myCubeInitjs= "";
  foreach($allLinks as $ainallLink) {
    $newFormalName = $ainallLink['name'];
    $myCubeInitjs .= "cubes[" . $iLinkjs . "-1] = new myCube( 'Snip#". $iLinkjs . "', '" . $newFormalName . "', '" . APP_HOST . "');\n";
    $myCubeInitjs .= "cubes[" . $iLinkjs . "-1].start();\n";
    $iLinkjs++; 
  }

  $myCubeInitjs .= "totcubes=" . count($allLinks) . ";\n"; 
  
  $aLinks = LinkUtil::getLinkList($q, $catMaskedPath);
  
  $iLink = 0;  
  foreach($aLinks as $aLink) { 
    
    $order = 1; 
    foreach ($allLinks as $ainallLink) {
      if ($ainallLink['name'] === $aLink['name']) {
        break; 
      }
      $order++;
    }
    
    $serverName = $_SERVER['SERVER_NAME'];
    $relPath = "/#" . $aLink['title'];
    
    ?>
    
                     <div id="<?php echo($aLink['title']);?>" class="link-div" title="<?php echo($aLink['desc']); ?>" order="<?PHP echo($order);?>" onclick="selCube(this);openDetail()" draggable="true" ondragstart="onDragStart(this, event);" onmouseover="onMouseOver();">
                           <div class="link-title"><?php echo($aLink['title']); ?><div style="width:25px; float:right;" title="It's a beauty!"><a href="#" onclick="event.stopPropagation();selCube($(this).parent().parent().parent());storeBeauty('imgheart<?php echo($aLink['title']);?>');"><img id="imgheart<?php echo($aLink['title']);?>" src="/res/<?PHP echo(($aLink['beauty']==="0")?"un":"");?>heart.png" style="height:23px;"></a></div></div>
                           <a href="#"><img class="link-img" src="/res/code.png" alt="<?php echo($aLink['title']); ?>"></a><br>
                           <br>
                           &nbsp;<a class="link-link" href="http://<?php echo(str_replace(PHP_TILDE, PHP_SLASH, $aLink['link']));?>"><?php echo_label(str_replace(PHP_TILDE, PHP_SLASH, $aLink['label']));?></a><br>
                           <div style="position:relative;top:-25px;left:-2px;text-align:right;padding-right:1.5px;">
                             <a href="https://www.facebook.com/sharer/sharer.php?u=http://<?PHP echo("{$serverName}{$relPath}");?>&t=" onclick="javascript:window.open(this.href, '', 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes,height=300,width=600');return false;" target="_blank" title="Share on Facebook"><img src="/res/fb.png"></a>
                             <a href="https://twitter.com/share?url=http://<?PHP echo("{$serverName}{$relPath}");?>&text=" onclick="javascript:window.open(this.href, '', 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes,height=300,width=600');return false;" target="_blank" title="Share on Twitter"><img src="/res/twitter.png"></a>
                             <a href="whatsapp://send?text=http://<?PHP echo("{$serverName}{$relPath}");?>" data-action="share/whatsapp/share" onClick="javascript:window.open(this.href, '', 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes,height=300,width=600');return false;" target="_blank" title="Share on whatsapp"><img src="/res/whatsapp.png"></a>
                           </div>
                     </div>
 
      <?php 
           
      $iLink++;
  
   } ?>
 
 <?php 
  if (Empty($aLinks)) {
    echo("<div class=\"no-link\" style=\"width:250px; float:left; padding: 10px;\">no link found</div>");    
  }
 ?>
  
</div>

<div>
  <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
  <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
</div>

<?PHP echo("<script>$myCubeInitjs</script>"); ?>

                    <button id="modalButton1" type="button" class="btn btn-primary" style="display:none;" data-toggle="modal" data-target="#modal1">Button #1</button>

                    <div class="modal" tabindex="-1" role="dialog" id="modal1">
                      <div class="modal-dialog modal-lg my-modal-dialog" role="document">
                        <div class="modal-content my-modal-content">
                          <img src="/res/code.png" style="width:98%; vertical-align:top; opacity:0.2"></a>
                          <div style="position:absolute; top:10px; padding:50px;">
                             <table style="width:100%">
                              <tr>  
                                <td class="snip-detail-cell">Title:&nbsp;</td><td width="700px"><input class="snip-detail-field" id="snip-detail-title" name="txtTitle" type="text" value="" onkeyup="storeData(this)" readonly></td>
                             </tr>
                             <tr>  
                                <td class="snip-detail-cell">Description:&nbsp;</td><td width="700px"><input class="snip-detail-field" id="snip-detail-desc" name="txtDesc" type="text" value="" onkeyup="storeData(this)" readonly></td>
                             </tr>
                             <tr>
                                <td class="snip-detail-cell">Code:&nbsp;</td><td width="700px"><textarea class="snip-detail-field snip-code" id="snip-detail-code" name="txtCode" style="max-width:750px;height:350px;max-height:350px;" onkeyup="storeData(this)" readonly></textarea></td>
                              </tr>
                             <tr>
                                <td class="snip-detail-cell">Tags:&nbsp;</td><td width="700px"><input class="snip-detail-field" id="snip-detail-tags" name="txtTags" type="text" value="" onkeyup="storeData(this)" readonly></td>
                              </tr>
                              <tr>  
                                <td class="snip-detail-cell">Label (link):&nbsp;</td><td width="700px"><input class="snip-detail-field" id="snip-detail-label" name="txtLabel" type="text" value="" onkeyup="storeData(this)" readonly></td>
                             </tr>
                              <tr>  
                                <td class="snip-detail-cell">Link:&nbsp;</td><td width="700px"><input class="snip-detail-field" id="snip-detail-link" name="txtLink" type="text" value="" onkeyup="storeData(this)" readonly></td>
                             </tr>
                              <tr>  
                                <td class="snip-detail-cell">Email:&nbsp;</td><td width="700px"><input class="snip-detail-field" id="snip-detail-email" name="txtEmail" type="text" value="" onkeyup="storeData(this)" readonly></td>
                             </tr>
                             <tr>
                                <td class="snip-detail-cell">Cats:&nbsp;</td><td width="700px" style="padding-top:8px;font-weight:900;"><input class="snip-detail-field" id="snip-detail-cats" name="txtCats" type="text" value="" onkeyup="storeData(this)" readonly><br><span style="font-size:10px;border-top:8px solid transparent;">space separated snip categories, "~" for subcategories.</span></td>
                              </tr>
                              <tr style="display: none;">
                                <td class="snip-detail-cell">Guid:&nbsp;</td><td width="700px"><input class="snip-detail-field" id="snip-detail-guid" name="txtGuid" type="text" value="" readonly></td>
                              </tr>
                              <tr>
                                <td class="snip-detail-cell">Password:&nbsp;</td><td width="700px"><input class="snip-detail-field" id="snip-detail-password" name="txtPassword" type="text" value="" onkeyup="checkPwd(this)"></td>
                              </tr>
                             </table>
                             <input type="hidden" id="comp-pwd" value="">
                           </div> 
                        </div>
                        <div class="modal-toolbox" style="float:left;">
                          <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>   
                        </div>   
                      </div>  
                    </div> 

<script>
  
/*
  * Interaction code
  */
 
  var oldtthis; // Old cube

  var lineOldVal = ""; // Old value for a detail line
  var lineNewVal = ""; // New value for a detail line

  var dataChanged = false;

  /*
   * Select the given cube 
   * 
   * @param <interfaceEl> selected cube
   * @returns void
   */
  function selCube(tthis) {    

    _selCube(tthis);

  } 

  function checkPwd(tthis) {
    if (encryptSha2($(tthis).val()) === $("#comp-pwd").val()) {
      $("#snip-detail-title").prop("readonly", false);
      $("#snip-detail-desc").prop("readonly", false);
      $("#snip-detail-code").prop("readonly", false);
      $("#snip-detail-tags").prop("readonly", false);
      $("#snip-detail-label").prop("readonly", false);
      $("#snip-detail-link").prop("readonly", false);
      $("#snip-detail-email").prop("readonly", false);
      $("#snip-detail-cats").prop("readonly", false);
    }  
  }  

  /*
   * Get the data for the given detail / face
   * 
   * @param string xmlStr, the current cube xml data
   * @param string detail, the requested detail
   * @returns string, the detail data 
   */
  function getDetailData(xmlStr, detail) {

    var ret = "";
    var re;

    detail = detail.toLowerCase();

    xmlStr = xmlStr.replace('<?xml version="1.0" encoding="UTF-8"?>',"");
    xmlStr = xmlStr.replace('<details>',"");
    xmlStr = xmlStr.replace('</details>',"");
    xmlStr = xmlStr.replaceAll('\n',"|||999");
    xmlStr = xmlStr.replaceAll(String.fromCharCode(9), "");
    xmlStr = xmlStr.replaceAll(String.fromCharCode(10), "|||999");
    xmlStr = xmlStr.replaceAll(String.fromCharCode(13), "|||999");
    xmlStr = xmlStr.replaceAll("   ", "");
    xmlStr = xmlStr.replaceAll("  ", "");
    xmlStr = escape(xmlStr);
    //xmlStr = xmlStr.replaceAll('\n',"|99");
    //xmlStr = xmlStr.replaceAll(String.fromCharCode(10), "|99");
    //xmlStr = xmlStr.replaceAll(String.fromCharCode(13), "|99");
    xmlStr = xmlStr.replaceAll("%0A", "");
    xmlStr = xmlStr.replaceAll("%20%20%20%20%20", "");
    xmlStr = xmlStr.replaceAll("%20%20%20%20%", "");
    xmlStr = xmlStr.replaceAll("%20%20%", "");
    //xmlStr = unescape(xmlStr);
    //alert("xmlStr="+xmlStr);

    switch (detail) {
      case "snippet":
        re = new RegExp("detail%20face%3D%22snippet%22.+/cats", "igsu");
        break;
      case "contacts":
        re = new RegExp("detail%20face%3D%22contacts%22.+/email", "igsu");
        break;
      case "other info":
        re = new RegExp("detail%20face%3D%22other%20info%22.+/guid", "igsu");
        break;
      case "password":
        re = new RegExp("detail%20face%3D%22password%22.+/password", "igsu");
        break;
    }        
    s = re.exec(xmlStr);
    if (!s || s.length===0) {
      //ret = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Error! #1";
      alert("Error#1");
      return ret;
    }
    xmlStr = s[0];
    xmlStr = "<"+xmlStr+"></detail>";
    xmlStr = unescape(xmlStr);
    //alert(xmlStr);
    const parser = new DOMParser();
    const doc = parser.parseFromString(xmlStr, "text/xml");
    x = doc.getElementsByTagName("detail");
    if (x.length===0) {
      //ret = "Error! #2";
      alert("Error#2");
      return ret;
    }
    //ret += "<div style='padding:10px;'>";
    for (i = 0; i < x[0].childNodes.length; i++) {
      if (x[0].childNodes[i].nodeType === 1) {
        
        if (x[0].childNodes[i].nodeName === "code") {
          document.getElementById("snip-detail-" + x[0].childNodes[i].nodeName).innerHTML = htmlEncode(x[0].childNodes[i].textContent);
        } else if (x[0].childNodes[i].nodeName === "password") {
          document.getElementById("comp-pwd").value = htmlEncode(x[0].childNodes[i].textContent);
        } else if (x[0].childNodes[i].nodeName === "beauty") {
          // none  
        } else {
          //alert(x[0].childNodes[i].nodeName);
          document.getElementById("snip-detail-" + x[0].childNodes[i].nodeName).value = x[0].childNodes[i].textContent;
        }
        
      }  
    }
    //if ((detail==="pictures") || (detail==="menu")) {
    //  ret += "<div style='padding-left:80px;clear:both;'><br>you can use eg. Goolge Drive or Microsoft OneDrive to host your pictures.</div>"
    //}
    //ret += "</div>";
    return ret;
  }  
  

  /*
   * Store in the cube object the new data of the text control
   * 
   * @param {InterfaceEl} tthis, the text control under editing
   * @returns void     
   */ 
  function storeData(tthis) {

    lineNewVal = $(tthis).val();
    //alert(lineNewVal);

    nodeName = tthis.id;
    nodeName = nodeName.replace("snip-detail-","");
    //alert(nodeName);

    xmlStr = curcube.getxml();
    //$("#log").html($("#log").html() + "old=" + "/(\<" + nodeName + "\>).*(\<\/" + nodeName + "\>)/gs" + "\n");
    //$("#log").html($("#log").html() + "new=" + lineNewVal + "\n");
    //alert("<" + nodeName + ">" + lineNewVal + "</" + nodeName + ">");
    //re = "/(\<" + nodeName + "\>).*(\<\/" + nodeName + "\>)/gs";

    switch (nodeName) {
      case "title":
        re = /(\<title>).*(\<\/title>)/gs;
        break;
      case "desc":
        re = /(\<desc>).*(\<\/desc>)/gs;
        break;      
      case "code":
        re = /(\<code>\<\!\[CDATA\[).*(\]\]\>\<\/code>)/gs;
        break;
      case "tags":
        re = /(\<tags>).*(\<\/tags>)/gs;
        break;
      case "cats":
        re = /(\<cats>).*(\<\/cats>)/gs;
        break;
      case "label":
        re = /(\<label>).*(\<\/label>)/gs;
        break;
      case "link":
        re = /(\<link>).*(\<\/link>)/gs;
        break;
      case "email":
        re = /(\<email>).*(\<\/email>)/gs;
        break;
    }  

    xmlStr = xmlStr.replace(re, "$1" + lineNewVal + "$2");
    //xmlStr = xmlStr.replace("<" + nodeName + ">" + lineOldVal + "</" + nodeName + ">", "<" + nodeName + ">" + lineNewVal + "</" + nodeName + ">");
    //alert(xmlStr);

    curcube.xml = xmlStr;

    dataChanged = true;
  }


  function storeBeauty(beautyImageId) {

    var xmlStr = curcube.getxml();
    var beautyNewVal = "1";
    re = /(\<beauty>).*(\<\/beauty>)/gs;
    xmlStr = xmlStr.replace(re, "$1" + beautyNewVal + "$2");
    
    curcube.xml = xmlStr;

    $("#"+beautyImageId).attr("src","/res/heart.png");

    dataChanged = true;

  }


  function _saveData() {
    if (dataChanged) {
      curcube.savedata();
      dataChanged = false;
    }  
  }  

  setInterval("_saveData()", 1500);

  /*
   * Display the given data detail
   * 
   * @param <interfaceEl> selected cube
   * @returns void
   */
  function openDetail() {
    //alert(curcube.getxml());
    myhtml = getDetailData(curcube.getxml(), "snippet") + getDetailData(curcube.getxml(), "contacts") + getDetailData(curcube.getxml(), "other info") + getDetailData(curcube.getxml(), "password");
    $('#modalButton1').click();      
  }

</script>  

 <?php require APP_SCRIPT_PATH . "/footer.php";?>

