
#!/bin/bash
who | cut -d ' ' -f 1 |cat>user.txt
sort user.txt | uniq | cat>uniquser.txt
echo " enter user "
read $user
grep -i "$user" uniquser.txt
if [ $? -eq 0 ]
then
echo " same user logged in "
else
echo " user not found "
fi
