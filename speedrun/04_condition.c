#include <stdio.h>

int main() {
    // 1. Declare an integer variable to store age
    int age;

    // 2. Prompt the user for input
    printf("Enter your age: ");

    // 3. Read user input and store it at the address of 'age'
    scanf("%d", &age);

    // 4. Check conditions using if-else statements
    if (age >= 20) {
        printf("Youi are an adult.\n");
    } else {
        printf("You are a minor.\n");
    }

    return 0;

}

