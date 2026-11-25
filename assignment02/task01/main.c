#include <stdio.h>

int main()
{
    float price, gross, discount, tax, total, net;
    int qty, senior;

    printf("Enter price: ");
    scanf("%f", &price);

    printf("Enter quantity: ");
    scanf("%d", &qty);

    printf("Senior citizen? (1-Yes, 0-No): ");
    scanf("%d", &senior);

    gross = price * qty;

    discount = senior ? gross * 15 / 100 : 0;

    tax = gross * 5 / 100;

    total = gross - discount + tax;

    net = (total > 1000) ? total - 50 : total;

    printf("\nGross Amount: %.2f\n", gross);
    printf("Discount: %.2f\n", discount);
    printf("GST: %.2f\n", tax);
    printf("Total Amount: %.2f\n", total);
    printf("Net Amount: %.2f\n", net);

    return 0;
}
