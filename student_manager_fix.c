#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    float score;
};

int main() {
    int count = 0;
    struct Student *list = NULL;

    printf("Enter number of students: ");
    if (scanf("%d", &count) != 1 || count <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    // [Point 1] calloc: Allocates memory AND initializes to zero (No trash!)
    list = (struct Student *)calloc(count, sizeof(struct Student));

    if (list == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // [Point 2] Ensuring all allocated space is filled
    for (int i = 0; i < count; i++) {
        list[i].id = i + 1;
        // If user skips input, it will stay 0.00 thanks to calloc
        printf("Score for ID %d: ", list[i].id);
        scanf("%f", &list[i].score);
    }

    printf("\n--- Results ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Score: %.2f\n", list[i].id, list[i].score);
    }

    // [Point 3] Clean exit
    free(list);
    list = NULL; // Defensive programming

    return 0;
}
