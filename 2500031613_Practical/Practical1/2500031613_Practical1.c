#include<stdio.h>
#include<unistd.h>
int main()
{
int fd[2];
char buf[100];
printf("Enter a command:\n");
read(0,buf,100);
int pid;
pid=fork();
if(pid==0)
{
printf("\nChild PID:%d\n",getpid());
printf("Parent PID:%d\n",getppid());
execl("/bin/sh", "sh", "-c", buf, NULL);
printf("Execution failed\n");
}
else
{
printf("\nParent PID:%d\n",getpid());
printf("Child PID:%d\n",pid);
printf("\nChild Process completed.\n");
}
}
