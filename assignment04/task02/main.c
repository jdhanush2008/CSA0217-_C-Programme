#include <stdio.h>
#include <string.h>

struct date {
    int day, month, year;
};

struct address {
    char city[30];
    int pincode;
};

struct parcel {
    int id;
    float weight;
    struct date booked;
    struct address sender;
    struct address receiver;
    char service[15];
    float charge;
};

void print_parcel(const struct parcel *p)
{
    printf("%d %.1f kg %s-%d %02d/%02d/%04d\n",
           p->id,
           p->weight,
           p->receiver.city,
           p->receiver.pincode,
           p->booked.day,
           p->booked.month,
           p->booked.year);
}

void sort_by_weight(struct parcel p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (p[j].weight < p[min].weight)
                min = j;
        }

        if (min != i)
        {
            struct parcel temp = p[i];
            p[i] = p[min];
            p[min] = temp;
        }
    }
}

void search_city(struct parcel p[], int n, char city[])
{
    printf("\nParcels for %s:\n", city);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(p[i].receiver.city, city) == 0)
            print_parcel(&p[i]);
    }
}

int main(void)
{
    struct parcel list[3] = {
        {501, 4.5f, {12,10,2026},
         {"Madurai",625001}, {"Madurai",625001},
         "Normal",100},

        {502, 1.2f, {12,10,2026},
         {"Chennai",600001}, {"Chennai",600077},
         "Express",150},

        {503, 2.8f, {13,10,2026},
         {"Salem",636001}, {"Coimbatore",641001},
         "Normal",120}
    };

    int n = 3;

    sort_by_weight(list, n);

    printf("Sorted Parcels:\n");

    for (int i = 0; i < n; i++)
        print_parcel(&list[i]);

    search_city(list, n, "Chennai");

    printf("\nThird parcel receiver PIN: %d\n",
           list[2].receiver.pincode);

    struct parcel *ptr = &list[2];

    printf("Using pointer: %d\n",
           ptr->receiver.pincode);

    return 0;
}
