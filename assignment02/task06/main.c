#include <stdio.h>

int main()
{
    double balance, rate, repayment;
    double interest, payment;
    double total_interest = 0;

    int month = 0;

    printf("Enter loan amount: ");
    scanf("%lf", &balance);

    printf("Enter monthly interest rate (%%): ");
    scanf("%lf", &rate);

    printf("Enter monthly repayment: ");
    scanf("%lf", &repayment);

    if (balance <= 0 || rate < 0 || repayment <= 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    if (repayment <= balance * rate / 100)
    {
        printf("Loan cannot be repaid with this amount.\n");
        return 0;
    }

    printf("\nMonth\tInterest\tPayment\t\tBalance\n");

    while (balance > 0.005)
    {
        if (month >= 360)
        {
            printf("Maximum repayment period reached.\n");
            return 0;
        }

        month++;

        interest = balance * rate / 100;
        total_interest += interest;

        balance += interest;

        payment = (repayment < balance) ? repayment : balance;

        balance -= payment;

        if (balance < 0.005)
            balance = 0;

        printf("%d\t%.2f\t\t%.2f\t\t%.2f\n",
               month, interest, payment, balance);
    }

    printf("\nTotal Months: %d\n", month);
    printf("Total Interest: Rs %.2f\n", total_interest);

    return 0;
}
