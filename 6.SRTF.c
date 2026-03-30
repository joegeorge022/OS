#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    int bt[10], at[10], rt[10], wt[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("P%d Burst Arrival: ", i+1);
        scanf("%d %d", &bt[i], &at[i]);
        rt[i] = bt[i];
    }

    while(completed < n) {
        int min = 9999, idx = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min) {
                min = rt[i];
                idx = i;
            }
        }

        if(idx != -1) {
            rt[idx]--;
            time++;

            if(rt[idx] == 0) {
                completed++;
                wt[idx] = time - bt[idx] - at[idx];
            }
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
