#include <stdio.h>

int main()
{
    int household;
    unsigned int units;
    long bill;

    printf("Enter household number: ");

    if (scanf("%d", &household) != 1)
    {
        printf("Invalid household number\n");
        return 1;
    }

    printf("Enter units consumed: ");

    if (scanf("%u", &units) != 1)
    {
        printf("Invalid units\n");
        return 1;
    }

    bill = 5000;

    if (units > 200)
        bill += (units - 200) * 450;

    if (units > 100)
        bill += ((units < 200) ? units - 100 : 100) * 225;

    printf("\nHousehold Number: %d\n", household);
    printf("Units Consumed: %u\n", units);
    printf("Total Bill: Rs %ld.%02ld\n", bill / 100, bill % 100);

    return 0;
}
