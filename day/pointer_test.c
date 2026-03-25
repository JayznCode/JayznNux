#include <stdio.h>


int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    /* The array name 'arr' acts as a pointer to the first element (&arr[0]) */
    int *ptr = arr;


    printf("--- Accessing Array with Pointers ---\n");


    for (int i = 0; i < 5; i++) {

        /* ptr + i: moves the pointer by (i * sizeof(int)) bytes
            *(ptr + i): accesses the value at that specific memory address */
        printf("Address: %p | Value: %d\n", (void*)(ptr + i), *(ptr + i));

    }

    return 0;

}

