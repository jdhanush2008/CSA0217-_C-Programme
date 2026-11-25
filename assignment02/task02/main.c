#include <stdio.h>

int calls = 0;

int slow_verify()
{
    calls++;
    printf("Verifying disability card...\n");
    return 1;
}

int main()
{
    int senior, eligible, disability;
    int result;

    printf("Enter senior citizen status (1/0): ");
    scanf("%d", &senior);

    printf("Enter ticket eligibility (1/0): ");
    scanf("%d", &eligible);

    printf("Enter disability card status (1/0): ");
    scanf("%d", &disability);

    result = (senior && eligible) || (disability && slow_verify());

    printf("\nConcession: %s\n", result ? "Granted" : "Not Granted");
    printf("Function Calls: %d\n", calls);

    return 0;
}
