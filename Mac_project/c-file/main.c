#include <stdio.h>
#include <string.h>

// Structure to hold student info
struct Student {
    char name[10];
    int scores[3];
    int total;
    char result[5]; // PASS or FAIL
};

int main() {
    // 1. Initialize students
    struct Student s[3] = {
        {"Alfa", {80, 70, 65}, 0, ""},
        {"Bravo", {60, 50, 40}, 0, ""},
        {"Charlie", {90, 85, 95}, 0, ""}
    };

    // 2. Calculate Total and Pass/Fail
    for(int i = 0; i < 3; i++) {
        s[i].total = s[i].scores[0] + s[i].scores[1] + s[i].scores[2];
        
        // Pass if total is 70 or higher
        if (s[i].total >= 70) strcpy(s[i].result, "PASS");
        else strcpy(s[i].result, "FAIL");
    }

    // 3. Sorting by Total Score (Bubble Sort)
    for(int i = 0; i < 2; i++) {
        for(int j = i + 1; j < 3; j++) {
            if(s[i].total < s[j].total) {
                struct Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    // 4. Output Results
    printf("RANK |   NAME   | TOTAL | RESULT\n");
    printf("--------------------------------\n");
    for(int i = 0; i < 3; i++) {
        printf("%dnd  | %-8s |  %3d  | %s\n", i+1, s[i].name, s[i].total, s[i].result);
    }

    return 0;
}
