#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig)
{
    printf("Signal received: %d\n", sig);
}

int main()
{
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    signal(SIGUSR1, handler);

    printf("PID: %d\n", getpid());

    while(1)
        sleep(2);

    return 0;
}
