#Prime numbers in a given range
#!/bin/bash
echo "Enter the value of n : "
read n
echo "Prime numbers from 1 to $n are:"
echo
flag=0
for ((i=2;i<=$n;i++))
do
  for ((j=2;j<=$((i/2));j++))
  do
  	if [ $((i%j)) == 0 ]
   	then 
      flag=1
    	break
    fi
  done
  if [ $flag == 0 ]
  then 
  echo -ne "$i "
  fi
  flag=0
done
