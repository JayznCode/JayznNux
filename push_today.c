#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // sleep, usleep 함수 사용 (Windows 환경은 <windows.h>의 Sleep)

// 터미널 색상 정의 (ANSI Escape Code)
#define COLOR_GREEN  "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_CYAN   "\033[0;36m"
#define COLOR_RED    "\033[0;31m"
#define COLOR_RESET  "\033[0m"

// 에러 출력용 로그 함수
void log_error(const char *message) {
    fprintf(stderr, "%s[ERROR] %s%s\n", COLOR_RED, message, COLOR_RESET);
}

// 1. 가드 클로즈: .git 폴더 존재 확인
int check_git_repository(void) {
    // 쉘의 [ ! -d ".git" ] 과 동일한 검문소
    if (access(".git", F_OK) != 0) {
        log_error("Not a git repository. Missing .git directory.");
        return 0; // 실패 (false)
    }
    return 1; // 성공 (true)
}

// 2. 파이썬 tqdm을 대신하는 C 언어 자체 프로그레스 바 연출
void show_progress_animation(const char *label) {
    printf("%s>> %s...%s ", COLOR_YELLOW, label, COLOR_RESET);
    fflush(stdout); // 버퍼 비우기 (즉시 출력)

    int total_steps = 20;
    for (int i = 0; i < total_steps; i++) {
        // 0.05초(50,000 마이크로초) 동안 프로세스 일시정지 (time.sleep 역할)
        usleep(50000); 
    }
}

int main(void) {
    // [검문소] .git 저장소 확인 (실패 시 빠른 비상 탈출)
    if (!check_git_repository()) {
        return 1; // 쉘 스크립트의 exit 1과 완벽 대응
    }

    // --- 1. Git Add ---
    printf("%s>> Staging...%s", COLOR_YELLOW, COLOR_RESET);
    fflush(stdout);
    
    // system() 함수로 쉘 명령 실행 및 종료 코드($?) 수신
    int add_status = system("git add . > /dev/null 2>&1");
    if (add_status != 0) {
        printf("\n");
        log_error("git add failed");
        return 1; // Fail Fast: 비상 탈출
    }
    printf("%s OK%s\n", COLOR_GREEN, COLOR_RESET);

    // --- 2. Git Commit ---
    printf("%s>> Committing...%s", COLOR_YELLOW, COLOR_RESET);
    fflush(stdout);

    // 날짜를 포함한 커밋 명령 생성
    char commit_cmd[256];
    snprintf(commit_cmd, sizeof(commit_cmd), 
             "git commit -m \"Auto-backup C version\" > /dev/null 2>&1");

    int commit_status = system(commit_cmd);
    
    // $? -ne 0 예외 처리: 커밋 실패는 치명적 에러가 아닌 (No changes)로 유연하게 수용
    if (commit_status != 0) {
        printf("%s (No changes to commit)%s\n", COLOR_CYAN, COLOR_RESET);
    } else {
        printf("%s OK%s\n", COLOR_GREEN, COLOR_RESET);
    }

    // --- 3. Git Push & UI 연출 ---
    // 애니메이션 띄우기 (Sleep으로 시각적 효과 부여)
    show_progress_animation("Pushing to origin");

    int push_status = system("git push origin main > /dev/null 2>&1");
    if (push_status != 0) {
        printf("%s FAILED%s\n", COLOR_RED, COLOR_RESET);
        log_error("git push failed. Check network or permissions.");
        return 1;
    }
    
    printf("%s OK%s\n\n", COLOR_GREEN, COLOR_RESET);
    printf("%s=== SYNC COMPLETE (C Version) ===%s\n", COLOR_GREEN, COLOR_RESET);

    return 0; // 정상 종료 (쉘의 $? 변수에 0 전달)
}
