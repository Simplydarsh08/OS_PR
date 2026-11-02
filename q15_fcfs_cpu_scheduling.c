#include <stdio.h>

#define MAX 20

int main(void)
{
    int n, i;
    int bt[MAX], wt[MAX], tat[MAX];
    float avgwt = 0.0f, avgtat = 0.0f;

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
    }

    wt[0] = 0;
    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for (i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f\n", avgwt / n);
    printf("Average Turnaround Time = %.2f\n", avgtat / n);

    return 0;
}
