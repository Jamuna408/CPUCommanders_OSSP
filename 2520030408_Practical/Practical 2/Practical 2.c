#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
int fd1, fd2;
size_t n;
char buf[100];
fd1 = open("b1", O_RDONLY);
fd2 = open("c2", O_WRONLY | O_CREAT, 0644);
while((n = read(fd1, buf, sizeof(buf))) > 0)
{
write(fd2, buf, n);
}
close(fd1);
close(fd2);
printf("File copied successfully\n");
return 0;
}
