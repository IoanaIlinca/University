#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int sum = 0;

int main()
{
        int i, n, vect[151];
        scanf("%d", &n);
        //vect = (int*)malloc(n*sizeof(int) + 1);
        for (i = 1; i <= n; ++i)
                vect[i] = i;

        if (fork() == 0)
        {
                for (i = 2; i <= n; i += 2)
                        sum += vect[i];
                exit(0);
        }
        wait(0);
        for (i = 1; i <= n; i += 2)
                sum += vect[i];
        printf("%d\n", sum);
        return 0;
}