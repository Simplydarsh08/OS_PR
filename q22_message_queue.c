#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

struct message
{
    long type;
    char text[100];
};

int main(void)
{
    int id = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
    if (id < 0)
    {
        perror("msgget");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        msgctl(id, IPC_RMID, NULL);
        return 1;
    }

    if (pid == 0)
    {
        struct message msg;
        msg.type = 1;
        snprintf(msg.text, sizeof(msg.text), "%s", "Hello using Message Queue");

        if (msgsnd(id, &msg, sizeof(msg.text), 0) == -1)
        {
            perror("msgsnd");
            _exit(1);
        }
        _exit(0);
    }

    struct message msg;
    if (msgrcv(id, &msg, sizeof(msg.text), 1, 0) == -1)
    {
        perror("msgrcv");
        waitpid(pid, NULL, 0);
        msgctl(id, IPC_RMID, NULL);
        return 1;
    }

    printf("Received: %s\n", msg.text);

    int status;
    if (waitpid(pid, &status, 0) == -1 || !WIFEXITED(status) || WEXITSTATUS(status) != 0)
        fprintf(stderr, "Child process failed\n");

    if (msgctl(id, IPC_RMID, NULL) == -1)
    {
        perror("msgctl");
        return 1;
    }

    return 0;
}
