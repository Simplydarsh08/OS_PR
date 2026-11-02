#include <stdio.h>

#define MAX 20

int main(void)
{
    int n, i, j, temp;
    int bt[MAX], p[MAX], wt[MAX], tat[MAX];

    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX)
    {
        printf("Enter a process count between 1 and %d.\n", MAX);
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("Enter burst time of P%d: ", p[i]);
        if (scanf("%d", &bt[i]) != 1 || bt[i] < 0)
        {
            printf("Burst time must be a non-negative integer.\n");
            return 1;
        }
    }

    /* Sort by burst time (non-preemptive SJF). */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    return 0;
}
