import json
import os

FILENAME = "python_mastery_roadmap.json"

# [방대한 로드맵 데이터베이스]
# 이 구조 하나에 파이썬 전체 영역의 실전 과제가 담깁니다.
DEFAULT_CURRICULUM = {
    "1. 기초 문법 & 데이터 타입": {
        "1-1. print() 출력과 f-string 문자열 포맷팅": True,
        "1-2. list, dict, set, tuple 특징과 슬라이싱 활용": False,
        "1-3. if 조건문과 Guard Clause(비상 탈출) 패턴": True,
        "1-4. for/while 반복문과 enumerate, zip 활용": False,
    },
    "2. 파일 입출력 & 예외 처리": {
        "2-1. open()과 with 문을 활용한 안전한 파일 읽기/쓰기": True,
        "2-2. try-except-finally 예외 처리와 sys.stderr 출력": True,
        "2-3. json 모듈을 활용한 데이터 직렬화 및 파일 보관": False,
    },
    "3. 리눅스 & 시스템 제어 (System & Process)": {
        "3-1. os, sys 모듈을 활용한 환경 변수 및 CLI 인자(sys.argv) 제어": True,
        "3-2. subprocess.run()과 DEVNULL로 외부 쉘 명령어 실행 및 exit code 받기": True,
        "3-3. ANSI Escape Code로 터미널 색상 및 로그 레벨 구현": True,
        "3-4. tqdm 모듈로 터미널 진행률 바(Progress Bar) 연동": True,
    },
    "4. 함수, 모듈 & 객체 지향 (OOP)": {
        "4-1. def 함수 정의, Type Hinting 및 리턴값 명시": True,
        "4-2. 모듈 분리(import)와 __name__ == '__main__' 가드": False,
        "4-3. Class 정의, __init__, self의 이해와 메모리 구조": False,
    },
    "5. 고급 파이썬 & 비동기/네트워크": {
        "5-1. List Comprehension 및 Generator 활용": False,
        "5-2. Decorator(@) 작성을 통한 실행 시간 측정": False,
        "5-3. socket 모듈을 이용한 기본 TCP 클라이언트/서버 작성": False,
    }
}

def load_data():
    """저장된 진행 상황 파일이 있으면 읽어오고, 없으면 기본 데이터 반환"""
    if os.path.exists(FILENAME):
        with open(FILENAME, "r", encoding="utf-8") as f:
            return json.load(f)
    return DEFAULT_CURRICULUM

def save_data(data):
    """현재 진행 상황을 JSON 파일로 저장"""
    with open(FILENAME, "w", encoding="utf-8") as f:
        json.dump(data, f, ensure_ascii=False, indent=2)

def main():
    roadmap = load_data()
    
    print("==================================================")
    print("    🐍 파이썬 완주(Mastery) 방대한 체크리스트")
    print("==================================================\n")
    
    total_items = 0
    completed_items = 0

    for category, tasks in roadmap.items():
        print(f"■ {category}")
        for task, is_done in tasks.items():
            total_items += 1
            if is_done:
                completed_items += 1
                status = "[\033[0;32mDONE\033[0m]"  # 초록색
            else:
                status = "[\033[0;31m    \033[0m]"  # 빨간 공간
            print(f"   {status} {task}")
        print()

    progress = (completed_items / total_items) * 100 if total_items > 0 else 0
    print("--------------------------------------------------")
    print(f"전체 진도율: {completed_items}/{total_items} ({progress:.1f}%)")
    print("--------------------------------------------------")

    save_data(roadmap)

if __name__ == "__main__":
    main()
