#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

    int fd[2];
    char message[100];
    char buffer[100];

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid > 0) {

        // Parent process
        close(fd[0]);

        printf("\nParent Process (PID: %d)\n", getpid());
        printf("Parent: Sending message...\n");

        write(fd[1], message, strlen(message) + 1);

        printf("Parent: Message sent successfully.\n");

        close(fd[1]);

        wait(NULL);
    }

    else {

        // Child process
        close(fd[1]);

        read(fd[0], buffer, sizeof(buffer));

        printf("\nChild Process (PID: %d)\n", getpid());
        printf("Child: Message received: %s", buffer);

        close(fd[0]);
    }

    return 0;
}
