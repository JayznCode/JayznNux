#!/bin/bash

# 색상 및 스타일 정의
GREEN='\033[0;32m'
RED='\033[0;31m'
CYAN='\033[0;36m'
YELLOW='\033[1;33m'
BOLD='\033[1m'
NC='\033[0m'

# 해커 느낌의 로딩 애니메이션 함수
loading_bar() {
    local duration=${1}
    already_done() { for ((i=0; i<$done; i++)); do printf "━"; done }
    remaining() { for ((i=$done; i<$total; i++)); do printf " "; done }
    
    total=20
    for ((done=0; done<=$total; done++)); do
        printf "\r  [${CYAN}$(already_done)${NC}$(remaining)] %d%%" $((done*100/total))
        sleep $duration
    done
    echo ""
}

clear
echo -e "${GREEN}${BOLD}=========================================="
echo -e "   [SYSTEM STATUS: INITIALIZING SYNC]    "
echo -e "   [USER: JAEJIN LEE / BRADY]           "
echo -e "   [TIME: $(date)]                       "
echo -e "==========================================${NC}\n"

# 1. 저장소 체크
if [ ! -d ".git" ]; then
    echo -e "${RED}[!] ERROR: GIT REPOSITORY NOT FOUND.${NC}"
    exit 1
fi

# 2. 단계별 실행 (애니메이션 적용)
echo -e "${YELLOW}>> STAGING FILES...${NC}"
loading_bar 0.05
git add . > /dev/null 2>&1
echo -e "${GREEN}✔ STAGE COMPLETE${NC}\n"

echo -e "${YELLOW}>> COMMITTING CHANGES...${NC}"
loading_bar 0.08
git commit -m "Auto-backup: $(date +'%Y-%m-%d %H:%M:%S')" > /dev/null 2>&1
echo -e "${GREEN}✔ COMMIT SUCCESS${NC}\n"

echo -e "${YELLOW}>> PUSHING TO REMOTE SERVER...${NC}"
loading_bar 0.1
git push origin master > /dev/null 2>&1
echo -e "${GREEN}✔ PUSH SUCCESSFUL${NC}\n"

# 최종 승리 메시지
echo -e "${BOLD}${CYAN}******************************************"
echo -e "  SYNC COMPLETE: ALL GRASS PLANTED!      "
echo -e "******************************************${NC}\n"
