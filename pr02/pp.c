#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct process
{
    int pid;
    int at;
    int bt;
    int p;
    int ct, wt, tat, completed, btr;
};
typedef struct process p;
int tot_tt = 0, tot_wt = 0;
int main()
{
    int n;
    printf("Enter the Number of Process : ");
    scanf("%d", &n);
    int completed = 0, curt = 0;
    p *a = (p *)calloc(n, sizeof(p));

    for (int i = 0; i < n; i++)
    {
        a[i].pid = i + 1;
        printf("AT of p%d : ", i + 1);
        scanf("%d", &a[i].at);
        printf("BT of p%d : ", i + 1);
        scanf("%d", &a[i].bt);
        printf("PR of p%d : ", i + 1);
        scanf("%d", &a[i].p);
        a[i].completed = 0;
        a[i].btr = a[i].bt;
    }

    while (completed != n)
    {
        int min_id = -1;
        int min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (a[i].at <= curt && !a[i].completed)
            {
                if (a[i].p < min)
                {
                    min = a[i].p;
                    min_id = i;
                }
                if (a[i].p == min)
                {
                    if (a[i].at < a[min_id].at)
                    {
                        min = a[i].p;
                        min_id = i;
                    }
                }
            }
        }
        if (min_id == -1)
        {
            curt++;
        }
        else
        {
            curt++;
            a[min_id].btr -= 1;
            printf("|P%d %d", a[min_id].pid, curt);
            if (a[min_id].btr == 0)
            {
                a[min_id].ct = curt;
                a[min_id].tat = a[min_id].ct - a[min_id].at;
                a[min_id].wt = a[min_id].tat - a[min_id].bt;

                tot_tt += a[min_id].tat;
                tot_wt += a[min_id].wt;

                completed++;
                a[min_id].completed = 1;
            }
        }
    }

    printf("\nPID\tAT\tBT\tPR\tWT\tTT\tCT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", a[i].pid, a[i].at, a[i].bt, a[i].p, a[i].wt, a[i].tat, a[i].ct);
    }
    printf("\nThe Average Total Time is %f\n", ((float)tot_tt / n));
    printf("\nThe Average Waiting Time is %f\n", ((float)tot_wt / n));

    return 1;
}
