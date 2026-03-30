#include <stdio.h>

int main() {
    int n, i, time = 0, quantum = 3;
    int bt[10], at[10], pr[10], wt[10], tat[10], ct[10];
    int rem_bt[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("P%d Burst Arrival Priority: ", i+1);
        scanf("%d %d %d", &bt[i], &at[i], &pr[i]);
        rem_bt[i] = bt[i];
    }

    // 🔹 FCFS
    time = 0;
    for(i = 0; i < n; i++) {
        if(time < at[i]) time = at[i];
        ct[i] = time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        time = ct[i];
    }

    float avg_wt_fcfs = 0;
    for(i = 0; i < n; i++) avg_wt_fcfs += wt[i];
    avg_wt_fcfs /= n;

    // 🔹 Round Robin
    int done, t = 0;
    for(i = 0; i < n; i++) rem_bt[i] = bt[i];

    do {
        done = 1;
        for(i = 0; i < n; i++) {
            if(rem_bt[i] > 0) {
                done = 0;
                if(rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
    } while(!done);

    float avg_wt_rr = 0;
    for(i = 0; i < n; i++) avg_wt_rr += wt[i];
    avg_wt_rr /= n;

    // 🔹 Priority (Non-preemptive, higher number = higher priority)
    int completed[10] = {0}, count = 0;
    time = 0;

    while(count < n) {
        int maxp = -1, idx = -1;
        for(i = 0; i < n; i++) {
            if(at[i] <= time && !completed[i]) {
                if(pr[i] > maxp) {
                    maxp = pr[i];
                    idx = i;
                }
            }
        }
        if(idx != -1) {
            ct[idx] = time + bt[idx];
            wt[idx] = time - at[idx];
            time = ct[idx];
            completed[idx] = 1;
            count++;
        } else {
            time++;
        }
    }

    float avg_wt_pr = 0;
    for(i = 0; i < n; i++) avg_wt_pr += wt[i];
    avg_wt_pr /= n;

    // 🔹 Result
    printf("\nAverage Waiting Time:\n");
    printf("FCFS = %.2f\n", avg_wt_fcfs);
    printf("RR = %.2f\n", avg_wt_rr);
    printf("Priority = %.2f\n", avg_wt_pr);

    return 0;
}
