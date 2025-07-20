#!/bin/bash
echo " enter two numbers : "
read a b
echo " menu 1.addition 2.subtraction 3.multiplication 4.division 5.modular division "
echo " enter your choice "
read ch
case $ch in
1)c=$(( $a+ $b ))
echo " $a + $b =$c ";;
2)c=$(( $a- $b ))
echo " $a - $b =$c ";;
3)c=$(( $a* $b ))
echo " $a * $b =$c ";;
4)c=$(( $a/ $b ))
echo " $a / $b =$c ";;
5)c=$(( $a% $b ))
echo " $a % $b =$c ";;
*)echo "invalid choice ";;
esac