#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find(int frames[], int f, int page) {
    for(int i = 0; i < f; i++)
        if(frames[i] == page) return i;
    return -1;
}

// 🔹 FIFO
int fifo(int pages[], int n, int f) {
    int frames[10], front = 0, faults = 0;

    for(int i = 0; i < f; i++) frames[i] = -1;

    for(int i = 0; i < n; i++) {
        if(find(frames, f, pages[i]) == -1) {
            frames[front] = pages[i];
            front = (front + 1) % f;
            faults++;
        }
    }
    return faults;
}

// 🔹 LRU
int lru(int pages[], int n, int f) {
    int frames[10], time[10], faults = 0, t = 0;

    for(int i = 0; i < f; i++) frames[i] = -1;

    for(int i = 0; i < n; i++) {
        int pos = find(frames, f, pages[i]);

        if(pos != -1) {
            time[pos] = ++t;
        } else {
            int min = 9999, idx = 0;

            for(int j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    idx = j;
                    break;
                }
                if(time[j] < min) {
                    min = time[j];
                    idx = j;
                }
            }

            frames[idx] = pages[i];
            time[idx] = ++t;
            faults++;
        }
    }
    return faults;
}

// 🔹 Optimal
int optimal(int pages[], int n, int f) {
    int frames[10], faults = 0;

    for(int i = 0; i < f; i++) frames[i] = -1;

    for(int i = 0; i < n; i++) {
        if(find(frames, f, pages[i]) == -1) {
            int idx = -1, farthest = i;

            for(int j = 0; j < f; j++) {
                int k;
                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k]) break;
                }

                if(k > farthest) {
                    farthest = k;
                    idx = j;
                }
            }

            if(idx == -1) {
                for(int j = 0; j < f; j++) {
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
    return faults;
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <length> <frames>\n", argv[0]);
        return 0;
    }

    int n = atoi(argv[1]);
    int f = atoi(argv[2]);
    int pages[100];

    srand(time(0));

    printf("Reference String:\n");
    for(int i = 0; i < n; i++) {
        pages[i] = rand() % 10;
        printf("%d ", pages[i]);
    }

    printf("\n\nPage Faults:\n");
    printf("FIFO = %d\n", fifo(pages, n, f));
    printf("LRU = %d\n", lru(pages, n, f));
    printf("Optimal = %d\n", optimal(pages, n, f));

    return 0;
}
