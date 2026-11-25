#include <stdio.h>

#define FIXED_CHARGE 5000L
#define RATE1 0
#define RATE2 225
#define RATE3 450

unsigned int consumption(unsigned short previous,
                         unsigned short current)
{
    return (unsigned short)(current - previous);
}

long calculate_bill(unsigned int units)
{
    long bill = FIXED_CHARGE;

    if (units > 200)
        bill += (units - 200) * RATE3;

    if (units > 100)
    {
        int slab = (units < 200) ? units - 100 : 100;
        bill += slab * RATE2;
    }

    return bill;
}

int main()
{
    unsigned int previous, current, units;
    long bill;

    printf("Enter previous reading: ");

    if (scanf("%u", &previous) != 1 || previous > 65535)
    {
        printf("Invalid previous reading\n");
        return 1;
    }

    printf("Enter current reading: ");

    if (scanf("%u", &current) != 1 || current > 65535)
    {
        printf("Invalid current reading\n");
        return 1;
    }

    if (current < previous && previous < 65000)
    {
        printf("Invalid meter reading\n");
        return 1;
    }

    units = consumption((unsigned short)previous,
                        (unsigned short)current);

    bill = calculate_bill(units);

    printf("\nUnits Consumed: %u\n", units);
    printf("Energy and Fixed Charges: Rs %ld.%02ld\n",
           bill / 100, bill % 100);

    return 0;
}
