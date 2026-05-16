#include <stdio.h>
#include <string.h>

// 1. [구조체] 학생 정보를 하나로 묶는 틀
struct Student {
    char name[20];
    int kor, eng, math;
    int total;
    float avg;
    char grade;
};

int main() {
    // [배열] 구조체 변수 3개를 배열로 선언
    struct Student s[3];
    struct Student temp; // 정렬 시 임시 저장용

    printf("=== 학생 성적 입력 시스템 ===\n");

    // 2. [반복문 & 입력] 사용자로부터 데이터 받기
    for(int i = 0; i < 3; i++) {
        printf("\n[%d번째 학생]\n", i + 1);
        printf("이름: ");
        scanf("%s", s[i].name);
        printf("국어, 영어, 수학 점수(공백 구분): ");
        scanf("%d %d %d", &s[i].kor, &s[i].eng, &s[i].math);

        // 3. [제어문/연산] 합계와 평균 계산
        s[i].total = s[i].kor + s[i].eng + s[i].math;
        s[i].avg = s[i].total / 3.0;

        // 4. [조건문] 성적 등급 매기기
        if (s[i].avg >= 90) s[i].grade = 'A';
        else if (s[i].avg >= 80) s[i].grade = 'B';
        else if (s[i].avg >= 70) s[i].grade = 'C';
        else s[i].grade = 'F';
    }

    // 5. [중첩 반복문] 성적순 정렬 (버블 정렬)
    for(int i = 0; i < 2; i++) {
        for(int j = i + 1; j < 3; j++) {
            if(s[i].total < s[j].total) { // 총점이 높은 순서대로
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    // 6. [출력] 최종 결과표
    printf("\n\n%10s %10s %8s %8s %8s\n", "RANK", "NAME", "TOTAL", "AVG", "GRADE");
    printf("----------------------------------------------------------\n");
    for(int i = 0; i < 3; i++) {
        printf("%8d등 | %8s | %6d | %8.2f | %4c\n", 
               i + 1, s[i].name, s[i].total, s[i].avg, s[i].grade);
    }

    return 0;
}
