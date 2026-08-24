#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;

    printf("Before Fork\n");
    printf("PID  : %d\n", getpid());
    printf("PPID : %d\n", getppid());

    pid = fork();

    if(pid == 0)
    {
        printf("\nChild Process\n");
        printf("PID  : %d\n", getpid());
        printf("PPID : %d\n", getppid());
    }
    else
    {
        printf("\nParent Process\n");
        printf("PID       : %d\n", getpid());
        printf("Child PID : %d\n", pid);
    }

    return 0;
}
