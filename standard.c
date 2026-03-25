#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

int main() {
    // 1. [int n] - Determine how many elements you need
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // 2. [sizeof] & [malloc] & [void*]
    // (int *) is type casting from the (void *) returned by malloc
    int *ptr = (int *)malloc(n * sizeof(int));

    // 3. Check if allocation was successful
    if (ptr == NULL) {
        printf("Memory not allocated. Exit.\n");
        return 1;
    }

    // [Use the memory here...]
    printf("Memory successfully allocated using malloc.\n");

    // 4. [free] - Crucial step to prevent memory leaks
    free(ptr);
    printf("Memory successfully freed.\n");

    return 0;
}
