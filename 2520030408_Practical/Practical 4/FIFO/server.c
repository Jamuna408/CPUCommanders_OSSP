#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    char msg[100];

    mkfifo("fifo", 0666);

    int fd = open("fifo", O_RDONLY);

    while (1)
    {
        read(fd, msg, sizeof(msg));
        printf("Client: %s\n", msg);
        printf("Server: Message received\n");
    }

    close(fd);
    return 0;
}
