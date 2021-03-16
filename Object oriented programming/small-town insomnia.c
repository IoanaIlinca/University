#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    scanf("%s", a);
    while (strcmp(a, "exit") != 0)
    {
        printf("%s", a);
        printf("%c", '\n');
        scanf("%s", a);
    }


    return 0;
}
