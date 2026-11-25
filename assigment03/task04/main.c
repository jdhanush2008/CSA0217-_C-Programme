#include <stdio.h>

#define DISTRICTS 38
#define MONTHS 12

void read_rainfall(float rain[DISTRICTS][MONTHS])
{
    for (int i = 0; i < DISTRICTS; i++)
    {
        printf("\nEnter rainfall for District %d:\n", i + 1);

        for (int j = 0; j < MONTHS; j++)
        {
            scanf("%f", &rain[i][j]);
        }
    }
}

void district_totals(float rain[DISTRICTS][MONTHS])
{
    printf("\nAnnual Rainfall:\n");

    for (int i = 0; i < DISTRICTS; i++)
    {
        float total = 0;

        for (int j = 0; j < MONTHS; j++)
            total += rain[i][j];

        printf("District %d: %.2f mm\n", i + 1, total);
    }
}

void monthly_averages(float rain[DISTRICTS][MONTHS])
{
    printf("\nMonthly Average Rainfall:\n");

    for (int j = 0; j < MONTHS; j++)
    {
        float total = 0;

        for (int i = 0; i < DISTRICTS; i++)
            total += rain[i][j];

        printf("Month %d: %.2f mm\n",
               j + 1, total / DISTRICTS);
    }
}

void wettest_month(float rain[DISTRICTS][MONTHS])
{
    float maximum = rain[0][0];
    int district = 0, month = 0;

    for (int i = 0; i < DISTRICTS; i++)
    {
        for (int j = 0; j < MONTHS; j++)
        {
            if (rain[i][j] > maximum)
            {
                maximum = rain[i][j];
                district = i;
                month = j;
            }
        }
    }

    printf("\nWettest District: %d\n", district + 1);
    printf("Month: %d\n", month + 1);
    printf("Rainfall: %.2f mm\n", maximum);
}

void deficient_districts(float rain[DISTRICTS][MONTHS])
{
    float total = 0;

    for (int i = 0; i < DISTRICTS; i++)
        for (int j = 0; j < MONTHS; j++)
            total += rain[i][j];

    float state_average = total / (DISTRICTS * MONTHS);

    printf("\nState Average: %.2f mm\n", state_average);
    printf("Districts below 60%% of state average:\n");

    for (int i = 0; i < DISTRICTS; i++)
    {
        float sum = 0;

        for (int j = 0; j < MONTHS; j++)
            sum += rain[i][j];

        if (sum / MONTHS < 0.60f * state_average)
            printf("District %d\n", i + 1);
    }
}

int main()
{
    float rain[DISTRICTS][MONTHS];

    read_rainfall(rain);

    district_totals(rain);
    monthly_averages(rain);
    wettest_month(rain);
    deficient_districts(rain);

    return 0;
}
