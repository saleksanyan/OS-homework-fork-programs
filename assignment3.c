#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        execl("/bin/echo", "echo", "Hello from the child process", (char *)NULL);
        return 1;
    }

    wait(NULL);
    printf("Parent process done\n");

    return 0;
}

