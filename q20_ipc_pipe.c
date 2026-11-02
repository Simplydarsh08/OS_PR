#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    int fd[2];
    char message[] = "Hello from Parent";
    char buffer[100] = {0};

    if (pipe(fd) == -1)
    {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        close(fd[1]);
        ssize_t bytes_read = read(fd[0], buffer, sizeof(buffer) - 1);
        if (bytes_read < 0)
        {
            perror("read");
            close(fd[0]);
            return 1;
        }
        buffer[bytes_read] = '\0';
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    }
    else
    {
        close(fd[0]);
        if (write(fd[1], message, strlen(message) + 1) == -1)
            perror("write");
        close(fd[1]);
        waitpid(pid, NULL, 0);
    }

    return 0;
}
