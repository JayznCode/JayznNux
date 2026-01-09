# 1. 컴파일러 설정
CC = gcc
# 2. 컴파일 옵션 (경고를 다 보여달라는 뜻)
CFLAGS = -Wall -g

# 3. 폴더 내의 모든 .c 파일을 찾아서 명단을 만듭니다. (logic_01.c, guard.c 등)
SRCS = $(wildcard *.c)

# 4. .c 파일을 컴파일해서 만들 결과물(실행파일) 명단을 만듭니다. (.c를 떼버림)
PROGS = $(patsubst %.c,%,$(SRCS))

# 'make'만 쳤을 때 실행될 기본 명령
all: $(PROGS)

# 각 .c 파일을 어떻게 실행파일로 만들지 정의하는 규칙
%: %.c
	$(CC) $(CFLAGS)  -o $@ $<

# 'make clean'을 치면 생성된 실행 파일만 싹 지우는 청소 기능
clean:
	rm -f $(PROGS)


