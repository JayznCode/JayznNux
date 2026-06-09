#!/bin/bash

# [설정] 로그 파일 위치
LOG_FILE="git_sync.log"

# 색상 정의
GREEN='\033[0;32m'; RED='\033[0;31m'; CYAN='\033[0;36m'; YELLOW='\033[1;33m'; NC='\033[0m'

# [기능 1] 유연성: 입력값이 없으면 기본값(master) 사용
BRANCH=${1:-master}

# 로딩 애니메이션 함수 (기존과 동일)
show_progress() {
    total=20; done=0
    for ((i=0; i<=$total; i++)); do
        printf "\r  [${CYAN}%${i}s${NC}]" "" 
        sleep 0.03
    done
    echo ""
}

# 에러 로그 함수 (핵심 20% 추가)
log_error() {
    echo -e "${RED}[ERROR] $(date): $1${NC}" | tee -a "$LOG_FILE"
}

clear
echo -e "${CYAN}=== SYSTEM SYNC: BRANCH [$BRANCH] ===${NC}"

# 1. 저장소 확인
if [ ! -d ".git" ]; then
    log_error "Not a git repository."
    exit 1
fi

# 2. Add
echo -ne "${YELLOW}>> Staging...${NC}"
git add . > /dev/null 2>&1
if [ $? -ne 0 ]; then log_error "git add failed"; exit 1; fi
echo -e "${GREEN} OK${NC}"

# 3. Commit
echo -ne "${YELLOW}>> Committing...${NC}"
git commit -m "Auto-backup: $(date +'%Y-%m-%d %H:%M:%S')" > /dev/null 2>&1
# 커밋할 게 없어서 실패하는 경우는 에러로 간주하지 않기 위해 별도 처리
if [ $? -ne 0 ]; then
    echo -e "${CYAN} (No changes to commit)${NC}"
else
    echo -e "${GREEN} OK${NC}"
fi

# 4. Push (유연성 적용)
echo -ne "${YELLOW}>> Pushing to origin $BRANCH...${NC}"
my_loading_bar
git push origin "$BRANCH" > /dev/null 2>&1
if [ $? -ne 0 ]; then
    log_error "git push to $BRANCH failed. Check network or permissions."
    exit 1
fi

echo -e "${GREEN}${BOLD}=== SYNC COMPLETE: BRANCH [$BRANCH] ===${NC}\n"
