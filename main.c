#include <stdio.h>
#include <stdlib.h>

int main() {

    int choice;

    while (1) {

        printf("\n====================================\n");
        printf("          LINUX IPC PROJECT\n");
        printf("====================================\n");
        printf("1. Pipe Communication\n");
        printf("2. FIFO Communication\n");
        printf("3. Exit\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nStarting Pipe Communication...\n");
                system("./pipe/pipe_demo");
                break;

            case 2:
                printf("\n====================================\n");
                printf("          FIFO COMMUNICATION\n");
                printf("====================================\n");
                printf("Terminal 1:\n");
                printf("./fifo/fifo_reader\n");
                printf("\nTerminal 2:\n");
                printf("./fifo/fifo_writer\n");
                printf("====================================\n");
                break;

            case 3:
                printf("\nExiting project...\n");
                return 0;

            default:
                printf("\nInvalid choice. Please enter 1, 2 or 3.\n");
        }
    }

    return 0;
}
