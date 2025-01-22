#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[20];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();
    if (pid == 0) { // Child process
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
    } else { // Parent process
        write(pipefd[1], "Hello Child!", 13);
    }

    return 0;
}
