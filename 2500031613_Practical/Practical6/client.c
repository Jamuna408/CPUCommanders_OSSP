#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_NAME "myfifo"

int main() {

    char message[100];

    printf("Client started.\n");

    while (1) {

        printf("Enter message: ");
        fgets(message, sizeof(message), stdin);

        message[strcspn(message, "\n")] = '\0';

        int fd = open(FIFO_NAME, O_WRONLY);

        if (fd == -1) {
            perror("open");
            return 1;
        }

        write(fd, message, strlen(message) + 1);

        close(fd);

        if (strcmp(message, "exit") == 0)
            break;
    }

    printf("Client stopped.\n");

    return 0;
}
