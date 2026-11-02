#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHM_SIZE 100

int main(void)
{
    int shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0)
    {
        perror("shmget");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        shmctl(shmid, IPC_RMID, NULL);
        return 1;
    }

    if (pid == 0)
    {
        char *shared_data = (char *)shmat(shmid, NULL, 0);
        if (shared_data == (char *)-1)
        {
            perror("shmat");
            _exit(1);
        }

        snprintf(shared_data, SHM_SIZE, "%s", "Hello using Shared Memory");
        shmdt(shared_data);
        _exit(0);
    }

    int status;
    if (waitpid(pid, &status, 0) == -1 || !WIFEXITED(status) || WEXITSTATUS(status) != 0)
    {
        fprintf(stderr, "Child process failed\n");
        shmctl(shmid, IPC_RMID, NULL);
        return 1;
    }

    char *shared_data = (char *)shmat(shmid, NULL, 0);
    if (shared_data == (char *)-1)
    {
        perror("shmat");
        shmctl(shmid, IPC_RMID, NULL);
        return 1;
    }

    printf("Data in shared memory: %s\n", shared_data);
    shmdt(shared_data);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
