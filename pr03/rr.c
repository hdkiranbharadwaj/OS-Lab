#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct process
{
    int pid;
    int at;
    int bt;
    int ct, wt, tat, completed, btr, visited;
};
typedef struct process p;
int q[100];
void sort(p *a, int n)
{
    p temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j].at > a[j + 1].at)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int f = 0, r = -1;
int tot_tt = 0, tot_wt = 0;
int main()
{
    int n, tq;
    printf("Enter the Number of Process and Time Quantum : ");
    scanf("%d", &n);
    scanf("%d", &tq);
    int completed = 0, curt = 0;
    p *a = (p *)calloc(n, sizeof(p));

    for (int i = 0; i < n; i++)
    {
        a[i].pid = i + 1;
        printf("AT of p%d : ", i + 1);
        scanf("%d", &a[i].at);
        printf("BT of p%d : ", i + 1);
        scanf("%d", &a[i].bt);
        a[i].completed = 0;
        a[i].visited = 0;
        a[i].btr = a[i].bt;
    }
    sort(a, n);
    q[++r] = 0;
    a[0].visited = 1;
    curt = a[0].at;
    while (completed != n)
    {
        int id = q[f++];
        if (a[id].btr > tq)
        {
            a[id].btr -= tq;
            curt += tq;
            printf("|P%d %d", a[id].pid, curt);
        }
        else
        {
            curt += a[id].btr;
            a[id].btr = 0;
            completed++;

            a[id].ct = curt;
            a[id].tat = a[id].ct - a[id].at;
            a[id].wt = a[id].tat - a[id].bt;
            tot_tt += a[id].tat;
            tot_wt += a[id].wt;

            printf("|P%d %d", a[id].pid, curt);
        }
        for (int i = 1; i < n; i++)
        {
            if (a[i].at <= curt && !a[i].visited)
            {
                q[++r] = i;
                a[i].visited = 1;
            }
        }
        if (a[id].btr > 0)
        {
            q[++r] = id;
        }
        while (f > r && completed < n) // if (f > r) -> q is empty
        {
            curt++;
            printf("|IDLE %d", curt);
            for (int i = 1; i < n; i++)
            {
                if (a[i].at <= curt && !a[i].visited)
                {
                    q[++r] = i;
                    a[i].visited = 1;
                }
            }
        }
    }
    printf("\nPID\tAT\tBT\tWT\tTT\tCT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", a[i].pid, a[i].at, a[i].bt, a[i].wt, a[i].tat, a[i].ct);
    }
    printf("\nThe Average Total Time is %f\n", ((float)tot_tt / n));
    printf("\nThe Average Waiting Time is %f\n", ((float)tot_wt / n));
}
