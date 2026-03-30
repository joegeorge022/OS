#include <stdio.h>

int main() {
    int n, f, i, j, faults = 0, time = 0;
    int frames[10], used[10];

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter reference string: ");
    for(i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frames[i] = -1;
        used[i] = 0;
    }

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                used[j] = ++time;
                break;
            }
        }

        if(!found) {
            int min = 9999, idx = 0;

            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    idx = j;
                    break;
                }
                if(used[j] < min) {
                    min = used[j];
                    idx = j;
                }
            }

            frames[idx] = pages[i];
            used[idx] = ++time;
            faults++;
        }
    }

    printf("Page Faults (LRU) = %d\n", faults);
    return 0;
}
