#include <stdio.h>

int readcount = 0;
int writer_waiting = 0;
int writing = 0;

// Reader
void reader(int id) {
    if (writer_waiting || writing) {
        printf("Reader %d is waiting (writer priority)\n", id);
        return;
    }

    readcount++;
    printf("Reader %d is reading\n", id);

    readcount--;
}

// Writer
void writer(int id) {
    writer_waiting = 1;

    if (readcount > 0 || writing) {
        printf("Writer %d is waiting\n", id);
    }

    writer_waiting = 0;
    writing = 1;

    printf("Writer %d is writing\n", id);

    writing = 0;
}

int main() {
    // Simulation order
    reader(1);
    reader(2);
    writer(1);
    reader(3);
    writer(2);

    return 0;
}
