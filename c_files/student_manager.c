#include <stdio.h>
#include <stdlib.h> // Essential for malloc() and free()

// 1. Defining the Structure: Setting the rule for data
struct Student {
    int id;
    float score;
};

int main() {
    int count;
    struct Student *list; // A pointer to manage our dynamic territory

    printf("Enter the number of students: ");
    scanf("%d", &count);

    // 2. Dynamic Memory Allocation: Claiming territory at runtime
    // We calculate exactly how much space we need: (size of 1 student) * (number of students)
    list = (struct Student *)malloc(sizeof(struct Student) * count);

    // Check if memory was successfully allocated
    if (list == NULL) {
        printf("Error: Could not allocate memory.\n");
        return 1;
    }

    // 3. Data Entry: Using the allocated territory
    for (int i = 0; i < count; i++) {
        list[i].id = i + 1;
        printf("Enter score for Student ID %d: ", list[i].id);
        scanf("%f", &list[i].score);
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        // Accessing structure members using the dot (.) operator
        printf("ID: %d | Score: %.2f\n", list[i].id, list[i].score);
    }

    // 4. Freeing Memory: Giving back the territory to the OS
    // This is the "etiquette" of a master programmer
    free(list);

    return 0;
}
