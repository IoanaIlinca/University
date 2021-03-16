#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
        char array[256];
        scanf("%[^\n]s", array);
        execlp("find", "find", ".", NULL);
}