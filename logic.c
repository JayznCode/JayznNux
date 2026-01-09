#include <stdio.h>

int main() {
    int target = 7;
    int guess;
    int attempts = 0; // English: Variable to store try counts

    printf("--- Linux Logic Test: Guess the Number ---\n");

    while (1) {
        printf("Enter your guess (1-10): ");
        scanf("%d", &guess);
        attempts++;

        if (guess == target) {
            printf("Correct! You found it in %d attempts.\n", attempts);
            break; 
        } else if (guess > target) {
            printf("Too high! Try again.\n");
        } else {
            printf("Too low! Try again.\n");
        }
    } // End of while loop

    return 0;
}
