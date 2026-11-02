#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Child process is running\n");
    }
    else if (pid > 0)
    {
        wait(NULL);
        printf("Parent process resumes after child\n");
    }
    else
    {
        perror("fork");
        return 1;
    }

    return 0;
}
