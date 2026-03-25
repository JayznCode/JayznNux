#include <stdio.h> // 1. printf 사용을 위해 필수!

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    printf("--- Array Memory Layout ---\n");
    
    // 2. i < 5 라고 명확히 써줘야 합니다.
    for (int i = 0; i < 5; i++) {
        // 3. %d(정수), %p(주소) 서식 지정자를 정확히 입력합니다.
        printf("arr[%d] : value = %d | address = %p\n", i, arr[i], (void*)&arr[i]);
    }

    return 0;
}
