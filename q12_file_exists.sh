#!/bin/bash

echo "Enter filename:"
read -r file

if [ -f "$file" ]; then
    echo "File exists"
else
    echo "File does not exist"
fi
