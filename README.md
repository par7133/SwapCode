# SnipSwap
Swapping code like burgers? Here your p2p, drag-n-drop solution - GPL License

Hello and welcome to SnipSwap!<br>
	   
SnipSwap is a light, simple, "peer-to-peer" software for swapping snippets of code with others, by dran-n-drop.<br>
	   
SnipSwap is released under GPLv3 license, it is supplied AS-IS and we do not take any responsibility for its misusage.<br>

SnipSwap got built behind some cool features like object drag-n-drop between browser windows, full object serialization and xml.

First step, use the left side panel password field to create the hashed password to insert in the config file.<br>
	   
As you are going to run SnipSwap in the PHP process context, using a limited web server or phpfpm user, you must follow some simple directives for an optimal first setup:<br>

<ol>
  <li>Check the write permissions of your "data" (repo) folder in your web app private path; and set its path in the config file.</li>
  <li>Set the default Business Label, Link and Email of the stuff your are going to swap.</li>
  <li>Set the MAX_DFT_NEW_SNIP value stating the max number of snippet the app is going to initially create.</li>
  <li>In Public/js/cube-code.js, in mystart class method, check if you are using 'http' or 'https'.</li>	   
</ol>
     
Hope you can enjoy it and let us know about any feedback: <a href="mailto:my25mb@aol.com" style="color:#e6d236;">my25mb@aol.com</a>   

<b>Please note that version 2.0.5 > is incompatible with previous versions.</b>

###Screenshots:

![SnipSwap in action](/Public/res/Screenshot1.jpg)<br>
