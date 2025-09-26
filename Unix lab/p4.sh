
#!/bin/bash
x=1
while [ $x -eq 1 ]
do
echo " enter your choice "
read ch
case $ch in
1)echo " file permission `ls -l $0| cut -d ' ' -f 1 `  ";;
2)echo " number of links `ls -l $0| cut -d ' ' -f 3 ` ";;
3)echo " owner info `ls -l $0| cut -d ' ' -f 4 ` ";;
4)echo " group info `ls -l $0| cut -d ' ' -f 6 ` ";;
5)echo " size `ls -l $0| cut -d ' ' -f 5 ` ";;
6)echo " month of creation `ls -l $0| cut -d ' ' -f 9 ` ";;
7)echo " time `ls -l $0| cut -d ' ' -f 7 ` ";;
8)echo " filename `ls -l $0| cut -d ' ' -f 8 ` ";;
*)echo " invalid choice ";;
esac
echo " do you want to continue? 1:yes 0:no "
read x
done
