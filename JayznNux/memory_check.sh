#!/bin/bash

# Define a variable for the header
TITLE="--- Top 5 Memory Consuming Processes ---"

echo $TITLE

#1. ps: Process status
#2. -eo: Select specific columns (pid, user, %mem, command)
#3. --sort=-%mem: Sort by memory usage descending
#4. head -n 6: Get the header + top 5 results
ps -eo pid,user,%mem,comm --sort=-%mem | head -n 6


echo "check complete. Investigate the PID if memory usage is too high."

