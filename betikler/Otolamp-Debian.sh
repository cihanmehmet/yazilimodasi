# 
#!/bin/bash
clear

 echo -e "\x1b[1m "
     echo -e " "
     echo -e " "
     echo -e "\x1b[36m Debian, Lamp & PhpMyadmin kurulumuna hoş geldiniz."
     echo -e " "
   
      

for i in {0..21} {0..16} ; do echo -en "\e[38;5;${i}m#\e[0m "; done; 
echo -e " "

  echo -e "\x1b[37m Kurulum Başlayacaktır. Devam etmek istiyormusunuz ? [E/H]"
echo -e ""

read secim
if [ $secim = "E" ]
then
echo -e "\x1b[1m "
echo -e "\x1b[31mLamp Kurulumu başlatılıyor...";
echo -e "\e[31m Bekleyiniz.. (Root degilseniz Lutfen Sifrenizi Giriniz.) \033[0m"
sudo apt-get install lamp-server^
echo -e "\x1b[1m "
echo -e "\x1b[31mLamp kuruldu phpmyadmin kuruluyor \033[0m"
echo "\e[31m Bekleyiniz.. (Root degilseniz Lutfen Sifrenizi Giriniz.)"
sudo apt-get install phpmyadmin
sudo ln -s /usr/share/phpmyadmin /var/www
echo -e "\e[31m  Kurulum tamamlandı tarayıcınız açılıyor. \033[0m"
/usr/bin/firefox -new-window http://localhost/
clear
echo -e "\x1b[1m "

echo -e "\e[7m»»»»»»»»»» UYGULAMA BASARIYLA KURULDU! «««««««««« \x1b[1m"
echo -e ""
for i in {0..21} {0..16} ; do echo -en "\e[38;5;${i}m#\e[0m "; done;
echo -e "\x1b[1m "
 echo -e ""
     echo -e "YAZILIM ODASI "
elif [ $secim = "H" ]
then
clear
echo -e "\x1b[1m "

echo -e "\e[7m»»»»»»»»»» UYGULAMA KAPATILDI! «««««««««« \x1b[1m"
echo -e ""
for i in {0..21} {0..16} ; do echo -en "\e[38;5;${i}m#\e[0m "; done;
echo -e "\x1b[1m "
 echo -e ""
   
exit;
else
	echo -e "\x1b[1m "
echo -e "\x1b[31m(E)vet veya (H)ayır diyiniz ! \033[0m";
echo -e " "
fi 
service apache2 restart

