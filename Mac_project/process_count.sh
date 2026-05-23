#!/bin/bash

# 1. Count processes and store in a variable
# 'ps -e' list all, 'wc -l' counts lines
COUNT=$((COUNT - 1))

# 2. Subtract 1 for the header line
TOTAL_COUNT=$((COUNT -1))

# 3. Use the variable to print a message
echo "--- System Status Report ---"
echo "Current Total Processes: $TOTAL_COUNT"

# 4. Logical Check (Intro to 'if' statements)
if [ $TOTAL_COUNT -gt 100 ]; then
	echo "Warnig: System might be busy."
else
	echo "system is running light and clean."
fi

