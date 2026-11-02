#!/bin/bash

echo "Enter a number:"
read -r n

if ! [[ "$n" =~ ^-?[0-9]+$ ]]; then
    echo "Please enter a valid integer."
    exit 1
fi

if (( n > 0 )); then
    echo "Positive Number"
elif (( n < 0 )); then
    echo "Negative Number"
else
    echo "Zero"
fi
