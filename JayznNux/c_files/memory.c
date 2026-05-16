#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;

    // These commands MUST be inside the main function
    printf("Size of a: %zu bytes\n", sizeof(a));
    printf("Address of a: %p\n", (void*)&a);
    printf("Address of b: %p\n", (void*)&b);

    return 0;
}
