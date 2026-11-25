#include <stdio.h>
#include <string.h>

#define MAX 500
#define SIZE 30

int main()
{
    char names[MAX][SIZE];
    char temp[SIZE];
    char search[SIZE];

    int n;

    printf("Enter number of residents: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of residents\n");
        return 1;
    }

    getchar();

    for (int i = 0; i < n; i++)
    {
        printf("Enter name %d: ", i + 1);

        if (fgets(names[i], SIZE, stdin) == NULL)
            return 1;

        names[i][strcspn(names[i], "\n")] = '\0';
    }

    /* Sorting names alphabetically */

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("\nSorted Names:\n");

    for (int i = 0; i < n; i++)
        printf("%s\n", names[i]);

    /* Detect duplicate names */

    printf("\nDuplicate Names:\n");

    int found = 0;

    for (int i = 1; i < n; i++)
    {
        if (strcmp(names[i], names[i - 1]) == 0)
        {
            printf("%s\n", names[i]);
            found = 1;
        }
    }

    if (!found)
        printf("No duplicates found\n");

    /* Binary search */

    printf("\nEnter name to search: ");
    fgets(search, SIZE, stdin);
    search[strcspn(search, "\n")] = '\0';

    int low = 0, high = n - 1, mid;
    int position = -1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        int result = strcmp(names[mid], search);

        if (result == 0)
        {
            position = mid;
            break;
        }
        else if (result < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (position != -1)
        printf("Name found at position %d\n", position + 1);
    else
        printf("Name not found\n");

    return 0;
}
