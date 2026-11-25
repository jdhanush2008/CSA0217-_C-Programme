#include <stdio.h>

/* Global variable */
int global_token = 1000;

/* Static local variable */
int next_token(void)
{
    static int token = 1000;
    return ++token;
}

/* Automatic variable */
int auto_token(void)
{
    int token = 1000;
    return ++token;
}

/* Global variable implementation */
int extern_token(void)
{
    return ++global_token;
}

int main(void)
{
    printf("STATIC:\n");

    for (int i = 0; i < 3; i++)
        printf("%d ", next_token());

    printf("\n\nAUTO:\n");

    for (int i = 0; i < 3; i++)
        printf("%d ", auto_token());

    printf("\n\nEXTERN / GLOBAL:\n");

    for (int i = 0; i < 3; i++)
        printf("%d ", extern_token());

    printf("\n\nREGISTER:\n");

    for (register int i = 1001; i <= 1003; i++)
        printf("%d ", i);

    printf("\n");

    return 0;
}
