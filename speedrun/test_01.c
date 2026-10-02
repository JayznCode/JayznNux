#include <stdio.h>

int main() {
    int i;
    int sum = 0; // 합계를 담을 변수

    for(i = 1; i <= 100; i++) {
        sum += i; // i를 sum에 누적
    }

    printf("result: %d, i = %d\n", sum, i);

    return 0;
}
