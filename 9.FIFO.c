#include <stdio.h>

int main() {
    int n, f, i, j, page, faults = 0, front = 0;
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
            frames[front] = pages[i];
            front = (front + 1) % f;
            faults++;
        }
    }

    printf("Page Faults (FIFO) = %d\n", faults);
    return 0;
}
