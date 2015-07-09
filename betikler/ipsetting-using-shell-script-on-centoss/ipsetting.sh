#!/bin/bash

if [ $# -eq 5 ]
then

echo ""
echo "Taking the backup and Changing the hostname from $(hostname) to $1 ..."

sed -i.bk "s/$(hostname)/$1/g" /etc/sysconfig/network

echo ""
echo "Backing up & Assigning the Static IP ..."
echo ""

cp /etc/sysconfig/network-scripts/ifcfg-$2 /etc/sysconfig/network-scripts/$2.bk

cat <<EOF > /etc/sysconfig/network-scripts/ifcfg-$2

DEVICE=$2
BOOTPROTO=static
IPADDR=$3.$4
NETMASK=255.255.255.0
GATEWAY=$3.$5
ONBOOT=yes
EOF

echo "Changing the dns ..."
echo ""

sed -i.bk "s/nameserver.*/nameserver $3.$5/" /etc/resolv.conf

echo "Adding $1 as hostname to the /etc/hosts file .."
echo ""

sed -i.bk "/$(hostname)$/d" /etc/hosts
echo "$3.$4 $1" >> /etc/hosts

echo "Restarting the Network Service, Please connect it using the new IP Address if you are using ssh ..."

service network restart

else

echo "Usage: ip.sh <hostname> <interface> <baseip> <ipaddress> <gateway/dns>"
echo "Example: ip.sh testname eth0 10.10.10 41 1"

fi
