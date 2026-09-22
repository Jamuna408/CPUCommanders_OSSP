#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2, child3;
    int status;

    child1 = fork();

    if (child1 == 0) {
        printf("Child 1: PID = %d\n", getpid());
        sleep(2);
        printf("Child 1 finished\n");
        exit(10);
    }

    child2 = fork();

    if (child2 == 0) {
        printf("Child 2: PID = %d\n", getpid());
        sleep(4);
        printf("Child 2 finished\n");
        exit(20);
    }

    child3 = fork();

    if (child3 == 0) {
        printf("Child 3: PID = %d\n", getpid());
        sleep(1);
        printf("Child 3 finished\n");
        exit(30);
    }

    printf("Parent: Waiting for Child 1 using waitpid()\n");

    waitpid(child1, &status, 0);

    if (WIFEXITED(status))
        printf("Child 1 exit status = %d\n", WEXITSTATUS(status));

    printf("Parent: Waiting for any remaining child using wait()\n");

    wait(&status);

    if (WIFEXITED(status))
        printf("A child finished with status = %d\n", WEXITSTATUS(status));

    wait(&status);

    if (WIFEXITED(status))
        printf("Last child finished with status = %d\n", WEXITSTATUS(status));

    printf("Parent process finished.\n");

    return 0;
}
