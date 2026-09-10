#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char msg[100];

    int fd = open("fifo", O_WRONLY);

    printf("Enter message: ");
    fgets(msg, sizeof(msg), stdin);

    write(fd, msg, sizeof(msg));

    close(fd);
    return 0;
}
