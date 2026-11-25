#include <stdio.h>
#include <string.h>

#define MAX 100

struct date {
    int day, month, year;
};

struct blood_pressure {
    int systolic;
    int diastolic;
};

struct patient {
    char name[100];
    int age;
    char phone[16];
    struct blood_pressure bp;
    struct date visitDate;
};

struct patient patients[MAX];
int count = 0;

void addPatient(struct patient *p)
{
    if (count >= MAX) {
        printf("Patient limit reached\n");
        return;
    }

    patients[count++] = *p;
}

int main()
{
    struct patient p;

    printf("Enter patient name: ");
    scanf(" %99[^\n]", p.name);

    printf("Enter age: ");
    scanf("%d", &p.age);

    printf("Enter phone number: ");
    scanf("%15s", p.phone);

    printf("Enter systolic and diastolic BP: ");
    scanf("%d %d", &p.bp.systolic, &p.bp.diastolic);

    printf("Enter visit date (dd mm yyyy): ");
    scanf("%d %d %d",
          &p.visitDate.day,
          &p.visitDate.month,
          &p.visitDate.year);

    addPatient(&p);

    printf("\nPatient Details\n");
    printf("Name: %s\n", patients[0].name);
    printf("Age: %d\n", patients[0].age);
    printf("Phone: %s\n", patients[0].phone);
    printf("Blood Pressure: %d/%d\n",
           patients[0].bp.systolic,
           patients[0].bp.diastolic);
    printf("Visit Date: %02d/%02d/%04d\n",
           patients[0].visitDate.day,
           patients[0].visitDate.month,
           patients[0].visitDate.year);

    return 0;
}
