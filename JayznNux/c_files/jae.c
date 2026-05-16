#include <stdio.h>

int main() {
    // 이름 배열 추가
    char names[3][10] = {"alfa", "bravo", "charlie"};
    
    int scores[3][3] = {
        {85, 90, 78}, // alfa의 점수
        {60, 55, 65}, // bravo의 점수
        {95, 88, 92}  // charlie의 점수
    };

    int top_score = 0;
    int top_student_index = 0; // 1등의 번호를 저장

    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += scores[i][j];
        }

        double average = sum / 3.0;

        // %d(숫자) 대신 %s(문자열)를 사용하여 이름을 출력합니다.
        if (average >= 70) {
            printf("%s: Pass (Avg: %.2f)\n", names[i], average);
        } else {
            printf("%s: Fail (Avg: %.2f)\n", names[i], average);
        }

        if (sum > top_score) {
            top_score = sum;
            top_student_index = i; // 1등인 학생의 '번호'를 기억해둡니다.
        }
    }

    // 마지막에 1등 이름을 출력할 때도 names 배열을 사용합니다.
    printf("--------------------\n");
    printf("Top Student: %s (Total: %d)\n", names[top_student_index], top_score);

    return 0;
}
