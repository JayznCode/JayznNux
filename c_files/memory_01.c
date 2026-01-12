#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;

    // 모든 printf는 반드시 이 중괄호 { } 안에 있어야 합니다.
    printf("Size of a: %zu bytes\n", sizeof(a));
    printf("Address of a: %p\n", (void*)&a);
    printf("Address of b: %p\n", (void*)&b);

    return 0;
}

