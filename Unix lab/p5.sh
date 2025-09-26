
#!/bin/bash
echo " enter filename "
read filename
echo " enter pattern "
read pat
if [ !-f "$filename" ]
then
echo " file doesnt exist "
fi
grep "$pat" "$filename"
if [ $? -eq 0 ]
then
echo " command executed "
else
echo " command not executed "
fi
