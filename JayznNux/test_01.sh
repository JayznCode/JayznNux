#!/bin/bash

# 사용자가 입력한 숫자($1)만큼 반복해서 출력만 해보기
for i in $(seq 1 $1)
do
    echo "This is loop number $i"
done
