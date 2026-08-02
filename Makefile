# 컴파일러 설정
CC = gcc

# 디렉토리 설정
SRC_DIR = c-file
BIN_DIR = bin

# 현재 폴더의 .c 파일들
SRCS = $(wildcard *.c)
TARGETS = $(SRCS:.c=.exe)

# 1. 기본 빌드 (컴파일 + 정리)
all: $(TARGETS) organize

# 2. 컴파일 규칙
%.exe: %.c
	@$(CC) $< -o $@
	@echo "🎯 빌드 완료: $@"

# 3. 정리 규칙 (소스는 c-file로, 실행 파일은 bin으로)
organize:
	@echo "📂 파일 정리 중..."
	@mkdir -p $(SRC_DIR) $(BIN_DIR)
	@if [ -n "$(SRCS)" ]; then mv $(SRCS) $(SRC_DIR)/; fi
	@mv *.exe $(BIN_DIR)/ 2>/dev/null || true

# 4. 초기화 규칙 (되돌리기)
clean:
	@echo "♻️ 프로젝트 초기화 중..."
	@if [ -d $(SRC_DIR) ]; then mv $(SRC_DIR)/*.c . && rm -rf $(SRC_DIR); fi
	@rm -rf $(BIN_DIR)
