#include <stdio.h>

int main() {
    // 1. Prepare rooms (Initialization)
    char *names[3] = {"alfa", "bravo", "charlie"};
    int scores[3][3] = {
        {80, 90, 70}, 
        {60, 50, 40}, 
        {100, 100, 100}
    };
    int total_sums[3] = {0, 0, 0};

    // 2. Process: Calculate each student's total
    for (int i = 0; i < 3; i++) {
        int sum = 0; // Clear the bucket for each student
        for (int j = 0; j < 3; j++) {
            sum += scores[i][j];
        }
        total_sums[i] = sum; // Send result to RAM
    }

    // 3. Logic: Find the winner (Champion Belt)
    int top_score = -1;
    int best_index = 0;

    for (int i = 0; i < 3; i++) {
        if (total_sums[i] > top_score) {
            top_score = total_sums[i];
            best_index = i; // Remember the room number
        }
    }

    // 4. Output: Show the final winner
    printf("------------------------------\n");
    printf("The Winner is: %s\n", names[best_index]);
    printf("Total Score: %d\n", top_score);
    printf("------------------------------\n");

    return 0;
}
