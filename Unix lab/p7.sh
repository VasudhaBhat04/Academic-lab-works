
#!/bin/bash
echo " menu 1)who 2)whoami 3)ls 4)date 5)ps "
echo " enter your choice "
read ch
case $ch in
1)who;;
2)whoami;;
3)ls;;
4)date;;
5)ps;;
*)echo " invalid choice "
esac
