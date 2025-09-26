#!/bin/bash
#dcode=$1
#descriptor=$2
echo " enter designation code and descriptor "
read dcode descriptor
if [[ $dcode =~ ^[0-9]+$ ]]
then
if [[ $descriptor =~ ^[a-z,A-Z]+$ ]]
then
echo $dcode $descriptor |cat>design.txt
echo " $dcode $descriptor added successfully "
else
echo " $descriptor not an alphabetical string "
fi
else
echo " $dcode not a numerical character "
fi
echo " content in design.txt "
cat design.txt
