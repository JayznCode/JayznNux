#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // 배열 이름은 포인터처럼 사용 가능!

    printf("배열의 첫 번째 요소: %d\n", arr[0]);
    printf("포인터가 가리키는 값: %d\n", *ptr);
    
    // 포인터 연산을 통해 배열의 다음 요소로 이동
    printf("두 번째 요소(포인터 연산): %d\n", *(ptr + 1));

    return 0;
}
