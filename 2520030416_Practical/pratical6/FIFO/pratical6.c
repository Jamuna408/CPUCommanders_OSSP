#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char msg[100];

    int fd = open("fifo", O_WRONLY);

    while(1)
    {
        printf("Enter message: ");
        fgets(msg, 100, stdin);

        write(fd, msg, sizeof(msg));
    }

    close(fd);
    return 0;
}
