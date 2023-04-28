#Comparing two strings
#!/bin/bash
echo "Enter the String"
read str1 str2
if [ "$str1" = "$str2" ]
then 
echo "$str1 are equal $str2"
else if [ "$str1" \> "$str2" ]
then
echo "$str1 is greater then $str2"
else
echo "$str2 is greater than $str1"
fi
fi
