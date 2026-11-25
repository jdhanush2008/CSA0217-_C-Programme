#include <stdio.h>

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void bubble_sort(int a[], int n)
{
    int comparisons = 0, swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                swaps++;
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }

    printf("Bubble Sort: ");
    display(a, n);

    printf("Comparisons = %d, Swaps = %d\n",
           comparisons, swaps);
}

void selection_sort(int a[], int n)
{
    int comparisons = 0, swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons++;

            if (a[j] < a[min])
                min = j;
        }

        if (min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
            swaps++;
        }
    }

    printf("Selection Sort: ");
    display(a, n);

    printf("Comparisons = %d, Swaps = %d\n",
           comparisons, swaps);
}

void insertion_sort(int a[], int n)
{
    int comparisons = 0, shifts = 0;

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisons++;

            if (a[j] > key)
            {
                a[j + 1] = a[j];
                shifts++;
                j--;
            }
            else
                break;
        }

        a[j + 1] = key;
    }

    printf("Insertion Sort: ");
    display(a, n);

    printf("Comparisons = %d, Shifts = %d\n",
           comparisons, shifts);
}

int main()
{
    int a[] = {45, 12, 89, 23, 67, 10};
    int b[] = {45, 12, 89, 23, 67, 10};
    int c[] = {45, 12, 89, 23, 67, 10};

    int n = 6;

    bubble_sort(a, n);
    selection_sort(b, n);
    insertion_sort(c, n);

    return 0;
}
