#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal) {

    if (signal == SIGINT) {
        printf("\nSIGINT received: Ctrl+C pressed.\n");
    }

    else if (signal == SIGTERM) {
        printf("\nSIGTERM received: Termination requested.\n");
    }

    else if (signal == SIGUSR1) {
        printf("\nSIGUSR1 received: User-defined event occurred.\n");
    }
}

int main() {

    printf("Process PID = %d\n", getpid());

    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    signal(SIGUSR1, signal_handler);

    printf("Waiting for signals...\n");

    while (1) {
        pause();
    }

    return 0;
}
