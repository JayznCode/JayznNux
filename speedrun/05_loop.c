#include <stdio.h>

int main(void) {
    // 1. For loop: Classic counting and summation
    int sum = 0;
    printf("---- For Loop  Example ----\n");
    for (int i = 1; i <= 5; i++) {
        sum += i;
        printf("i = %d, current sum = %d\n", i, sum);

    }

    // 2. while loop: Condition-based iteration
    printf("\n--- While Loop Example ---\n");
    int count = 3;
    while (count > 0) {
        printf("Countdown: %d\n", count);
        count--;
    }

    // 3. Loop control: break Continue
    printf("\n--- Break & Continue Example ---\n");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue; // Skip even numbers

        }
        if (i > 7) {
            break;    // Exit loop when i exceeds 7

        }
        printf("Odd number: %d\n", i);

    }


    return 0;

}

