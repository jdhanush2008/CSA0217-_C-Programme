#include <stdio.h>

#define MAX_ITEMS 10
#define MAX_SALES 100

enum item_type {
    PACKAGED,
    COOKED,
    COMBO
};

struct date {
    int day, month, year;
};

struct item {
    int id;
    char name[30];
    float price;
    int stock;
    float revenue;

    enum item_type type;

    union {
        struct {
            struct date expiry;
        } packaged;

        struct {
            int hour, minute;
        } cooked;

        struct {
            int count;
            int item_ids[3];
        } combo;

    } details;
};

struct sale {
    int item_id;
    int quantity;
    float amount;
};

struct item inventory[MAX_ITEMS];
struct sale sales[MAX_SALES];

static int item_count = 0;
static int sale_count = 0;

int date_days(struct date d)
{
    int days = d.year * 365 + d.day;

    for (int i = 1; i < d.month; i++)
    {
        if (i == 2)
            days += 28;
        else if (i == 4 || i == 6 ||
                 i == 9 || i == 11)
            days += 30;
        else
            days += 31;
    }

    return days;
}

struct item *find_item(int id)
{
    for (int i = 0; i < item_count; i++)
    {
        if (inventory[i].id == id)
            return &inventory[i];
    }

    return NULL;
}

void add_item(struct item x)
{
    if (item_count < MAX_ITEMS)
        inventory[item_count++] = x;
}

int check_stock(struct item *p, int quantity)
{
    if (p == NULL)
        return 0;

    if (p->type != COMBO)
        return p->stock >= quantity;

    for (int i = 0; i < p->details.combo.count; i++)
    {
        struct item *component =
            find_item(p->details.combo.item_ids[i]);

        if (component == NULL ||
            component->stock < quantity)
            return 0;
    }

    return 1;
}

void record_sale(int id, int quantity)
{
    struct item *p = find_item(id);

    if (p == NULL || quantity <= 0)
    {
        printf("Invalid item or quantity\n");
        return;
    }

    if (!check_stock(p, quantity))
    {
        printf("Insufficient stock!\n");
        return;
    }

    if (sale_count >= MAX_SALES)
    {
        printf("Sales limit reached\n");
        return;
    }

    if (p->type == COMBO)
    {
        for (int i = 0; i < p->details.combo.count; i++)
        {
            struct item *component =
                find_item(p->details.combo.item_ids[i]);

            component->stock -= quantity;
        }
    }
    else
    {
        p->stock -= quantity;
    }

    float amount = p->price * quantity;

    p->revenue += amount;

    sales[sale_count].item_id = id;
    sales[sale_count].quantity = quantity;
    sales[sale_count].amount = amount;

    sale_count++;

    printf("Sale successful!\n");
    printf("Item: %s\n", p->name);
    printf("Amount: Rs %.2f\n", amount);
}

void expiry_warning(struct date today)
{
    int current = date_days(today);

    printf("\nExpiring Items:\n");

    for (int i = 0; i < item_count; i++)
    {
        if (inventory[i].type == PACKAGED)
        {
            int expiry =
                date_days(inventory[i].details.packaged.expiry);

            int difference = expiry - current;

            if (difference >= 0 && difference <= 2)
            {
                printf("%s expires within %d days\n",
                       inventory[i].name, difference);
            }
        }
    }
}

void bill_summary(void)
{
    struct item temp[MAX_ITEMS];

    for (int i = 0; i < item_count; i++)
        temp[i] = inventory[i];

    for (int i = 0; i < item_count - 1; i++)
    {
        for (int j = 0; j < item_count - i - 1; j++)
        {
            if (temp[j].revenue < temp[j + 1].revenue)
            {
                struct item t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    printf("\n----- DAILY BILL SUMMARY -----\n");

    for (int i = 0; i < item_count; i++)
    {
        printf("%s : Rs %.2f\n",
               temp[i].name, temp[i].revenue);
    }
}

int main(void)
{
    struct date today = {24, 11, 2026};

    struct item a = {
        .id = 1,
        .name = "Milk Packet",
        .price = 30,
        .stock = 10,
        .type = PACKAGED,
        .details.packaged.expiry = {25, 11, 2026}
    };

    struct item b = {
        .id = 2,
        .name = "Sandwich",
        .price = 50,
        .stock = 8,
        .type = COOKED,
        .details.cooked = {9, 30}
    };

    struct item c = {
        .id = 3,
        .name = "Combo Meal",
        .price = 75,
        .stock = 0,
        .type = COMBO,
        .details.combo = {2, {1, 2}}
    };

    add_item(a);
    add_item(b);
    add_item(c);

    printf("COLLEGE CANTEEN BILLING SYSTEM\n");

    record_sale(1, 2);
    record_sale(2, 1);
    record_sale(3, 1);

    record_sale(1, 20);

    expiry_warning(today);

    bill_summary();

    return 0;
}
