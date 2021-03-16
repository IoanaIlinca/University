#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>

int var = 0;
pthread_mutex_t mutex;

void* funct(void* param)
{
        int n = *((int*)param);

        printf("thread %ld, number %d\n", pthread_self(), n);

        if(n % 5 == 0 || n % 2 == 0)
        {
                pthread_mutex_lock(&mutex);
                var++;
                printf("n is %d and var is %d\n", n, var);
                //var++;
                pthread_mutex_unlock(&mutex);
        }
        return NULL;
}

int main(int argc, char **argv)
{
        pthread_t threads[argc];
        pthread_mutex_init(&mutex, NULL);

        int i, arr[argc];
        for (i = 1; i < argc; i++)
        {
                arr[i] = atoi(argv[i]);
                //printf("%s\n", argv[i]);

        }

        printf("%d\n", argc);
        for (i = 1; i < argc; i++)
        {
                        pthread_create(&threads[i], NULL, funct, (void*)&arr[i]);
        }
        for (i = 1; i < argc; i++)
        {
                pthread_join(threads[i], NULL);
        }
        pthread_mutex_destroy(&mutex);
        printf("%d\n", var);
        return 0;
}