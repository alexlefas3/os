#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void signal_handler(int sig) {
    printf("Child received signal %d\n", sig);
}

int main() {
    pid_t pid = fork();

    if (pid == 0) { // Child
        signal(SIGUSR1, signal_handler);
        pause(); // Wait for signal
    } else { // Parent
        sleep(1);
        kill(pid, SIGUSR1);
    }

    return 0;
}
