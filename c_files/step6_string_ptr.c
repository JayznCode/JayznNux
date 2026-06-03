#include <stdio.h>

int main() {
    // C handles strings as a character array. 
    // It automatically adds a hidden '\0' (Null) at the end.
    char name[] = "Jae"; 
    char *ptr = name; // Synchronization: ptr points to the start of name

    printf("=== String Memory & Pointer Analysis ===\n");

    // Loop 4 times to see the hidden ghost character at the end!
    for (int i = 0; i < 4; i++) {
        // %c prints the character, %d prints the ASCII code number
        printf("Index [%d] | Address: %p | Char: '%c' | ASCII: %d\n", 
               i, (void*)(ptr + i), *(ptr + i), *(ptr + i));
    }

    return 0;
}
