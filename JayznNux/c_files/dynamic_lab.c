#include <stdio.h>
#include <stdlib.h> // for malloc and free

int main() {
    // 1. Trying to allocate exactly 3 bytes (non-standard size)
    char *small_room1 = (char *)malloc(3);
    char *small_room2 = (char *)malloc(3);

    // 2. Trying to allocate 8 bytes (standard 64-bit size)
    long *standard_room = (long *)malloc(sizeof(long));

    printf("--- Dynamic Allocation Analysis ---\n");
    
    printf("3-byte room 1 address: %p\n", (void*)small_room1);
    printf("3-byte room 2 address: %p\n", (void*)small_room2);
    
    // Distance between two small rooms
    printf("Distance between small rooms: %ld bytes\n", (long)small_room2 - (long)small_room1);

    printf("8-byte standard room address: %p\n", (void*)standard_room);

    // Clean up
    free(small_room1);
    free(small_room2);
    free(standard_room);

    return 0;
}
