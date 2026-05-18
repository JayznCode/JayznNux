#include <stdio.h>

int main() {
    char grade = 'A';
    int age = 46;
    double weight = 72.5;

    // sizeof() operator returns the size in bytes
    // %lu is used for size_t, %p is used for memory addresses
    printf("Size of char:   %lu byte(s)  | Address: %p\n", sizeof(grade), (void*)&grade);
    printf("Size of int:    %lu byte(s)  | Address: %p\n", sizeof(age), (void*)&age);
    printf("Size of double: %lu byte(s)  | Address: %p\n", sizeof(weight), (void*)&weight);

    return 0;
}
