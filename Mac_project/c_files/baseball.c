#include <stdio.h>

int main() {
    int target[3] = {7, 2, 9}; 
    int input[3];
    int chance = 10; // 사용자에게 주는 10번의 기회 (박스 하나 추가!)

    printf("=== 숫자 야구 게임 시작! (기회 10번) ===\n");

    while (chance > 0) {
        int strike = 0, ball = 0; // 매 판마다 스트라이크/볼은 초기화 (박스 비우기)

        printf("\n남은 기회: %d\n", chance);
        printf("숫자 3개를 입력 (예: 1 2 3): ");
        scanf("%d %d %d", &input[0], &input[1], &input[2]);

        // [아까 만든 이중 루프 엔진]
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (input[i] == target[j]) {
                    if (i == j) strike++;
                    else ball++;
                }
            }
        }

        // [결과 보고 및 기회 깎기]
        printf("결과: %d Strike, %d Ball\n", strike, ball);

        if (strike == 3) {
            printf("축하합니다! 정답을 맞췄습니다!\n");
            break; // 정답 맞추면 무한루프 탈출!
        }

        chance--; // 기회를 하나 깎음 (원자 단위 행동)

        if (chance == 0) {
            printf("기회를 모두 사용했습니다. 패배! 정답은 %d %d %d였습니다.\n", target[0], target[1], target[2]);
        }
    }

    return 0;
}
