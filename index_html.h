char *index_html=R"(

<!DOCTYPE html>
<html lang="en"><head>
<title>servoVox - ESP32 Servo Tester</title>
<meta name="author" content="Erik Dorstel">
<meta name="generator" content="vi">
<meta name="repository" content="https://github.com/ErikDorstel/servoVox">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta charset="utf-8">
<style>
html { font-family:Arial; }
div  { background-color:#888888; color:#ffffff; border:0px; padding:0px; margin:0px; text-align:center; width:100%; user-select:none; display:inline-block; }
.x0a { background-color:#C0A0A0; padding:0.2em 0em 0.1em; width:100%; font-size:1.5em; }
.x0b { background-color:#C0A0A0; padding:0.1em 0em 0.2em; width:100%; font-size:1.2em; }
.x0  { background-color:#C0A0A0; padding:0.3em 0em; width:100%; font-size:1.4em; }
.x1  { background-color:#A0B0C0; padding:0.3em 0em; width:100%; font-size:1.4em; }
.x2  { background-color:#888888; padding:0.3em 0em; width:48%; font-size:1.4em; }
.x3  { background-color:#888888; padding:0.3em 0em; width:32%; font-size:1.4em; }
.x4  { background-color:#888888; padding:0.3em 0em; width:24%; font-size:1.4em; }
</style>
<script>

function SERVOinit() {
  servoFreq=50; servoValue=307; servoWidth=1.5; servoChan1=16; servoChan2=16;
  doRange(true); }

function doDisplay() {
  document.getElementById("freqBtn").innerHTML="Frequency "+servoFreq+" Hz ["+Math.round(1000/servoFreq*100)/100+" ms]";
  document.getElementById("valueBtn").innerHTML="Value "+servoValue+" / 4095";
  document.getElementById("widthBtn").innerHTML="Pulse Width "+servoWidth+" ms";
  if (servoChan1==16) { document.getElementById("chanBtn1").innerHTML="Channel 0-15"; }
  else { document.getElementById("chanBtn1").innerHTML="Channel "+servoChan1; }
  if (servoChan2==16) { document.getElementById("chanBtn2").innerHTML="0-15"; }
  else { document.getElementById("chanBtn2").innerHTML=servoChan2; } }

function freqDef() { servoFreq=50; doRange(true); }
function freqDec1() { servoFreq-=1; doRange(true); }
function freqInc1() { servoFreq+=1; doRange(true); }
function freqDec10() { servoFreq-=10; doRange(true); }
function freqInc10() { servoFreq+=10; doRange(true); }
function valueDef(ms) { servoValue=Math.round(4095/(1000/servoFreq)*ms); doRange(true); }
function valueDec1() { servoValue-=1; doRange(true); }
function valueInc1() { servoValue+=1; doRange(true); }
function valueDec10() { servoValue-=10; doRange(true); }
function valueInc10() { servoValue+=10; doRange(true); }
function valueDec100() { servoValue-=100; doRange(true); }
function valueInc100() { servoValue+=100; doRange(true); }
function chanDef1() { servoChan1=16; doRange(true); }
function chanDef2() { servoChan2=16; doRange(false); }
function chanDec() { servoChan2-=1; doRange(false); }
function chanInc() { servoChan2+=1; doRange(false); }
function chanSet() { servoChan1=servoChan2; doRange(true); }

function doRange(doSet) {
  if (servoFreq<40) { servoFreq=40; }
  if (servoFreq>500) { servoFreq=500; }
  if (servoValue<0) { servoValue=0; }
  if (servoValue>4095) { servoValue=4095; }
  if (servoValue>4095) { servoValue=4095; }
  if (servoChan2<0) { servoChan2=16; }
  if (servoChan2>16) { servoChan2=0; }
  servoWidth=Math.round((1000/servoFreq)/4095*servoValue*100)/100;
  doDisplay();
  if (doSet==true) { sendAJAX('setSERVO,'+servoChan1+','+servoFreq+','+servoValue); } }

function sendAJAX(value) {
  ajaxObj=new XMLHttpRequest; ajaxObj.open("GET",value,true); ajaxObj.setRequestHeader("Content-Type","application/x-www-form-urlencoded"); ajaxObj.send(); }

</script></head><body onload="SERVOinit();">

<div><div class="x0a">servoFox</div></div>
<div><div class="x0b">PCA9685 Servo Tester</div></div>

<div class="x1" onclick="location.replace('/chooseAP');">Choose WLAN AP</div></div>

<div>
<div><div class="x0">Set Servo Parameters</div></div>
<div><div class="x1" id="freqBtn" onclick="freqDef();"></div></div>
<div><div class="x4" onclick="freqDec10();">&#8722; 10</div>
     <div class="x4" onclick="freqDec1();">&#8722; 1</div>
     <div class="x4" onclick="freqInc1();">+ 1</div>     
     <div class="x4" onclick="freqInc10();">+ 10</div></div>
<div><div class="x1" id="valueBtn" onclick="valueDef(1.5);"></div></div>
<div><div class="x4" onclick="valueDec100();">&#8722; 100</div>
     <div class="x4" onclick="valueDec1();">&#8722; 1</div>
     <div class="x4" onclick="valueInc1();">+ 1</div>
     <div class="x4" onclick="valueInc100();">+ 100</div></div>
<div><div class="x2" onclick="valueDec10();">&#8722; 10</div>
     <div class="x2" onclick="valueInc10();">+ 10</div></div>
<div><div class="x1" id="widthBtn" onclick="valueDef(1.5);"></div></div>
<div><div class="x3" onclick="valueDef(0.75);">0.75</div>
     <div class="x3" onclick="valueDef(1.5);">1.5</div>
     <div class="x3" onclick="valueDef(2.25);">2.25</div></div>
<div><div class="x2" onclick="valueDef(1);">1</div>
     <div class="x2" onclick="valueDef(2);">2</div></div>
<div><div class="x4" onclick="valueDef(0.5);">0.5</div>
     <div class="x4" onclick="valueDef(1.25);">1.25</div>
     <div class="x4" onclick="valueDef(1.75);">1.75</div>
     <div class="x4" onclick="valueDef(2.5);">2.5</div></div>
<div><div class="x1" id="chanBtn1" onclick="chanDef1();"></div></div>
<div><div class="x4" id="chanBtn2" onclick="chanDef2();"></div>
     <div class="x4" onclick="chanDec();">&#8722;</div>
     <div class="x4" onclick="chanInc();">+</div>
     <div class="x4" onclick="chanSet();">Set</div></div>
</div>

</body></html>

)";
