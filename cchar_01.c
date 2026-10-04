

#include <stdio.h>

int main(void)
{
    char name[] = "ABC";
    char *p = name;

    printf("%c\n", *p);
    printf("%c\n", *(p + 2));
    printf("%c\n", *(p + 1));

    return 0;

}

