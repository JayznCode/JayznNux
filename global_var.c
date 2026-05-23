#include <stdio.h>
#include <stdlib.h>

// Data 영역에 저장되는 전역 변수
int global_var = 10; 

int main(void) {
    // Code/Text 영역에 저장되는 문자열 상수
    char *code_area = "Linux"; 

    // Stack 영역에 저장되는 지역 변수
    int stack_var = 20; 
    char *stack_array[2] = {"Docker", "Git"};

    // Heap 영역에 저장되는 동적 할당 변수
    int *heap_var = (int *)malloc(sizeof(int));

    printf("=== [브래디님의 메모리 주소 지도] ===\n\n");
    
    // 1. Code 영역 (가장 낮은 주소대)
    printf("[Code 영역 문자열] 주소: %p\n", (void *)code_area);
    
    // 2. Data 영역
    printf("[Data 영역 전역변수] 주소: %p\n", (void *)&global_var);
    
    // 3. Heap 영역 (아래에서 위로 자람)
    printf("[Heap 영역 동적할당] 주소: %p\n", (void *)heap_var);
    
    // 4. Stack 영역 (가장 높은 주소대, 위에서 아래로 자람)
    printf("[Stack 영역 포인터배열] 주소: %p\n", (void *)stack_array);
    printf("[Stack 영역 지역변수] 주소: %p\n", (void *)&stack_var);

    // 할당 해제
    free(heap_var);

    return 0;
}
