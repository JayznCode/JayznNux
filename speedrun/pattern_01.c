#include <stdio.h>

int main(void) {
    
    return 0;
}





int num = 0;
printf("Enter a number: ");
scanf("%d", &num);
printf("You entered: %d\n", num);



for (int i = 0; i < 10; i++) {
    // Loop body
}







int i = 0;
while (i < 5) {
    // Loop body
    i++;
}

int arr[5] = {10, 20, 30, 40, 50};
for (int i = 0; i < 5; i++) {
    printf("%d\n", arr[i]);
}







int val = 42;
int *ptr = &val;
printf("Value: %d, Address: %p\n", *ptr, (void *)ptr);






int *arr = malloc(sizeof(int) * 10);
if (arr == NULL) {
    return 1; // Allocation failed
}

// Use memory...

free(arr);
arr = NULL;
