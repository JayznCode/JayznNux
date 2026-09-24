#include <stdio.h>
#include <stdlib.h>

int main() {
    // Open the file in read mode
    FILE *file = fopen("practice.txt", "r");
    
    // Check if the file opened successfully
    if (file == NULL) {
        printf("Error: Cannot open the file.\n");
        return 1;
    }

    char buffer[256];
    
    // Read and print line by line
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);
    return 0;
}
