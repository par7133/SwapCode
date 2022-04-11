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
 * dragndrop-code.js
 * 
 * Drg-n-drop Code for home.php.
 *
 * @author Daniele Bonini <my25mb@aol.com>
 * @copyrights (c) 2021, 2024, 5 Mode     
 */
gguid = "";

function onDragStart(tthis, e) {
  //e.preventDefault();
  tthisorder = parseInt($(tthis).attr("order"));
  //objName = document.getElementById("objName").value;
  //alert(tthisorder);
  jsonData = serialize( cubes[tthisorder-1] ) + window.name;
  //alert(jsonData);
  e.dataTransfer.setData('text/plain', jsonData);
  document.body.style.cursor="move";
}

function onDragOver(e) {
  e.preventDefault();
  const id = e.dataTransfer.getData('text/plain');
  document.body.style.cursor="pointer";     
}  

function onDragOverOff(e) {
  e.preventDefault();
  document.body.style.cursor="not-allowed";     
}  

function onDrop(tthis, e) {
  e.preventDefault();
  mys=e.dataTransfer.getData('text/plain');
  gguid=mys.substr(mys.length-64); 
  mys=mys.substr(0,mys.length-64);
  //alert(mys);
  //alert(cubes.length);
  
  newcube = deserialize(mys);

  g = window.name; //$(tthis).attr("guid");
  if (g === gguid) {
    alert("Operation not allowed in same window!");
    return;
  }
  
  curcat = $(tthis).attr("cat");
  n = totcubes + 1;

 //alert(curcat);

  bfound=false;
  var i;
  for (i=0;i<(n-1);i++) {
    if (cubes[i]) {
      if (cubes[i].getguid() === newcube.getguid()) {
        bfound=i;
        break;
      }
    } else {
      break;
    }  
  }  

  //alert(newcube.cats);
  //alert(newcube.cats.indexOf(curcat));
  if (curcat!=="*") {
    bcatfound = false;
    mycats = " " + newcube.cats + " ";
    if ((mycats.indexOf(curcat) === -1)) {
      newcube.cats += " " + curcat;      
      newcube.xml = updCubeXML(newcube.xml, "cats", newcube.cats);
    } else {
      bcatfound = curcat;
    }  
    //alert(newcube.cats);
  } else {
    bcatfound = true;
  }  
  //alert("bfound=" + bfound);
  //alert("bcatfound=" + bcatfound);
  
  if (bfound===false || bcatfound===false) {
  // if same GUID doesn't exists || or the drop happened for a new cat 
  
    if (bfound===false) {
      // if same GUID doesn't exists
      
      n=totcubes+1;
      
      // check for the same formalName, if exists
      bffound=false;
      var y;
      for (y=0;y<(n-1);y++) {
        if (cubes[y]) {
          if (cubes[y].formalName === newcube.formalName) {
            bffound=y;
            break;
          }
        } else {
          break;
        }  
      }  

      // if same formalName exists, I assign an other formalName to the new snip..
      if (bffound===false) {
      } else {  
        
        newcube.formalName += " (" + rnd(10000, 99999) + "-" + rnd(10000, 99999) + "-" + rnd(10000, 99999)  + "-" + rnd(10000, 99999) + ")";      
      }

      // I assign the new snip to the next el in the cubes array
      cubes[n-1] = newcube;
      
    } else {
      // if the drop happened for a new cat but the snip exists
      
      n=bfound+1;
      
      // I assign the new snip to the existing el in the cubes array
      cubes[bfound].xml = newcube.xml;
      
    }  
    //n = parseInt($(tthis).attr("size")) + 1;
  
    // I insert the the new snip in the GUI.. 
    
    newCube = "";
    newCube += "<div class='link-div' style='width:250px; float:left; padding: 10px; margin:5px;' title='" + newcube.desc + "' order='" + n + "' onclick='selCube(this);openDetail()' draggable='true' ondragstart='onDragStart(this, event);' onmouseover='onMouseOver();'>";
    newCube += "<div style='color:#ed6a43; padding-bottom:8px;'>" + newcube.title + "</div>";
    newCube += "<a href='#'><img src='/res/code.png' style='width:232px; height:124px; border:1px solid darkgray;' alt='" + newcube.title + "'></a><br>";
    newCube += "&nbsp;<a style='font-style:italic; color:green; font-size:10px; padding-top:5px;' href='http://" + newcube.link.replace(/~/g, "/") + "'>" + newcube.label.replace(/~/g, "/") + "</a><br>";
    newCube += "</div>";
    
    oldHtml = $(tthis).html();
    if (oldHtml.indexOf("no link found")>-1) {
      $(tthis).html(newCube);
    } else {
      $(tthis).html($(tthis).html() + newCube);
    }
    
  } else {
  // if same GUID exists..
  
    if (cubes[bfound].formalName !== newcube.formalName) {
      alert("A snip by the same GUID already exists. But it has a different name.");  
      return;
    }

    if (cubes[bfound].getpassword() === newcube.getpassword()) {
      pwd2 = prompt("password confirmation:");
      pwd2en = encryptSha2(pwd2);
      if (cubes[bfound].getpassword() !== pwd2en) {
        alert("A snip by the same GUID already exists. But you typed the wrong password to access it.");  
        return;
      }  
    } else {
      alert("A snip by the same GUID already exists.");  
      return;
    }  

    // I assign the snip to the existing el in the cubes array
    cubes[bfound].xml = newcube.xml;

    n=bfound+1;
  }

  cubes[n-1].savedata();

  if (n>totcubes) {
    totcubes = n;
  }

  document.body.style.cursor="normal";

}


function onDropOff(e) {
  e.preventDefault();
  document.body.style.cursor="not-allowed";
  e.stopPropagation();
}

function onMouseOver() {
  document.body.style.cursor="pointer";     
}
  

