#Greatest of three numbers
#!/bin/bash
echo "Enter three number : "
read n1 
read n2 
read n3
if [[ $n1 >  $n2 && $n1 >  $n3 ]]
then echo "$n1 is the greatest"
else if [[ $n2 >  $n1 && $n2 >  $n3 ]] 
then echo "$n2 is the greatest"
else
	echo "$n3 is the greatest"	
fi
fi
