#include <stdio.h>

int main() {
    int n, f, i, j, k, faults = 0;
    int frames[10];

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter reference string: ");
    for(i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) frames[i] = -1;

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            int idx = -1, farthest = i;

            for(j = 0; j < f; j++) {
                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k]) break;
                }

                if(k > farthest) {
                    farthest = k;
                    idx = j;
                }
            }

            if(idx == -1) {
                for(j = 0; j < f; j++) {
                    if(frames[j] == -1) {
                        idx = j;
                        break;
                    }
                }
            }

            frames[idx] = pages[i];
            faults++;
        }
    }

    printf("Page Faults (Optimal) = %d\n", faults);
    return 0;
}
