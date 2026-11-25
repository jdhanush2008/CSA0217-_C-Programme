#include <stdio.h>

unsigned long original_checks = 0;
unsigned long improved_checks = 0;

int original_prime(unsigned long n)
{
    original_checks = 0;

    if (n < 2)
        return 0;

    for (unsigned long i = 2; i < n; i++)
    {
        original_checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

int improved_prime(unsigned long n)
{
    improved_checks = 0;

    if (n < 2)
        return 0;

    if (n == 2)
        return 1;

    if (n % 2 == 0)
    {
        improved_checks++;
        return 0;
    }

    for (unsigned long i = 3; i <= n / i; i += 2)
    {
        improved_checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    unsigned long numbers[] = {97, 100, 7919, 1000003};

    int n = sizeof(numbers) / sizeof(numbers[0]);

    printf("Number\tOriginal\tImproved\n");

    for (int i = 0; i < n; i++)
    {
        int result1 = original_prime(numbers[i]);
        int result2 = improved_prime(numbers[i]);

        printf("%lu\t%lu\t\t%lu\n",
               numbers[i],
               original_checks,
               improved_checks);

        printf("Result: %s\n",
               result2 ? "Prime" : "Not Prime");
    }

    return 0;
}
