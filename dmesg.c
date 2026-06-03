#include <stdio.h>
#include <stdlib.h>
#include <sys/klog.h> // klogctl 시스템 콜을 위한 헤더
#include <errno.h>

#define LOG_BUF_LEN 16384 // 읽어올 로그 버퍼의 크기

int main() {
    char *log_buf = malloc(LOG_BUF_LEN);
    if (!log_buf) {
        perror("malloc");
        return 1;
    }

    // klogctl(1, buf, len) -> 커널 로그 버퍼 전체를 읽어옴
    int n = klogctl(1, log_buf, LOG_BUF_LEN - 1);
    
    if (n < 0) {
        perror("klogctl (권한 부족일 수 있습니다)");
        free(log_buf);
        return 1;
    }

    log_buf[n] = '\0'; // 문자열 끝 처리
    printf("--- Kernel Log Output ---\n%s\n", log_buf);

    free(log_buf);
    return 0;
}
