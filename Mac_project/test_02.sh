#!/bin/bash

for i in $(seq 1 $1)
do

    #echo 대신 touch를 써서 실제 파일을 만듭니다.
    touch "my_file_$i.txt"
    echo "Created: my_file_$i.txt"

done

