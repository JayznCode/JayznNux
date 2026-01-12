#include <stdio.h>

int main() {
    // 이름을 추가 !
    char names[3][10] = {"alfa", "bravo", "charlie"};

    // 1. 2D Array: [Students][Subjects]
    int scores[3][3] = {
        {85, 90, 78}, // Student 0
        {60, 55, 65}, // Student 1
        {95, 88, 92}  // Student 2
    };

    int top_score = 0;
    int top_student = 0;

    printf("--- Grade Report ---\n");

    // 2. Nested Loop: Rows (Students)
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        
        // Inner Loop: Columns (Subjects)
        for (int j = 0; j < 3; j++) {
            sum += scores[i][j];
        }

        double average = sum / 3.0;

        // 3. Conditional: Check Pass/Fail
        if (average >= 70) {
            printf("Student %d: Pass (Avg: %.2f)\n", i, average);
        } else {
            printf("Student %d: Fail (Avg: %.2f)\n", i, average);
        }

        // 4. Conditional: Find the Top Student
        if (sum > top_score) {
            top_score = sum;
            top_student = i;
        }
    }

    printf("--------------------\n");
    printf("Top Student: Number %d with Total Score %d\n", top_student, top_score);

    return 0;
}
