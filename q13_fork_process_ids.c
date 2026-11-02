#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Child Process\n");
        printf("Child PID = %ld\n", (long)getpid());
    }
    else
    {
        printf("Parent Process\n");
        printf("Parent PID = %ld\n", (long)getpid());
        if (waitpid(pid, NULL, 0) == -1)
        {
            perror("waitpid");
            return 1;
        }
    }

    return 0;
}
