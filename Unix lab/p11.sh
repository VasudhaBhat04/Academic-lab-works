
#!/bin/bash
echo " enter the units consumed "
read unit
if [ $unit -gt 0 ] && [ $unit -le 50 ]
then
charge=$((75*unit/100))
elif [ $unit -gt 50 ] && [ $unit -le 150 ]
then
charge=$((75*50/100)+(($unit - 50)*1.30))
elif [ $unit -gt 150 ] && [$unit -le 250 ]
then
charge=$(( (75*50/100)+(100*130/100)+(($unit -150)*145/100) ))
else
charge=$(( (75*50/100)+(100*130/100)+(100*145/100)+(($unit-250)*155/100) ))
fi
bill_amt=$(( $charge *125/100 ))
echo " units consumed: $unit "
echo " charge:$charge "
echo " bill amount:$bill_amt "
