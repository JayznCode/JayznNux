def check_log(file_path):
    # 파일을 읽기 모드로 엽니다.
    with open(file_path, 'r') as file:
        # 파일의 각 줄을 순회합니다.
        for line in file:
            # 줄에 'ERROR'라는 단어가 포함되어 있는지 확인합니다.
            if "ERROR" in line:
                # 찾으면 출력합니다. (strip()은 줄바꿈 문자를 제거합니다.)
                print(f"Found error: {line.strip()}")

if __name__ == "__main__":
    check_log('system.log')
