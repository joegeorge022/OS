#include <stdio.h>

int main() {
    int n, i, time = 0, done;
    int bt[10], rem[10], wt[10];
    int quantum = 3;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    do {
        done = 1;
        for(i = 0; i < n; i++) {
            if(rem[i] > 0) {
                done = 0;

                if(rem[i] > quantum) {
                    time += quantum;
                    rem[i] -= quantum;
                } else {
                    time += rem[i];
                    wt[i] = time - bt[i];
                    rem[i] = 0;
                }
            }
        }
    } while(!done);

    float avg = 0;
    for(i = 0; i < n; i++) avg += wt[i];
    avg /= n;

    printf("\nAvg Waiting Time = %.2f\n", avg);
    return 0;
}
