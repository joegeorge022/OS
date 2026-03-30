#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    int bt[10], at[10], pr[10], wt[10], done[10] = {0};

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("P%d Burst Arrival Priority: ", i+1);
        scanf("%d %d %d", &bt[i], &at[i], &pr[i]);
    }

    while(completed < n) {
        int maxp = -1, idx = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && !done[i] && pr[i] > maxp) {
                maxp = pr[i];
                idx = i;
            }
        }

        if(idx != -1) {
            wt[idx] = time - at[idx];
            time += bt[idx];
            done[idx] = 1;
            completed++;
        } else {
            time++;
        }
    }

    float avg = 0;
    for(i = 0; i < n; i++) avg += wt[i];
    avg /= n;

    printf("\nAvg Waiting Time = %.2f\n", avg);
    return 0;
}
