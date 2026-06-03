#!/bin/bash

# 1. 함수 정의 (먼저 만들어두기)
my_loading_bar() {
    local total=20
    for ((i=0; i<=$total; i++)); do
        printf "\r[====================] %d%%" "$((i * 5))"
        sleep 0.05
    done
    echo ""
}

# 2. 실행 (함수 정의보다 아래에 있어야 함)
echo "작업을 시작합니다..."
my_loading_bar
echo "완료!"
