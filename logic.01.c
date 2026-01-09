#include <stdio.h>

int main() {
    int target[3] = {7, 2, 9}; // 정답
    int input[3];              // 사용자 입력
    int strike = 0, ball = 0;

    printf("숫자 3개를 입력하세요: ");
    scanf("%d %d %d", &input[0], &input[1], &input[2]);

    // [이중 루프: 마트료시카 엔진]
    for (int i = 0; i < 3; i++) {         // 바깥 루프: 내 숫자 하나씩 꺼내기
        for (int j = 0; j < 3; j++) {     // 안쪽 루프: 정답 숫자 3개와 다 대조하기
            
            if (input[i] == target[j]) {  // 숫자가 일단 존재한다면?
                if (i == j) {             // 위치(방 번호)까지 같다면?
                    strike++;
                } else {                  // 위치는 다르다면?
                    ball++;
                }
            }
        }
    }

    printf("결과: %d 스트라이크, %d 볼\n", strike, ball);

    if (strike == 3) printf("축하합니다! 홈런입니다!\n");

    return 0;
}
