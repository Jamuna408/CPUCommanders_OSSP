#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig)
{
    printf("Signal %d received\n", sig);
}

int main()
{
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    signal(SIGUSR1, handler);

    printf("PID: %d\n", getpid());

    while(1)
        pause();

    return 0;
}
