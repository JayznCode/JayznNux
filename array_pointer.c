#include <stdio.h>

int main(void) {
    // 1. Allocate 3 integers sequentially in memory (Total 12 bytes)
    int arr[3] = {10, 20, 30};

    // 2. Assign the array name (which is a address) to a pointer
    int *ptr = arr; 

    printf("==================================================\n");
    printf(" 1. Address Comparison (Array Name vs Element [0])\n");
    printf("==================================================\n");
    printf("Array name (arr) points to       : %p\n", (void*)arr);
    printf("First element (&arr[0]) address  : %p\n", (void*)&arr[0]);
    printf("Pointer variable (ptr) holds     : %p\n", (void*)ptr);

    printf("\n==================================================\n");
    printf(" 2. Pointer Arithmetic (Moving through Memory)\n");
    printf("==================================================\n");
    // Notice how the hexadecimal address increments by 4 bytes (sizeof(int))
    printf("ptr     (points to arr[0]) : %p -> value: %d\n", (void*)ptr, *ptr);
    printf("ptr + 1 (points to arr[1]) : %p -> value: %d\n", (void*)(ptr + 1), *(ptr + 1));
    printf("ptr + 2 (points to arr[2]) : %p -> value: %d\n", (void*)(ptr + 2), *(ptr + 2));

    return 0;
}
