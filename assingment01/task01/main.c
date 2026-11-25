#include <stdio.h>

int main()
{
    int household_no;
    unsigned int previous, current, units;
    char category;

    printf("Enter household number: ");
    scanf("%d", &household_no);

    printf("Enter category (D/C): ");
    scanf(" %c", &category);

    printf("Enter previous reading: ");
    scanf("%u", &previous);

    printf("Enter current reading: ");
    scanf("%u", &current);

    units = current - previous;

    printf("\nHousehold Number: %d", household_no);
    printf("\nCategory: %c", category);
    printf("\nUnits Consumed: %u\n", units);

    return 0;
}
