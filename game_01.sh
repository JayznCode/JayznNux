#include <stdio.h>
#include <unistd.h> // sleep() 사용

int main() {
    int x = 0;
    while(x < 20) {
        printf("\r"); // 맨 앞으로 커서 이동
        for(int i = 0; i < x; i++) printf(" "); // 공백 출력
        printf("O"); // 캐릭터 출력
        fflush(stdout); // 화면에 즉시 출력
        
        sleep(1); // 1초 대기
        x++;
    }
    return 0;
}
