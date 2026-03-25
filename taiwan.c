#include <stdlib.h>

int main() {
    int n = 5; // [int n]
    
    // [void*] becomes [int*] using [sizeof] and [malloc]
    int *ptr = (int *)malloc(n * sizeof(int)); 

    if (ptr != NULL) { // [Safety Check]
        // Use memory here...
        
        free(ptr); // [free]
    }
    
    return 0;
}
