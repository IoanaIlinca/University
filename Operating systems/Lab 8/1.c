#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

int n = 0, v = 0;
pthread_mutex_t mutex;

void* ThreadFunct(void* param)
{
        char string[256];
        strcpy(string, (char*)param);
        int i;
        for(i = 0; i < strlen(string); ++i)
        {
                pthread_mutex_lock(&mutex);
                if(strchr("aeiou", string[i]) != NULL)
                        v++;
                if(isdigit(string[i]))
                        n++;
                pthread_mutex_unlock(&mutex);
        }
        return NULL;
}

int main(int argc, char** argv)
{
        pthread_t threads[5];
        pthread_mutex_init(&mutex, NULL);
        int i;
        for (i = 0; i < 5; ++i)
        {
                pthread_create(&threads[i], NULL, ThreadFunct, (void*)argv[i + 1]);
        }
        for (i = 0; i < 5; ++i)
        {
                pthread_join(threads[i], NULL);
        }

        pthread_mutex_destroy(&mutex);
        printf("%d %d\n", v, n);
         return 0;
}