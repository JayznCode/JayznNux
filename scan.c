#include <stdio.h>
#include <string.h>

void inspect_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    char buffer[1024];
    char *forbidden_word = "HACK"; // We are looking for this word

    if (fp == NULL) return;

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, forbidden_word)) {
            printf("[DANGER] Forbidden content detected in: %s\n", filename);
            fclose(fp);
            return;
        }
    }
    printf("[SAFE] %s passed inspection.\n", filename);
    fclose(fp);
}

int main() {
    // Let's inspect a file named 'data.txt'
    inspect_file("data.txt");
    return 0;
}
