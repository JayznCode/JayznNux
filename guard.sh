#!/bin/bash

password=1234
chance=3

echo "--- Secure Login System (Shell) ---"

while true; do
    # 사용자로부터 입력 받기 (주소 & 따위 필요 없음!)
    read -p "Enter Password: " input

    if [ "$input" -eq "$password" ]; then
        echo "Access Granted! Welcome."
        break  # C언어와 똑같은 break!
    else
        ((chance--))
        echo "Access Denied! (Remaining: $chance)"

        if [ $chance -le 0 ]; then
            echo "Too many failed attempts. System Locked!"
            break
        fi
    fi
done

