#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char name[20];
    FILE *fp;

    if (argc != 2)
    {
        printf("Usage: ./program <blood_group>\n");
        return 1;
    }

    if (strcmp(argv[1], "A+") != 0 &&
        strcmp(argv[1], "A-") != 0 &&
        strcmp(argv[1], "B+") != 0 &&
        strcmp(argv[1], "B-") != 0 &&
        strcmp(argv[1], "O+") != 0 &&
        strcmp(argv[1], "O-") != 0 &&
        strcmp(argv[1], "AB+") != 0 &&
        strcmp(argv[1], "AB-") != 0)
    {
        printf("Invalid blood group\n");
        return 1;
    }

    printf("Enter donor name: ");

    if (fgets(name, sizeof(name), stdin) == NULL)
    {
        printf("Input error\n");
        return 1;
    }

    name[strcspn(name, "\n")] = '\0';

    printf("Donor Name: %s\n", name);
    printf("Blood Group: %s\n", argv[1]);

    fp = fopen("donor.txt", "r");

    if (fp == NULL)
    {
        perror("File error");
        return 1;
    }

    fclose(fp);

    return 0;
}
