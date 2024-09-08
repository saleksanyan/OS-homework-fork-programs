#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        execl("/bin/grep", "grep", "main", "test.txt", (char *)NULL);
        return 1;
    }

    wait(NULL);
    printf("Parent process completed\n");

    return 0;
}

