#include <stdio.h>

#define FIXED_CHARGE 5000

int main()
{
    int units = 150;
    long bill = FIXED_CHARGE;

    bill += (units - 100) * 225;

#ifdef DEBUG
    printf("Debug: Units = %d\n", units);
    printf("Debug: Bill in paise = %ld\n", bill);
#endif

    printf("Units Consumed: %d\n", units);
    printf("Total Bill: Rs %ld.%02ld\n", bill / 100, bill % 100);

    return 0;
}
