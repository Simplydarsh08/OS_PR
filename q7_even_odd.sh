#!/bin/bash

echo "Enter a number:"
read -r n

if ! [[ "$n" =~ ^-?[0-9]+$ ]]; then
    echo "Please enter a valid integer."
    exit 1
fi

if (( n % 2 == 0 )); then
    echo "Even Number"
else
    echo "Odd Number"
fi
