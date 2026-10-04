import os
import sys
import subprocess
import time
from tqdm import tqdm

# 터미널 색상 정의 (ANSI Escape Code)
COLOR_GREEN = "\033[0;32m"
COLOR_YELLOW = "\033[0;33m"
COLOR_CYAN = "\033[0;36m"
COLOR_RED = "\033[0;31m"
COLOR_RESET = "\033[0m"


def log_error(message: str) -> None:
    """에러 메시지를 표준 에러(stderr)로 출력"""
    print(f"{COLOR_RED}[ERROR] {message}{COLOR_RESET}", file=sys.stderr)


def check_git_repository() -> bool:
    """1. 가드 클로즈: .git 폴더 존재 확인"""
    # 쉘의 [ ! -d ".git" ] 과 동일한 검문소
    if not os.path.exists(".git"):
        log_error("Not a git repository. Missing .git directory.")
        return False
    return True


def run_cmd(command: str) -> int:
    """
    외부 쉘 명령어를 실행하고 종료 상태 코드(Exit Code)를 반환하는 함수
    > /dev/null 2>&1 처리처럼 출력을 숨김 (stdout/stderr 캡처)
    """
    result = subprocess.run(
        command,
        shell=True,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL
    )
    return result.returncode  # 쉘 스크립트의 $?, C 언어의 return값과 동일


def main():
    # [검문소] .git 저장소 확인 (실패 시 빠른 비상 탈출)
    if not check_git_repository():
        sys.exit(1)  # 쉘의 exit 1, C 언어의 return 1 과 동일

    # --- 1. Git Add ---
    print(f"{COLOR_YELLOW}>> Staging...{COLOR_RESET}", end="", flush=True)
    
    add_status = run_cmd("git add .")
    if add_status != 0:
        print()
        log_error("git add failed")
        sys.exit(1)  # Fail Fast: 비상 탈출
        
    print(f"{COLOR_GREEN} OK{COLOR_RESET}")

    # --- 2. Git Commit ---
    print(f"{COLOR_YELLOW}>> Committing...{COLOR_RESET}", end="", flush=True)

    timestamp = time.strftime("%Y-%m-%d %H:%M:%S")
    commit_cmd = f'git commit -m "Auto-backup Python version: {timestamp}"'
    
    commit_status = run_cmd(commit_cmd)
    
    # $? -ne 0 예외 처리: 커밋 실패는 (No changes)로 유연하게 수용
    if commit_status != 0:
        print(f"{COLOR_CYAN} (No changes to commit){COLOR_RESET}")
    else:
        print(f"{COLOR_GREEN} OK{COLOR_RESET}")

    # --- 3. Git Push & UI 연출 ---
    print(f"{COLOR_YELLOW}>> Pushing to origin...{COLOR_RESET}")

    # 파이썬 tqdm을 활용한 로딩 애니메이션 연출 (tqdm + time.sleep)
    for _ in tqdm(range(20), desc="Processing", ascii=" #", unit="step"):
        time.sleep(0.05)

    # 실제 git push 실행
    push_status = run_cmd("git push origin main")
    if push_status != 0:
        print(f"{COLOR_RED}FAILED{COLOR_RESET}")
        log_error("git push failed. Check network or permissions.")
        sys.exit(1)

    print(f"{COLOR_GREEN} OK{COLOR_RESET}\n")
    print(f"{COLOR_GREEN}=== SYNC COMPLETE (Python Version) ==={COLOR_RESET}\n")


if __name__ == "__main__":
    main()
