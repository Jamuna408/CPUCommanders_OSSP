#include <unistd.h>
#include <stdio.h>
int main()
{
int fd[2];
int pid;
if (pipe(fd) == -1)
{
printf("Pipe not created\n");
}
else
{
printf("Read end of the pipe is %d\n", fd[0]);
printf("Write end of the pipe is %d\n", fd[1]);
printf("Pipe successfully created\n");
}
pid = fork();
if (pid < 0)
{
printf("Fork not successful\n");
}
else if (pid == 0)
{
printf("Child process\n");
printf("The process ID is %d\n", getpid());
printf("The parent process ID is %d\n", getppid());
}
else
{
printf("Parent process\n");
printf("The process ID is %d\n", getpid());
printf("The parent process ID is %d\n", getppid());
}
}
