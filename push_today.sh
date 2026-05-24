#!/bin/bash

# 색상 정의 (해커 스타일)
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
BOLD='\033[1m'
NC='\033[0m' # No Color

echo -e "${BLUE}${BOLD}>>> INITIALIZING SYSTEM SYNC...${NC}"

# 1. 깃 저장소 확인 (조건 체크)
if [ ! -d ".git" ]; then
    echo -e "${RED}[ERROR] Not a git repository! Aborting.${NC}"
    exit 1
fi

# 2. 스테이징 과정 시각화
echo -ne "  [1/3] Staging files... "
git add . > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo -e "${GREEN}DONE${NC}"
else
    echo -e "${RED}FAILED${NC}"
    exit 1
fi

# 3. 커밋 과정 시각화
TODAY=$(date "+%Y-%m-%d %H:%M:%S")
echo -ne "  [2/3] Committing changes... "
git commit -m "System Backup: $TODAY" > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo -e "${GREEN}DONE${NC}"
else
    # 이미 변경된 내용이 없을 수도 있으니 확인
    echo -e "${BLUE}SKIPPED (No changes?)${NC}"
fi

# 4. 푸시 과정 시각화
echo -ne "  [3/3] Pushing to origin... "
git push origin master > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo -e "${GREEN}${BOLD}SUCCESS!${NC}"
else
    echo -e "${RED}FAILED${NC}"
    exit 1
fi

echo -e "\n${GREEN}${BOLD}=== SYSTEM SYNC COMPLETE: GREEN GRASS PLANTED ===${NC}\n"
