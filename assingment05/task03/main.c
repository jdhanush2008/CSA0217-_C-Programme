#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int id;
    char name[30];
    char group[5];
    int age;
} Donor;

int main()
{
    FILE *text, *binary;
    Donor d;
    int n = 10;

    text = fopen("donors.txt", "w");
    binary = fopen("donors.dat", "wb");

    if (text == NULL || binary == NULL)
    {
        perror("File opening error");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        d.id = 1001 + i;
        snprintf(d.name, sizeof(d.name), "Donor%d", i + 1);
        snprintf(d.group, sizeof(d.group), "O+");
        d.age = 20 + i;

        fprintf(text, "%d %s %s %d\n",
                d.id, d.name, d.group, d.age);

        fwrite(&d, sizeof(Donor), 1, binary);
    }

    fclose(text);
    fclose(binary);

    printf("10 donor records written successfully.\n");

    text = fopen("donors.txt", "r");
    binary = fopen("donors.dat", "rb");

    if (text == NULL || binary == NULL)
    {
        perror("File reading error");
        return 1;
    }

    printf("\nReading binary records:\n");

    while (fread(&d, sizeof(Donor), 1, binary) == 1)
    {
        printf("%d %s %s %d\n",
               d.id, d.name, d.group, d.age);
    }

    fclose(text);
    fclose(binary);

    return 0;
}
