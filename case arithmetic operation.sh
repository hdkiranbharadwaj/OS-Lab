#Arithmetic operation using case
#!/bin/bash
echo "Enter the 1st number"
read n1
echo "Enter the 2nd number"
read n2
echo "menu: 1.ADD 2.SUB 3.MUL 4.DIV 5.MOD"
echo "Enter the choice"
read ch
case $ch in
1) echo "Addition is :$((n1+n2))";;
2) echo "Subtraction is :$((n1-n2))";;
3) echo "Multiplication is :$((n1*n2))";;
4) echo "Division is :$((n1/n2))";;
5) echo "Modulus is :$((n1%n2))";;
*) echo "Enter valid choice";;
esac
