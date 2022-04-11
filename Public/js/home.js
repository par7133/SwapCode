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
 * home.js
 * 
 * JS file for Home page
 *
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2016, 2024, 5 Mode
  */

 /*
  * Boot up code
  */

 //var fetchDataIntervalId;  

 /*
  * App starting proc
  * 
  * @returns void
  */
 function startApp() {

   window.name = encryptSha2(rnd(0,99999999)+"");
   
   $(document.body).css("background","#FFFFFF");
   $("#HCsplash").css("display","none");
   $(".body-area").show();
   $(".header2").show();
   
   //fetchDataIntervalId = setInterval("_fetchData()", 2000);
 }			

 /*
  * call to startApp
  * 
  * @returns void
  */
 function _startApp() {
   setTimeout("startApp()", 1000);    
 }
 

 window.addEventListener("load", function() {

   //Splash
   if (firstaccess===1) {
     $("#HCsplash").show();	
   }  
 
 }, true);
 
  window.addEventListener("load", function() {

   if (firstaccess===1) {
     $(document.body).css("background","#0d0d0d");
     $(".body-area").hide();

     // Fisnished the Intro load the app..
     setTimeout("_startApp()", 6000);
   } else {
     $("#HCsplash").hide();
     _startApp();     
   }
   
   // A bit of preload..

 });

 window.addEventListener("resize", function() {

   //if ($("#cubeList").css("display")==="none") {
   //  setTimeout("setFooterPos()", 9000);
   //} else {
   //  setTimeout("setFooterPos()", 2000);  
   //} 

 });

// -- End Boot up code


/*
 *  Display the current hash for the config file
 *  
 *  @returns void
 */
function showEncodedPassword() {
  if ($("#Password").val() === "") {
    $("#Password").addClass("emptyfield");
    return;  
  }
  passw = encryptSha2( $("#Password").val() );
  msg = "Please set your new pasword in the config file with this value:";
  alert(msg + "\n\n" + passw);	
}


function initLinkTooltip() {
  $("div.link-div").each(function(){
    $(this).tooltip({
      position: {
        my: "left+20 top+76",
        at: "left top",
        collision: "none"
      }
    });
  });
}


function setContentPosHome() {

  bodyRect = document.body.getBoundingClientRect();
  bodyRect.width = window.innerWidth;
  
  $(".snip-code").css("height", parseInt((window.innerHeight * 30) / 100) + "px");

  tollerance = 180;
  frmSearchRect = document.getElementById("frmSearch").getBoundingClientRect();
  catListRect = document.getElementById("catList").getBoundingClientRect();
  vertHeight = frmSearchRect.height + catListRect.height + tollerance;

  if (bodyRect.width < 740) {  
    $(".header").css("height",vertHeight);
    $("#logo-div").css("margin-left","39%");
    $("#frmSearch").css("left","");
    $("#frmSearch").css("float","none");
    $("#frmSearch").css("clear","both");
    $("#frmSearch").css("margin","auto");
    $("#form-vert-bar").hide();
    $("#form-ori-sep1").show();
    $(".link-div").css("float", "none");
    $(".link-div").css("clear", "both");
    $(".link-div").css("margin", "auto");
    $(".link-div").css("padding-left", "10px");
    $(".link-div").css("padding-right", "10px");
    $(".myxs").css("display", "none");
  } else if (bodyRect.width < 950) {
    $(".header").css("height",vertHeight);
    $("#logo-div").css("margin-left","39%");
    $("#frmSearch").css("left","-5%");
    $("#frmSearch").css("float","none");
    $("#frmSearch").css("clear","both");
    $("#frmSearch").css("margin","auto");
    $("#form-vert-bar").hide();
    $("#form-ori-sep1").show();
    $(".link-div").css("float", "left");
    $(".link-div").css("clear", "");
    $(".link-div").css("margin", "");
    $(".link-div").css("padding-left", "10px");
    $(".link-div").css("padding-right", "10px");
    $(".myxs").css("display", "inline");
  } else {
    $(".header").css("height","228px");
    $("#logo-div").css("margin-left","46%");
    $("#frmSearch").css("left","+25px");
    $("#frmSearch").css("float","left");
    $("#frmSearch").css("clear","none");
    $("#frmSearch").css("margin","");
    $("#form-vert-bar").show();
    $("#form-ori-sep1").hide();
    $(".link-div").css("float", "left");
    $(".link-div").css("clear", "");
    $(".link-div").css("margin", "");
    $(".link-div").css("padding-left", "10px");
    $(".link-div").css("padding-right", "10px");
    $(".myxs").css("display", "inline");
  }

}

window.addEventListener("load", function() {

  //setTimeout("initLinkTooltip()", 1500);
  setTimeout("setContentPosHome()", 1500);
  
}, true);

window.addEventListener("resize", function() {
  
  setTimeout("setContentPosHome()", 2000);
  
}, true);

