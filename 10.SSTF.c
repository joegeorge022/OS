#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head, total = 0;
    int req[20], visited[20] = {0};

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests: ");
    for(i = 0; i < n; i++) scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for(i = 0; i < n; i++) {
        int min = 9999, idx = -1;

        for(int j = 0; j < n; j++) {
            if(!visited[j]) {
                int dist = abs(head - req[j]);
                if(dist < min) {
                    min = dist;
                    idx = j;
                }
            }
        }

        visited[idx] = 1;
        total += abs(head - req[idx]);
        head = req[idx];
    }

    printf("Total Seek Time (SSTF) = %d\n", total);
    return 0;
}
