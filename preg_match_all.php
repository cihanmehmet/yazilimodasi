<html>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=utf8" />
</head>
<body>
<h2>
<?php
/*
$metin = "PHP ile Web Programlama";
if (preg_match("/Web/",$metin,$sonuc))
	print $sonuc[0];

*/


/*
$metin = "PHP ile Web Programlama";
if (preg_match("/^PHP/",$metin,$sonuc))
	print $sonuc[0];
*/

/*
$metin = "PHP ile Web Programlama";
if (preg_match("/lama$/",$metin,$sonuc))
	print $sonuc[0];
*/

/*
$metin = "Ümit Durus";
if (preg_match("/^Ümit Durus$/",$metin,$sonuc))
	print $sonuc[0];
*/

/*
$metin = "eLmA";
if (preg_match("/ELMA/i",$metin,$sonuc))
	print $sonuc[0];

*/
/*
$metin = "123wr4er5";
if (preg_match("/\D/",$metin,$sonuc))
	print $sonuc[0];
*/

/*
$metin = "123wr4er5";
if (preg_match("/\d/",$metin,$sonuc))
	print $sonuc[0];
*/
/*
// [0-9][a-z][A-Z]
$metin = "PHP ile Web 56Programlama";
if (preg_match("/[a-z]/",$metin,$sonuc))
	print $sonuc[0]; 
*/

/*
// [14] [agh]
$metin = "Kobay"; // Kolay, Kobay, Koray
if (preg_match("/Ko[lbr]ay/",$metin,$sonuc))
	print $sonuc[0]; 
*/

/*
$metin = "Kohtrtay";
if (preg_match("/K.+ay/",$metin,$sonuc))
	print $sonuc[0];
*/

/*
$metin = "armut:345";
if (preg_match("/[a-z]+\:[0-9]+/",$metin,$sonuc))
	print $sonuc[0];
*/

/*
$metin = "elmalar";
if (preg_match("/[a-z]{4}/",$metin,$sonuc))
	print $sonuc[0];
*/

/*
$metin = "123458";
//if (preg_match("/[5][7]/",$metin,$sonuc))
if (preg_match("/([5]|[7])/",$metin,$sonuc))
	print $sonuc[0];
*/

/*
$metin = "14:41:56";
if (preg_match("/^([0-1][0-9]|[2][0-3])\:(GERİSİNİ BUL)/",$metin,$sonuc))
	print $sonuc[0];
else
	print "Tarih formatı yanlış";
*/
	/*
$date="2012-09-29";

if (preg_match("/^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])$/",$date,$sonuc))
print $sonuc[0];
*/
/*
$metin = "14:41:56";
if (preg_match("/\d{2}\:\d{2}\:\d{2}/",$metin,$sonuc))
	print $sonuc[0];
*/

/*
$metin = "adem@gmail.com";
if (preg_match("/^([a-z]|[A-Z])([a-z]|[0-9])+\@([a-z]|[A-Z])+\.([a-z]|[A-Z])+/",$metin,$sonuc))
	print $sonuc[0];
else
	print "E posta formatı yanlış";
*/

$metin = "elma armut elma kiraz elma"; // Kolay, Kobay, Koray
if (preg_match_all("/elma/",$metin,$sonuc)){
	for ($i=0;$i<count($sonuc[0]);$i++){
		print $sonuc[0][$i];
		echo "<br/>";
	}
}

?>
</h2>
</body>
</html>
