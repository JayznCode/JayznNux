#include <stdio.h>
#include <stdlib.h> // malloc, free를 사용하기 위해 필요

int main() {
    int size;
    int *arr;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // 1. 메모리 동적 할당 (int 크기 * 원하는 개수)
    arr = (int *)malloc(sizeof(int) * size);

    // 2. 안전장치: 메모리 할당 실패 여부 확인 (Null Check)
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; 
    }

    // 3. 동적 배열 사용하기
    for (int i = 0; i < size; i++) {
        arr[i] = (i + 1) * 10;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // 4. 중요: 사용이 끝난 메모리는 반드시 해제
    free(arr);
    arr = NULL; // 해제 후 포인터를 NULL로 초기화하는 좋은 습관

    return 0;
}
