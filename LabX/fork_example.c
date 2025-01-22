#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        if (fork() == 0) {
            printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        }
    }
    return 0;
}
