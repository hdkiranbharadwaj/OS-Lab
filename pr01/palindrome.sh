#!/bin/bash
echo Enter the number
read n 
temp=$n
while((temp > 0))
do
  r=$((temp%10))
  rev=$((rev*10+r))
  temp=$((temp/10))
done
if [ $rev = $n ]
then echo "It is a palindrome"
else echo "It is not a palindrome"
fi
