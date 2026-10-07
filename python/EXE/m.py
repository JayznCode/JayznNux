import sys
import os
import io
from datetime import datetime

# 터미널 입출력 인코딩 UTF-8 강제 지정
sys.stdin = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8', errors='replace')
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')

NOTE_FILE = os.path.join(os.path.dirname(os.path.abspath(__file__)), "quick_notes.txt")

def view_notes():
    """저장된 메모 전체 조회"""
    if not os.path.exists(NOTE_FILE) or os.path.getsize(NOTE_FILE) == 0:
        print("📂 저장된 메모가 없습니다.")
        return

    print("\n=== 📝 저장된 메모 목록 ===")
    with open(NOTE_FILE, "r", encoding="utf-8") as f:
        print(f.read().strip())
    print("=========================\n")

def save_note(content):
    """메모 추가 저장"""
    if not content.strip():
        print("내용이 없어 저장하지 않았습니다.")
        return

    timestamp = datetime.now().strftime("[%Y-%m-%d %H:%M:%S]")
    entry = f"{timestamp} {content}\n"

    with open(NOTE_FILE, "a", encoding="utf-8") as f:
        f.write(entry)

    print(f"✅ 저장 완료: {content}")

if __name__ == "__main__":
    # 1. 'list' 또는 'l' 인자를 준 경우: 메모 목록 출력
    if len(sys.argv) > 1 and sys.argv[1].lower() in ["list", "l"]:
        view_notes()
    # 2. 한 줄 인자로 메모를 넘긴 경우: 바로 저장 (예: python3 m.py "내용")
    elif len(sys.argv) > 1:
        content = " ".join(sys.argv[1:])
        save_note(content)
    # 3. 인자 없이 실행한 경우: 입력받기
    else:
        try:
            content = input("📝 메모 입력: ").strip()
            save_note(content)
        except (KeyboardInterrupt, EOFError):
            print("\n취소되었습니다.")
