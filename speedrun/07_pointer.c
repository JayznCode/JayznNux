#include <stdio.h>

int main(void) {
    int num = 100;
    int *ptr = &num; // prt stores the memory address of num

    printf("variable value: %d\n", num);
    printf("Variable address: %p\n", (void *)&num);
    printf("Pointer value (Address): %p\n", (void *)ptr);
    printf("Value via pointer (Dereference): %d\n", *ptr);


    // Modify value via pointer
    *ptr = 200;
    printf("Changed num value: %d\n", num);

    return 0;

}


