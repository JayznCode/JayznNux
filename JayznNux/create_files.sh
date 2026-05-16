#!/bin/bash

# Check if an argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 [number of files]"
    exit 1
fi

COUNT=$1

echo "Creating $COUNT empty files..."

for i in $(seq 1 $COUNT)
do
    touch "file_$i.txt"
    echo "Created file_$i.txt"
done

echo "Done!"
