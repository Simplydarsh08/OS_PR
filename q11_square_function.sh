#!/bin/bash

square()
{
    echo "Square = $(( $1 * $1 ))"
}

echo "Enter a number:"
read -r n

if ! [[ "$n" =~ ^-?[0-9]+$ ]]; then
    echo "Please enter a valid integer."
    exit 1
fi

square "$n"
