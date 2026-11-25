#include <stdio.h>

#define MAX_CANDIDATES 12
#define MAX_VOTES 5000

int main()
{
    int votes[MAX_VOTES];
    int count[MAX_CANDIDATES + 1] = {0};

    int candidates, total;
    int valid = 0, invalid = 0;

    printf("Enter number of candidates: ");
    scanf("%d", &candidates);

    if (candidates < 1 || candidates > MAX_CANDIDATES)
    {
        printf("Invalid number of candidates\n");
        return 1;
    }

    printf("Enter total number of votes: ");
    scanf("%d", &total);

    if (total < 1 || total > MAX_VOTES)
    {
        printf("Invalid number of votes\n");
        return 1;
    }

    printf("Enter candidate number for each vote:\n");

    for (int i = 0; i < total; i++)
    {
        scanf("%d", &votes[i]);

        if (votes[i] >= 1 && votes[i] <= candidates)
        {
            count[votes[i]]++;
            valid++;
        }
        else
        {
            invalid++;
        }
    }

    printf("\nValid Votes: %d\n", valid);
    printf("Invalid Votes: %d\n", invalid);

    /* Sort candidates by vote count */

    int candidate_id[MAX_CANDIDATES];

    for (int i = 0; i < candidates; i++)
        candidate_id[i] = i + 1;

    for (int i = 0; i < candidates - 1; i++)
    {
        for (int j = 0; j < candidates - i - 1; j++)
        {
            if (count[candidate_id[j]] <
                count[candidate_id[j + 1]])
            {
                int temp = candidate_id[j];

                candidate_id[j] = candidate_id[j + 1];
                candidate_id[j + 1] = temp;
            }
        }
    }

    printf("\nElection Results:\n");

    for (int i = 0; i < candidates; i++)
    {
        int id = candidate_id[i];

        printf("Candidate %d: %d votes\n",
               id, count[id]);
    }

    /* Winner and tie detection */

    int highest = count[candidate_id[0]];
    int tie = 0;

    for (int i = 1; i < candidates; i++)
    {
        if (count[candidate_id[i]] == highest)
            tie = 1;
    }

    if (tie)
    {
        printf("\nElection Result: TIE\n");
        printf("Candidates with highest votes:\n");

        for (int i = 0; i < candidates; i++)
        {
            int id = candidate_id[i];

            if (count[id] == highest)
                printf("Candidate %d\n", id);
        }
    }
    else
    {
        printf("\nWinner: Candidate %d\n",
               candidate_id[0]);
    }

    return 0;
}
