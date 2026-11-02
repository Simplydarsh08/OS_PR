#include <stdio.h>

#define MAX 20

int main(void)
{
    int n, tq, i, time = 0, done;
    int bt[MAX], rem[MAX], wt[MAX] = {0}, tat[MAX];

    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX)
    {
        printf("Enter a process count between 1 and %d.\n", MAX);
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter burst time of P%d: ", i + 1);
        if (scanf("%d", &bt[i]) != 1 || bt[i] < 0)
        {
            printf("Burst time must be a non-negative integer.\n");
            return 1;
        }
        rem[i] = bt[i];
    }

    printf("Enter time quantum: ");
    if (scanf("%d", &tq) != 1 || tq <= 0)
    {
        printf("Time quantum must be a positive integer.\n");
        return 1;
    }

    /* All processes are assumed to arrive at time zero. */
    do
    {
        done = 1;
        for (i = 0; i < n; i++)
        {
            if (rem[i] > 0)
            {
                done = 0;
                if (rem[i] > tq)
                {
                    time += tq;
                    rem[i] -= tq;
                }
                else
                {
                    time += rem[i];
                    wt[i] = time - bt[i];
                    rem[i] = 0;
                }
            }
        }
    } while (!done);

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    return 0;
}
