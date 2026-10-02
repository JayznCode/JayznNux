#include <stdio.h>

int main(void)
{
    double num1;
    double num2;
    char operator;

    printf("첫 번째 숫자: ");
    scanf("%lf", &num1);

    printf("연산자 (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("두 번째 숫자: ");
    scanf("%lf", &num2);

    switch (operator)
    {
        case '+':
            printf("결과: %.2f\n", num1 + num2);
            break;

        case '-':
            printf("결과: %.2f\n", num1 - num2);
            break;

        case '*':
            printf("결과: %.2f\n", num1 * num2);
            break;

        case '/':
            if (num2 != 0)
            {
                printf("결과: %.2f\n", num1 / num2);
            }
            else
            {
                printf("0으로 나눌 수 없습니다.\n");
            }
            break;

        default:
            printf("잘못된 연산자입니다.\n");
    }

    return 0;
}

