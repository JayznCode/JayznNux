#!/bin/bash

# 상단 컴파일 부분은 그대로 두시고...

# 변수 설정 (사용자님이 원하는 숫자로 여기서 한 번에 관리)
STUDENT_COUNT=10

if [ $? -eq 0 ]; then
    echo "Running program with $STUDENT_COUNT students..."
    
    # 변수값을 파이프로 던져줍니다.
    echo "$STUDENT_COUNT" | ./my_test > result.txt
    
    echo "------------------------------------------"
    cat result.txt
    echo "------------------------------------------"
    echo "Step 3: Program finished. All data saved to result.txt"
fi
