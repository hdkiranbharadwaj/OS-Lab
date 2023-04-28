#Reverse of the string
#!/bin/bash

echo "Enter a string : "
echo
read str
echo "the reverse of string using inbuilt function is : "
echo $str|rev
echo
length=${#str}
echo "Length of the string is $length"
