#!/bin/bash

# Simple for loop to print numbers 1 to 5
for i in {1..5}
do
    if [ $i -eq 3 ]; then
        echo "Found the number three!"
    else
        echo "Number: $i"
    fi
done
