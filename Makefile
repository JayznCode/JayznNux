# 1. 현재 폴더의 모든 .c 파일을 찾아서 리스트업 (main.c, Priority.c 등)
SRCS = $(wildcard *.c)

# 2. 각 소스 파일 이름을 따서 .exe 파일 이름 생성 (main.exe, Priority.exe 등)
TARGETS = $(SRCS:.c=.exe)

# 3. 기본 실행 (모든 타겟을 만들고 소스 정리)
all: $(TARGETS) move_src

# 4. 각 .c 파일을 각각의 .exe로 컴파일하는 규칙
%.exe: %.c
	gcc $< -o $@
	@echo "🎯 빌드 완료: $@"

# 5. [핵심] 컴파일 후 각 소스 파일을 c-file 폴더로 이동
move_src:
	@mkdir -p c-file
	@if [ -n "$(SRCS)" ]; then \
		mv $(SRCS) c-file/; \
		echo "📂 모든 소스 파일(.c)을 'c-file' 폴더로 정리했습니다."; \
	fi

# 6. 초기화: 소스 파일을 다시 꺼내고 .exe 삭제
clean:
	@if [ -d c-file ]; then mv c-file/*.c . && rm -rf c-file; fi
	rm -f *.exe
	@echo "♻️ 소스 파일을 복구하고 실행 파일을 삭제했습니다."
