#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global_var = 10; // 데이터 영역 (Data Segment)

int main() {
    int local_var = 20; // 스택 영역 (Stack)
    int *heap_var = (int *)malloc(sizeof(int)); // 힙 영역 (Heap)
    *heap_var = 30;

    printf("PID: %d\n", getpid());
    printf("Code(main)   addr: %p\n", (void *)main);
    printf("Data(global) addr: %p\n", (void *)&global_var);
    printf("Heap         addr: %p\n", (void *)heap_var);
    printf("Stack(local) addr: %p\n", (void *)&local_var);

    printf("\n메모리 맵을 확인하려면 다른 터미널에서 'cat /proc/%d/maps'를 입력하세요.\n", getpid());
    
    // 프로그램이 종료되지 않게 대기
    while(1) {
        sleep(1);
    }

    free(heap_var);
    return 0;
}
