#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== SYSTEM SYNC: C-VERSION ===\n");

    // 파이썬 기반 진행 바 호출 (tqdm 사용)
    printf(">> Pushing to origin master...\n");
    system("python3 -c 'from tqdm import tqdm; import time; [time.sleep(0.05) for i in tqdm(range(20))]'");

    // Git 명령어 실행
    int result = system("git push origin master > /dev/null 2>&1");

    if (result == 0) {
        printf("✅ SYNC COMPLETE\n");
    } else {
        printf("❌ SYNC FAILED\n");
    }

    return 0;
}
