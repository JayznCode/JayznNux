#include <stdio.h>
#include <unistd.h>     // sleep() 함수를 쓰기 위한 헤더
#include <sys/sysinfo.h> // 리눅스 메모리 정보를 가져오기 위한 헤더

int main(void) {
    struct sysinfo info;
    
    // 대시보드를 10번 실시간으로 갱신하는 무한 루프 시뮬레이션 (Ctrl+C로 종료 가능)
    for (int i = 0; i < 10; i++) {
        // [원리 1] 터미널 화면을 깨끗하게 청소하고 커서를 맨 위로 이동
        printf("\e[1;1H\e[2J");

        // 리눅스 커널로부터 최신 메모리 정보 갱신
       // sysinfo(&info);

        // 바이트 단위를 MB 단위로 변환
        unsigned long total_ram = info.totalram / (1024 * 1024);
        unsigned long free_ram = info.freeram / (1024 * 1024);
        unsigned long used_ram = total_ram - free_ram;

        // 메모리 사용률 퍼센트(%) 계산
        int usage_percent = (int)((double)used_ram / total_ram * 100);

        // 대시보드 UI 그리기
        printf("==================================================\n");
        printf("    🍏 MacNux: Activity Monitor (CLI Version)    \n");
        printf("==================================================\n");
        printf("  [System Status]  Running...\n\n");
        printf("  TOTAL RAM : %4lu MB\n", total_ram);
        printf("  USED  RAM : %4lu MB\n", used_ram);
        printf("  FREE  RAM : %4lu MB\n\n", free_ram);

        // [원리 2] 텍스트로 가독성 좋은 바(Bar) 그래프 그리기
        printf("  Memory Usage: [");
        int bar_count = usage_percent / 10; // 10%당 막대기 1개
        for (int j = 0; j < 10; j++) {
            if (j < bar_count) {
                printf("■"); // 사용 중인 구역
            } else {
                printf(" "); // 빈 구역
            }
        }
        printf("] %d%%\n", usage_percent);
        printf("==================================================\n");
        printf("  (Press Ctrl+C to exit) \n");

        // [원리 3] 1초 동안 대기한 후 다음 바퀴(화면 갱신)로 이동
        sleep(1);
    }

    return 0;
}
