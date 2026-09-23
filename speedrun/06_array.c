#include <stdio.h>

int main(void) {
    // 1. Declare and initialize an array of integers
    int scores[5] = {90, 80, 75, 95, 85};
    int sum = 0;

    printf("--- Array Iteration with For Loop ---\n");
    
    // 2. Iterate through the array using a for loop
    for (int i = 0; i < 5; i++) {
        printf("Score at index %d: %d\n", i, scores[i]);
        sum += scores[i];
    }

    // 3. Calculate and print the average
    float average = (float)sum / 5;
    printf("\nTotal Sum: %d\n", sum);
    printf("Average Score: %.2f\n", average);

    return 0;
}
