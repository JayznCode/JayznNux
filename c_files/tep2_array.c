#include <stdio.h>

int main() {
    int scores[3] = {90, 85, 95};

    // Check the address of each element
    printf("Address of scores[0]: %p\n", (void*)&scores[0]);
    printf("Address of scores[1]: %p\n", (void*)&scores[1]);
    printf("Address of scores[2]: %p\n", (void*)&scores[2]);

    printf("\n");

    // The array name itself is actually the address of the first element
    printf("Value of 'scores' array name: %p\n", (void*)scores);

    return 0;
}
