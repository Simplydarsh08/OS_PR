#!/bin/bash

echo "Enter first number:"
read -r a
echo "Enter second number:"
read -r b

if ! [[ "$a" =~ ^-?[0-9]+$ && "$b" =~ ^-?[0-9]+$ ]]; then
    echo "Please enter valid integers."
    exit 1
fi

echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
echo "Enter your choice:"
read -r ch

case "$ch" in
    1) echo "Result = $((a + b))" ;;
    2) echo "Result = $((a - b))" ;;
    3) echo "Result = $((a * b))" ;;
    4)
        if (( b == 0 )); then
            echo "Division by zero is not allowed."
            exit 1
        fi
        echo "Result = $((a / b))"
        ;;
    *) echo "Invalid Choice" ;;
esac
