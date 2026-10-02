#include <stdio.h>
#include <stdlib.h>

// 1. 함수 포인터를 매개변수로 받는 고차 함수 (Callbacks & Function Pointers)
// 연산을 수행할 함수들의 주소를 통째로 인자로 받아 처리하는 로직입니다.
void process_data(int *data, size_t size, int (*op)(int)) {
    for (size_t i = 0; i < size; i++) {
        data[i] = op(data[i]);
    }
}

int double_value(int x) { return x * 2; }
int square_value(int x) { return x * x; }

int main(void) {
    int raw_array[3] = {1, 2, 3};

    // 함수 이름을 그냥 쓰거나 '&'를 붙이면 그 함수의 '메모리 주소'가 됩니다.
    // 그 주소를 포인터 변수처럼 넘겨서 실행하는 구조입니다.
    process_data(raw_array, 3, double_value);
    
    // 2. 이중 포인터(Pointer to Pointer)와 동적 할당의 결합
    // 함수 안에서 바깥의 포인터 변수 자체를 조작(주소값 변경)해야 할 때 쓰이는 악명 높은 패턴입니다.
    int **matrix = NULL;
    int rows = 2, cols = 2;

    // 포인터의 배열을 먼저 할당하고 (행)
    matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) return 1;

    for (int i = 0; i < rows; i++) {
        // 각 행마다 실제 데이터 공간을 할당 (열)
        matrix[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j; // 값 채우기
        }
    }

    // 결과 확인
    printf("Matrix[1][1] = %d\n", matrix[1][1]);

    // 3. 끔찍한 해제(Free) 지옥
    // 만든 순서의 역순으로 일일이 찾아가서 수작업으로 지워야 합니다.
    for (int i = 0; i < rows; i++) {
        free(matrix[i]); // 열 해제
    }
    free(matrix); // 행 해제 (이거 하나라도 빼먹으면 메모리 누수 발생)

    return 0;
}
