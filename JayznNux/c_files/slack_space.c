#include <stdio.h>

// A structure representing a data packet
struct MyData {
    char a;     // 1 byte
    int b;      // 4 bytes
    char c;     // 1 byte
};

int main() {
    struct MyData data;

    printf("--- Analysis of 'MyData' Structure ---\n");
    printf("Logical size (1+4+1): 6 bytes\n");
    printf("Actual size (sizeof): %zu bytes\n", sizeof(data));
    
    printf("\n--- Memory Address Layout ---\n");
    printf("Address of data.a: %p\n", (void*)&data.a);
    printf("Address of data.b: %p\n", (void*)&data.b);
    printf("Address of data.c: %p\n", (void*)&data.c);

    return 0;
}
