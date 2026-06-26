#include <stdio.h>
#include <fcntl.h>   // open 함수용
#include <unistd.h>  // read, write, close 함수용

int main(int argc, char *argv[]) {
    int fd;
    char buffer[1024];
    ssize_t bytes_read;

    // 1. 파일 열기 (인자로 전달받은 파일명)
    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 2. 파일 내용을 읽어서 화면에 출력 (루프 반복)
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    // 3. 파일 닫기
    close(fd);
    return 0;
}










