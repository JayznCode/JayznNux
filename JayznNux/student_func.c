#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    float score;
};

// 1. Function to input data (Receives the memory address)
void input_data(struct Student *s, int n) {
    for (int i = 0; i < n; i++) {
        s[i].id = i + 1;
        printf("Enter score for ID %d: ", s[i].id);
        scanf("%f", &s[i].score); // Directly modifying the memory at the address
    }
}

// 2. Function to print data (Receives the memory address)
void print_data(struct Student *s, int n) {
    printf("\n--- Report Card ---\n");
    for (int i = 0; i < n; i++) {
        // Using arrow '->' if we were handling a single pointer, 
        // but since it's an array, s[i].score is also fine!
        printf("ID: %d | Score: %.2f\n", s[i].id, s[i].score);
    }
}

int main() {
    int count;
    struct Student *list;

    printf("How many students? ");
    scanf("%d", &count);

    // Allocating memory
    list = (struct Student *)calloc(count, sizeof(struct Student));

    // BOSS: "Hey, you guys take this 'list' address and do your job!"
    input_data(list, count);
    print_data(list, count);

    free(list);
    return 0;
}
