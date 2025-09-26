
#!/bin/bash
# create a empn list file first
echo  " EmpId\t Emp name\t Basic\t da\t hra\t gsal "
while read line
do
temp=$line
Id=$(cut -d "," -f 1 <<<$temp )
Name=$(cut -d "," -f 2 <<<$temp )
basic=$(cut -d "," -f 3 <<<$temp)
if [[ $basic =~ ^[0-9]+$ ]]
then
if [  $basic -gt 6000 ]
then
da=$((25*$basic/100))
else
da=$((30*$basic/100))
fi
hra=$((10*$basic/100))
gsal=$(($basic+$da+$hra))
echo  " $Id\t  $Name\t $basic\t $da\t $hra\t $gsal\t "
else
echo " invalid basic salary "
fi
done < emp.lst
