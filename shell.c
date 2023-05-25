#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char *prompt = "#cisfun$ ";
    char command[100];

    while (1) {
        printf("%s", prompt);
        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("\n");
            break;
        }
        command[strcspn(command, "\n")] = '\0';

        if (access(command, X_OK) == 0) {
            pid_t pid = fork();

            if (pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {
                if (execve(command, NULL, NULL) == -1) {
                    perror("execve");
                    exit(EXIT_FAILURE);
                }
            } else {
                wait(NULL);
            }
        } else {
            printf("%s: No such file or directory\n", command);
        }
    }

    return 0;
}

