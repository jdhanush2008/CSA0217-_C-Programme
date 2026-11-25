#include <stdio.h>

int main()
{
    long long normal_rate, peak_rate;
    long long fixed_charge;
    long long total_wh = 0;
    long long total_paise = 0;
    long long watt_hours;
    int peak;
    int n;

    printf("Enter normal tariff (paise per kWh): ");
    scanf("%lld", &normal_rate);

    printf("Enter fixed charge (paise): ");
    scanf("%lld", &fixed_charge);

    peak_rate = (normal_rate * 6) / 5;

    printf("Enter number of readings: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("\nEnter watt-hours for reading %d: ", i);
        if (scanf("%lld", &watt_hours) != 1 || watt_hours < 0)
        {
            printf("Invalid reading\n");
            return 1;
        }

        printf("Peak hour? (1 = Yes, 0 = No): ");
        if (scanf("%d", &peak) != 1 || (peak != 0 && peak != 1))
        {
            printf("Invalid peak-hour value\n");
            return 1;
        }

        total_wh += watt_hours;

        if (peak)
            total_paise += watt_hours * peak_rate / 1000;
        else
            total_paise += watt_hours * normal_rate / 1000;
    }

    total_paise += fixed_charge;

    printf("\n----- SMART METER BILL -----\n");

    printf("Total Energy: %lld Wh\n", total_wh);

    printf("Energy Charge: Rs %lld.%02lld\n",
           total_paise / 100, total_paise % 100);

    return 0;
}
