#include <stdio.h>

int main(void) {
    // Declare an integer array with 3 elements
    int arr[3] = {10, 20, 30};
    
    // The array name 'arr' itself decays into the address of the first element (&arr[0])
    int *ptr = arr; 

    printf("--- 1. Comparing Array Indexing and Pointer Arithmetic ---\n");
    for (int i = 0; i < 3; i++) {
        // Accessing via array subscript vs pointer offset
        printf("arr[%d] value: %d | Address: %p\n", i, arr[i], (void *)&arr[i]);
        printf("*(ptr + %d) value: %d | Address: %p\n", i, *(ptr + i), (void *)(ptr + i));
    }

    printf("\n--- 2. Moving Pointer Directly (ptr++) ---\n");
    // We can increment the pointer itself to jump to the next memory block
    for (int i = 0; i < 3; i++) {
        printf("Current pointer address: %p | Value: %d\n", (void *)ptr, *ptr);
        ptr++; // Moves forward by sizeof(int) bytes (typically 4 bytes)
    }

    return 0;
}
