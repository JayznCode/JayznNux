#include <stdio.h>

int main() {
    // 1. Declare an integer variable to stroe age
    int age;

    // 2. Prompt the user for input
    printf("Enter your age: ");

    // 3. Read user input from the keyboard (%d for integer, & for address)
    scanf("%d", &age);

    // 4. print the entered value
    printf("You are %d years old. \n", age);

    return 0;

}

