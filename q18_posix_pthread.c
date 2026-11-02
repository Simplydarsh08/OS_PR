#include <stdio.h>
#include <pthread.h>

void *display(void *arg)
{
    (void)arg;
    printf("Thread is running\n");
    return NULL;
}

int main(void)
{
    pthread_t thread;

    if (pthread_create(&thread, NULL, display, NULL) != 0)
    {
        fprintf(stderr, "Thread creation failed\n");
        return 1;
    }

    if (pthread_join(thread, NULL) != 0)
    {
        fprintf(stderr, "Thread join failed\n");
        return 1;
    }

    printf("Main thread completed\n");
    return 0;
}
