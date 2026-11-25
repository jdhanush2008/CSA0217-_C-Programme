#include <stdio.h>

int main()
{
    int a = 5, b = 2;
    float x;
    double amount = 125.75;

    printf("Integer Division: %d\n", a / b);

    printf("Floating Division: %.2f\n", (float)a / b);

    x = (float)a / b;
    printf("Type Conversion: %.2f\n", x);

    printf("Double Amount: %.2lf\n", amount);

    printf("Casting Double to Integer: %d\n", (int)amount);

    printf("Correct Paise Calculation: %ld\n",
           (long)(amount * 100 + 0.5));

    return 0;
}
