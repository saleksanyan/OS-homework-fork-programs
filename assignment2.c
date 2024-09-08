#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 == 0) {
        execl("/bin/ls", "ls", (char *)NULL);
        return 1;
    }

    pid2 = fork();
    if (pid2 == 0) {
        execl("/bin/date", "date", (char *)NULL);
        return 1;
    }

    wait(NULL);
    wait(NULL);

    printf("Parent process done\n");

    return 0;
}

