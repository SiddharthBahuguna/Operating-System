#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int n, bt[30], wait_t[30], tat[30], awt = 0, atat = 0, i, j;
    printf("Enter total number of processes:");
    scanf("%d", &n);

    printf("\nEnter Burst Time taken:");
    for (i = 0; i < n; i++) {
        printf("P[%d]:", i + 1);
        scanf("%d", &bt[i]);
    }
    wait_t[0] = 0;
    for (i = 1; i < n; i++) {
        wait_t[i] = 0;
        for (j = 0; j < i; j++)
            wait_t[i] += bt[j];
    }
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wait_t[i];
        awt = awt + wait_t[i];
        atat = atat + tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t\t%d", i + 1, bt[i], wait_t[i], tat[i]);
    }
    awt = awt / n;
    atat = atat / n;

    printf("\nAverage Waiting Time:%d", awt);
    printf("\nAverage Turnaround Time:%d", atat);

    return 0;
}
