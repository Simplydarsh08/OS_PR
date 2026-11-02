#!/bin/bash

echo "Enter a number:"
read -r n

if ! [[ "$n" =~ ^[0-9]+$ ]]; then
    echo "Please enter a non-negative integer."
    exit 1
fi

fact=1
for ((i = 1; i <= n; i++)); do
    fact=$((fact * i))
done

echo "Factorial = $fact"
