<html>
<head>
  <script type="text/javascript" src="http://cloud.boltiot.com/static/js/boltCommands.js"></script>
</head>
<body>
<script type="text/javascript">
	var isOn = False;
    setKey('{{ApiKey}}','{{Name}}');
	setDebug(False);
</script>
<center>
<div class="imageContainer">
  <img id="myImage" onclick="changeImage()" src="/control?name={{Name}}&filename=bulboff.png" height="200" width="200">
  </div>
</center>


<script>
function changeImage() {
   // digitalWrite(0, LOW);
    //digitalWrite(0, HIGH);

    var image = document.getElementById('myImage');
    if (image.src.match("bulbon")) {
        digitalWrite(0, LOW);
        image.src = "/serveFile?name={{Name}}&filename=bulboff.png";
        
    } else {
        digitalWrite(0, HIGH);
        image.src = "/serveFile?name={{Name}}&filename=bulbon.gif";
    }
}
</script>

<style type="text/css">
  .imageContainer{
        position: absolute;
        width: 100px; /*the image width*/
        height: 100px; /*the image height*/
        left: 45%;
        top: 35%;
        margin-left: -50px; /*half the image width*/
        margin-top: -50px; /*half the image height*/
    }
</style>

</body>
</html>