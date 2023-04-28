#Reverse of the string
#!/bin/bash

echo "Enter a string : "
echo
read str
echo "the reverse of string using inbuilt function is : "
echo $str|rev
length=${#str}

for((i=$length-1;i>=0;i--))
do
REV=$REV${str:$i:1}
done


echo "The reverse of string using loop is :"
echo $REV

echo "To check Palindrome"

if [ "$str" = "$REV" ]
then 
	echo "$str is a palindrome"
else
	echo "$str is not a palindrome"
fi
