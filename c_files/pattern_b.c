#include <stdio.h>

void process_array(int *arr, int size) {
    // 포인터를 이용한 배열 순회 패턴
    for (int i = 0; i < size; i++) {
        // *(arr + i)는 arr[i]와 동일한 접근 방식
        printf("데이터 %d번: %d\n", i + 1, *(arr + i));
    }
}

int main() {
    int data[] = {10, 20, 30, 40, 50};
    int size = sizeof(data) / sizeof(data[0]);

    printf("배열 처리 시작:\n");
    process_array(data, size);

    return 0;
}
