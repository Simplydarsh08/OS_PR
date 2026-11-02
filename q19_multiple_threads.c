#include <stdio.h>
#include <pthread.h>

void *task(void *arg)
{
    (void)arg;
    printf("Thread ID = %lu\n", (unsigned long)pthread_self());
    return NULL;
}

int main(void)
{
    pthread_t t1, t2, t3;

    if (pthread_create(&t1, NULL, task, NULL) != 0 ||
        pthread_create(&t2, NULL, task, NULL) != 0 ||
        pthread_create(&t3, NULL, task, NULL) != 0)
    {
        fprintf(stderr, "Thread creation failed\n");
        return 1;
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("All threads completed\n");
    return 0;
}
