#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "myfifo"

int main() {

    char buffer[100];

    // Create the FIFO
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
    }

    printf("FIFO Reader\n");
    printf("Waiting for message...\n");

    // Open FIFO for reading
    int fd = open(FIFO_NAME, O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Read message
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);

    if (bytesRead == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    buffer[bytesRead] = '\0';

    printf("Message received: %s", buffer);

    // Close FIFO
    close(fd);

    // Remove FIFO
    if (unlink(FIFO_NAME) == -1) {
        perror("unlink");
        return 1;
    }

    printf("FIFO closed and removed successfully.\n");

    return 0;
}
