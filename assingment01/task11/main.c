#include <stdio.h>

#define FIXED_CHARGE 5000L
#define RATE1 0
#define RATE2 225
#define RATE3 450

long long calculate_bill(unsigned int units)
{
    long long bill = FIXED_CHARGE;

    if (units > 200)
        bill += (long long)(units - 200) * RATE3;

    if (units > 100)
    {
        unsigned int slab =
            (units < 200) ? units - 100 : 100;

        bill += (long long)slab * RATE2;
    }

    return bill;
}

int main()
{
    unsigned short previous = 1200;
    unsigned short current = 1530;

    unsigned int units =
        (unsigned short)(current - previous);

    long long bill = calculate_bill(units);

    printf("Previous Reading: %hu\n", previous);
    printf("Current Reading: %hu\n", current);
    printf("Units Consumed: %u\n", units);

    printf("Total Bill: Rs %lld.%02lld\n",
           bill / 100, bill % 100);

    return 0;
}
