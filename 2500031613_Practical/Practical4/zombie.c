#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        printf("Child process running. PID = %d\n", getpid());
        printf("Child exiting now...\n");
        exit(0);
    }

    else {
        printf("Parent PID = %d\n", getpid());
        printf("Child PID = %d\n", pid);

        printf("Parent sleeping for 20 seconds...\n");
        printf("During this time, child becomes a zombie.\n");

        sleep(20);

        printf("Parent now calls wait().\n");
        wait(NULL);

        printf("Zombie removed.\n");
    }

    return 0;
}
