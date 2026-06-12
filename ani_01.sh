#!/bin/bash

# [1] 스피너 애니메이션 (작업 중임을 표시)
spinner() {
    local pid=$1
    local delay=0.1
    local spinstr='|/-\'
    while [ "$(ps a | awk '{print $1}' | grep $pid)" ]; do
        local temp=${spinstr#?}
        printf " [%c]  " "$spinstr"
        local spinstr=$temp${spinstr%"$temp"}
        sleep $delay
        printf "\b\b\b\b\b\b"
    done
    printf "    \b\b\b\b"
}

# [2] 진행률 바 애니메이션 (길이와 속도 조절 가능)
progress_bar() {
    local duration=$1
    local columns=$(tput cols)
    local bar_width=$((columns / 2))
    
    for ((i=0; i<=bar_width; i++)); do
        printf "\r["
        printf "%${i}s" | tr ' ' '='
        printf ">"
        printf "%$((bar_width-i))s" | tr ' ' ' '
        printf "] %d%%" $((i * 100 / bar_width))
        sleep $duration
    done
    echo -e "\n작업 완료!"
}

# [3] 타이핑 애니메이션 (사용자에게 메시지 전달)
typing_message() {
    local text="$1"
    for ((i=0; i<${#text}; i++)); do
        printf "%s" "${text:$i:1}"
        sleep 0.03
    done
    echo ""
}

# --- 실행 로직 ---
clear
typing_message "시스템을 진단 중입니다..."
# 스피너 실행 (배경 작업으로)
(sleep 3) & 
spinner $!

echo "데이터 동기화를 시작합니다."
progress_bar 0.05
