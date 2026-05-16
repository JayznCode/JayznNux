#!/bin/bash

# Get the current date and time
NOW=$(date)
# Get the number of logged-in users
    User_COUBT=$(who | wc -l)

echo "Current Time: $NOW"
echo "Active Users: $USER_COUNT"




if [ $1 -gt 1 ]; then
    if [ $1 -lt 10 ]; then
        echo "The number is between 2 and 9."
    fi
fi



#Same as above but more 'Shell-style'
if [ $1 -gt 1 ] && [ $1 -lt 10 ]; then
    echo "This is much cleaner!"

fi

