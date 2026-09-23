#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

int main() {

    int pipefd[2];
    pid_t pid;
    char buffer[100];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid > 0) {

        // Parent - Producer
        close(pipefd[0]);

        printf("Producer: Sending data...\n");

        clock_t start = clock();

        for (int i = 1; i <= 5; i++) {

            sprintf(buffer, "Data %d", i);

            write(pipefd[1], buffer, strlen(buffer) + 1);

            printf("Producer sent: %s\n", buffer);

            sleep(1);
        }

        clock_t end = clock();

        close(pipefd[1]);

        printf("Producer finished.\n");

        double time_taken =
            (double)(end - start) / CLOCKS_PER_SEC;

        printf("Communication time: %.6f seconds\n",
               time_taken);

        wait(NULL);
    }

    else {

        // Child - Consumer
        close(pipefd[1]);

        printf("Consumer waiting for data...\n");

        while (read(pipefd[0], buffer, sizeof(buffer)) > 0) {

            printf("Consumer received: %s\n", buffer);
        }

        close(pipefd[0]);

        printf("Consumer finished.\n");
    }

    return 0;
}
