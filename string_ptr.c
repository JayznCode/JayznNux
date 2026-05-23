#include <stdio.h>

int main(void) {
    // 1. 아까 썼던 일반 배열 방식 (스택에 방을 만듦)
    char stack_name[6] = "Brady";
    
    // 2. 새로운 포인터 방식 (진짜 Brady가 있는 주소만 가리킴)
    char *ptr_name = "Brady";

    printf("==================================================\n");
    printf(" 1. Stack Room (The local room we know)\n");
    printf("==================================================\n");
    printf("stack_name[0] ('B') address : %p\n", (void*)&stack_name[0]);

    printf("\n==================================================\n");
    printf(" 2. Secret Territory (Where did it go?)\n");
    printf("==================================================\n");
    // Let's print the actual address where ptr_name is pointing to!
    printf("ptr_name points to address   : %p\n", (void*)ptr_name);

    return 0;
}
