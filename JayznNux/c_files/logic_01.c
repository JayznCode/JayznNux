#include <stdio.h>

int main() {
    int target[3] = {7, 2, 9}; // 정답 (아파트 3채)
    int input[3];              // 사용자 입력용 (아파트 3채)
    int strike = 0;

    printf("숫자 3개를 입력하세요 (예: 1 2 3): ");
    scanf("%d %d %d", &input[0], &input[1], &input[2]); // 주소 3개 찍어주기!

    // [정밀 분석 시작]
    for (int i = 0; i < 3; i++) {
        // 내 i번째 숫자가 정답의 i번째 숫자와 '위치까지' 정확히 같은가?
        if (input[i] == target[i]) {
            strike++;
        }
    }

    printf("결과: %d 스트라이크!\n", strike);

    if (strike == 3) {
        printf("홈런입니다! 축하합니다.\n");
    }

    return 0;
}
