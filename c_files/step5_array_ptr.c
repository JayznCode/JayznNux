#include <stdio.h>

int main() {
    int arr[3] = {10, 20, 30};
    int *ptr = arr;

    printf("=== Danger Zone Test ===\n");

    // 방은 3개인데, 5번(0부터 4까지) 돌려버립니다!
    for (int i = 0; i < 5; i++) {
        // 3번째, 4번째 방은 우리가 예약한 주차 칸이 아닙니다.
        printf("Index [%d] | Address: %p | Value: %d\n", i, (void*)(ptr + i), *(ptr + i));
    }

    return 0;
}
