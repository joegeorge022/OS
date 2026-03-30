#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, total = 0, max = 199;
    int req[20];

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests: ");
    for(i = 0; i < n; i++) scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // sort
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(req[i] > req[j]) {
                int t = req[i];
                req[i] = req[j];
                req[j] = t;
            }

    int idx;
    for(i = 0; i < n; i++) {
        if(req[i] >= head) {
            idx = i;
            break;
        }
    }

    // move right
    for(i = idx; i < n; i++) {
        total += abs(head - req[i]);
        head = req[i];
    }

    // go to end
    total += abs(head - max);
    head = 0;

    // from start
    for(i = 0; i < idx; i++) {
        total += abs(head - req[i]);
        head = req[i];
    }

    printf("Total Seek Time (CSCAN) = %d\n", total);
    return 0;
}
