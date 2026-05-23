#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("How many students? ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Enter score for student %d: ", i);
        // 여기서 쉘이 던져줄 점수를 기다립니다.
        scanf("%d", &arr[i]); 
    }

    printf("\n--- Results ---\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d score: %d\n", i, arr[i]);
    }

    free(arr);
    return 0;
}
