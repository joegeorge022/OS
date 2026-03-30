#include <stdio.h>

int main() {
    int n, i;
    int bt[10], at[10], wt[10], tat[10], ct[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("P%d Burst Arrival: ", i+1);
        scanf("%d %d", &bt[i], &at[i]);
    }

    ct[0] = at[0] + bt[0];
    for(i = 1; i < n; i++) {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    float avg = 0;
    for(i = 0; i < n; i++) avg += wt[i];
    avg /= n;

    printf("\nAvg Waiting Time = %.2f\n", avg);
    return 0;
}
