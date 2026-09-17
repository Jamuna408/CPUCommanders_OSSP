#include<stdio.h>
#include<unistd.h>
#include<time.h>

int main()
{
int fd[2];
int data;
pipe(fd);
int pid;
pid=fork();
if(pid==0)
{
printf("Consumer %d\n",getpid());
close(fd[1]);
for(int i=0;i<5;i++)
{
read(fd[0],&data,sizeof(data));
printf("Consumed %d\n",data);
}
close(fd[0]);
}
else
{
printf("Producer %d\n",getpid());
close(fd[0]);
for(int i=1;i<=5;i++)
{
data=i*10;
write(fd[1],&data,sizeof(data));
printf("Produced %d\n",data);
}
close(fd[1]);
}
}
