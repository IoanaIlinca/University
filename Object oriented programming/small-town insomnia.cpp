#include <stdio.h>
#include <cstring>

int main()
{
    bool ok = true;
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
