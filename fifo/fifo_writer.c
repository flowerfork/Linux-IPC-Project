#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define FIFO_NAME "myfifo"

int main() {

    char message[100];

    // Create FIFO if it does not already exist
    if (mkfifo(FIFO_NAME, 0666) == -1 && errno != EEXIST) {
        perror("mkfifo");
        return 1;
    }

    printf("FIFO Writer\n");
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    // Open FIFO for writing
    int fd = open(FIFO_NAME, O_WRONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Write message
    ssize_t bytesWritten = write(fd, message, strlen(message) + 1);

    if (bytesWritten == -1) {
        perror("write");
        close(fd);
        return 1;
    }

    printf("Message sent successfully.\n");

    // Close FIFO
    close(fd);

    return 0;
}
