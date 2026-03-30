#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    } else if (pid == 0) {
        printf("24SJPCCSL407 ");             // Child process
    } else {
        wait(NULL);
        printf("Operating Systems Lab");     // Parent process
    }
    return 0;
}
