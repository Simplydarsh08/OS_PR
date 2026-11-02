#!/bin/bash

# Create a sample file, then demonstrate copy, move, rename, and delete.
echo "Operating System Lab" > student.txt
cp student.txt copy.txt
mv copy.txt newfile.txt
mv newfile.txt renamed.txt
rm renamed.txt

echo "File operations completed successfully."
