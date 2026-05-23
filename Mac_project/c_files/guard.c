#include <stdio.h>

int main() {
    int password = 1234; // 정답 비밀번호
    int input;           // 사용자 입력 박스
    int chance = 3;      // 남은 기회

    printf("--- Secure Login System ---\n");

    while (1) {
        printf("Enter Password: ");
        scanf("%d", &input);

        if (input == password) {
            printf("Access Granted! Welcome.\n");
            // [미션 1] 여기서 어떻게 탈출할까요?
	    break; 
        } else {
            chance--; // 기회 1 깎기
            printf("Access Denied! (Remaining: %d)\n", chance);
            
            // [미션 2] 기회가 0이 되었을 때 탈출하는 조건을 아래에 써보세요.
            if (chance <= 0) {
                printf("Too many failed attempts. System Locked!\n");
                break;
            }
        }
    }

    return 0;
}

