#!/bin/bash
ch="y"
while [ $ch == 'y' ]
do
echo " enter item code and name "
read icode iname
echo  $icode $iname|cat>>items.txt
echo " $icode $iname added successfully "
echo " do u want to continue?y:yes n:no "
read ch
done
echo " items in the list "
cat items.txt
