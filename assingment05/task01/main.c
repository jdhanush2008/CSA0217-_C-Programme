#include <stdio.h>

long long calls = 0;

long long power_linear(long long base, int exp)
{
    calls++;

    if (exp == 0)
        return 1;

    return base * power_linear(base, exp - 1);
}

long long power_fast(long long base, int exp)
{
    calls++;

    if (exp == 0)
        return 1;

    long long half = power_fast(base, exp / 2);

    if (exp % 2 == 0)
        return half * half;
    else
        return base * half * half;
}

int digital_root(int n)
{
    if (n < 10)
        return n;

    int sum = 0;

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return digital_root(sum);
}

int main()
{
    calls = 0;
    printf("Digital Root of 9875 = %d\n", digital_root(9875));

    calls = 0;
    printf("Linear Power = %lld\n", power_linear(2, 30));
    printf("Linear Calls = %lld\n", calls);

    calls = 0;
    printf("Fast Power = %lld\n", power_fast(2, 30));
    printf("Fast Calls = %lld\n", calls);

    return 0;
}
