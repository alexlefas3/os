#include <stdio.h>
#include <unistd.h>

int main() {
    FILE *file = fopen("pid_output.txt", "w");

    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    pid_t pid = fork();

    fprintf(file, "Process PID: %d\n", getpid());
    fclose(file);

    return 0;
}
