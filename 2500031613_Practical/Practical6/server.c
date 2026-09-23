#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define FIFO_NAME "myfifo"

int main() {

    char buffer[100];

    // Create FIFO
    mkfifo(FIFO_NAME, 0666);

    printf("Server started.\n");
    printf("Waiting for client messages...\n");

    while (1) {

        int fd = open(FIFO_NAME, O_RDONLY);

        if (fd == -1) {
            perror("open");
            return 1;
        }

        int n = read(fd, buffer, sizeof(buffer) - 1);

        if (n > 0) {

            buffer[n] = '\0';

            printf("Server received: %s\n", buffer);

            if (strcmp(buffer, "exit") == 0) {
                close(fd);
                break;
            }

            printf("Server processed the message.\n");
        }

        close(fd);
    }

    unlink(FIFO_NAME);

    printf("Server stopped.\n");

    return 0;
}
