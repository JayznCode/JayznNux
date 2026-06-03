#include <stdio.h>

// 1. Call by Value: Copying values (Original variables will NOT change)
void swap_by_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// 2. Call by Reference: Passing addresses (Original variables WILL change)
void swap_by_reference(int *a, int *b) {
    int temp = *a;  // Go to address 'a' and grab the value
    *a = *b;        // Go to address 'a' and overwrite it with value at address 'b'
    *b = temp;       // Go to address 'b' and write the stored temp value
}

int main() {
    int x = 10;
    int y = 20;

    printf("--- Before Swap ---\n");
    printf("x = %d, y = %d\n\n", x, y);

    // Test 1: Trying to swap using values
    swap_by_value(x, y);
    printf("--- After swap_by_value() ---\n");
    printf("x = %d, y = %d (No change!)\n\n", x, y);

    // Test 2: Trying to swap using memory addresses
    swap_by_reference(&x, &y);
    printf("--- After swap_by_reference() ---\n");
    printf("x = %d, y = %d (Successfully changed!)\n", x, y);

    return 0;
}
