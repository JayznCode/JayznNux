#include <stdio.h>
#include <string.h>

// 실무에서는 '학생' 대신 '프로세스(작업)' 정보를 묶습니다.
struct Process {
    int pid;            // 프로세스 ID
    char name[20];      // 프로그램 이름 (예: Docker, Git, Vim)
    int priority;       // 우선순위 (1~10, 높을수록 먼저 실행)
};

int main() {
    // 1. 시스템에 현재 떠 있는 프로세스들 (무작위 상태)
    struct Process tasks[3] = {
        {101, "Vim Editor", 3},
        {102, "Docker Engine", 9},  // 이놈이 제일 급함
        {103, "Git Push", 5}
    };

    // 2. 실무형 정렬 (가장 높은 우선순위를 0번 자리에 배치)
    for(int i = 0; i < 2; i++) {
        for(int j = i + 1; j < 3; j++) {
            // "뒷번호 프로세스(j)가 더 급하면(priority가 크면) 자리를 바꿔라!"
            if(tasks[i].priority < tasks[j].priority) {
                struct Process temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    // 3. 실행 순서 출력
    printf("CPU Scheduling Order:\n");
    for(int i = 0; i < 3; i++) {
        printf("Step %d: [PID: %d] %-15s (Priority: %d)\n", 
                i+1, tasks[i].pid, tasks[i].name, tasks[i].priority);
    }

    return 0;
}
