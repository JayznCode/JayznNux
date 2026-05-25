#include <stdio.h>

int main() {

    int choice;
    int running = 1;

    // 프로그램의 메인 루프 (반복 패턴)
    while (running) {
        printf("\n--- 메뉴 선택 ---\n");
        printf("1. 정보 확인\n2. 종료\n선택: ");
        
        // 입력 패턴: 반환값을 확인하여 올바른 입력인지 검사
        if (scanf("%d", &choice) != 1) {
            printf("숫자만 입력해주세요.\n");
            while(getchar() != '\n'); // 버퍼 비우기 패턴
            continue;
        }

        // 조건 분기 패턴
        switch (choice) {
            case 1:
                printf("C언어 공부 중입니다.\n");
                break;
            case 2:
                printf("종료합니다.\n");
                running = 0;
                break;
            default:
                printf("잘못된 입력입니다.\n");
        }
    }
    return 0;
}
