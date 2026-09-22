#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int pid[3];
for(int i=0;i<3;i++)
{
pid[i]=fork();

if(pid[i]==0)
{
printf("Child %d pid=%d\n",i+1,getpid());
sleep(i+1);
exit(0);
}
}

wait(NULL);
printf("Parent:Any one child completes with wait()\n");

waitpid(pid[2],NULL,0);
printf("Parent: Child 3 completes with waitpid()\n");

wait(NULL);
printf("Parent:All the childs completed");
}
