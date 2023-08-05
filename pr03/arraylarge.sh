#!/bin/bash
echo "Enter the number of elements: "
read n
echo "Enter $n numbers: "
for ((i=0; i<n; i++))
do
   read numbers[$i]
done
largest=${numbers[0]}
for ((i=1; i<n; i++))
do
   if (( ${numbers[$i]} > largest ))
   then
      largest=${numbers[$i]}
   fi
done
echo "The largest number is: $largest"
