#!/bin/bash

# 1. 필요한 폴더들을 생성 (이미 있으면 통과)
mkdir -p c_files exe_files python_scripts shell_scripts notes others

# 2. 확장자별로 파일 이동
# - .c 파일 -> c_files
mv *.c c_files/ 2>/dev/null

# - .exe 파일 -> exe_files
mv *.exe exe_files/ 2>/dev/null

# - .py 파일 -> python_scripts (추가됨!)
mv *.py python_scripts/ 2>/dev/null

# - .sh 파일 -> shell_scripts (추가됨!)
# 주의: 이 스크립트 파일 자체(organize.sh)는 옮기지 않도록 설정 가능
mv *.sh shell_scripts/ 2>/dev/null

# - .txt 또는 .tct (오타 포함) -> notes
mv *.txt *.tct notes/ 2>/dev/null

echo "Success! Your files (.c, .exe, .py, .sh) are now organized."
