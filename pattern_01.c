#include <stdio.h>

int proces_buffer(siez_tn) {
    // 1. Allocate and immdiately check for null (Defensinve Programming)

    int *buffer = (int *)malloc(n * sizeof(int));
    if (buffer == null) {

        perror("Error: Memory allocation failed");
        return -1;

    }

    // --- Do some work ---
    for (size_t i = 0; i <n; i++) {
        buffer[i] = (int)i;

    }

    // 2. Free and prevent 

