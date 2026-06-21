#include <stdio.h>
#include <stdlib.h>

// 하드웨어의 특정 메모리 주소를 관리하는 시스템이라고 가정합니다.
void manage_memory_module(int *data_pointer) {
    // 1. 메모리 접근 전 안전성 확인 (오류 방지)
    if (data_pointer == NULL) {
        printf("[Error] 잘못된 모듈 접근입니다. 하드웨어 신호가 끊겼습니다.\n");
        return;
    }

    // 2. 데이터 값 변경 (하드웨어 레지스터 제어)
    printf("[System] 모듈의 데이터를 변경합니다. 현재 값: %d\n", *data_pointer);
    *data_pointer = 100; // 하드웨어에게 새로운 명령값을 전달
    printf("[System] 변경 완료. 새로운 값: %d\n", *data_pointer);
}

int main() {
    int hardware_register = 10; // 하드웨어 장치의 상태값
    
    printf("--- 하드웨어 모듈 제어 시스템 ---\n");
    
    // 정상적인 제어
    manage_memory_module(&hardware_register);
    
    // 잘못된 제어 시도 (오류 발생 시나리오)
    printf("\n--- 비정상적인 모듈 접근 시도 ---\n");
    manage_memory_module(NULL); 
    
    return 0;
}
