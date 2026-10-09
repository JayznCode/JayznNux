import sys
from datetime import datetime
from pathlib import Path 

# 저장할 메모 파일 이름
NOTE_FILE = Path.home() / "JayznNux" / "python" / "EXE" / "notes.txt"

def main():
    # CLI 실행 인자 확인
    if len(sys.argv) < 2:
        print("💡 사용법: m \"메모 내용\" 또는 m 메모 내용")
        print("예시: m 오늘 TAFE 과제 제출하기")
        return

    # 입력된 단어들을 하나의 문자열로 합침
    content = " ".join(sys.argv[1:])
    timestamp = datetime.now().strftime("[%Y-%m-%d %H:%M:%S]")
    entry = f"{timestamp} {content}\n"


    # 메모 파일에 추적 저장 (a mode)
    try:
        with open(NOTE_FILE, "a", encoding="utf-8") as f:
            f.write(entry)
        print(f"✅ 저장됨: {content}")
    except Exception as e:
        print(f"❌ 저장 실패: {e}")

if __name__ == "__main__":
    main()

