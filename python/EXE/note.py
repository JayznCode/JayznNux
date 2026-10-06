import sys
import datetime
import os

# 상대 경로 대신 내 홈 디렉토리 기준 절대 경로로 고정!
HOME_DIR = os.path.expanduser("~")
FILENAME = os.path.join(HOME_DIR, "JayznNux", "python", "EXE",  "study_log.txt")

# 터미널에서 입력한 글자를 하나로 묶기
if len(sys.argv) < 2:
    print("사용법: python3 note.py 오늘 배운 내용 한 줄")
    print("예시 : python3 note.py jason dump랑 load 함수 익힘")
    sys.exit(1)

# 오늘 날짜와 시간 구하기 (예: 2026-10-06 14:30)

now = datetime.datetime.now().strftime("%Y-%m-%d %H:%M")
content = " ".join(sys.argv[1:])


#파일 끝에 날짜와 함꼐 기록(a 모드)
with open(FILENAME, "a", encoding="utf-8") as f:
    f.write(f"[{now}] {content}\n")

print(f"기록 완료! -> {FILENAME}")




