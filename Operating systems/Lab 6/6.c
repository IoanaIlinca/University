#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int Prime(int x)
{
        if (x < 2)
                return 0;
        if (x == 2)
                return 1;
        if (x % 2 == 0)
                return 0;

        for (int d = 3; d * d <= x; d += 2)
                if (x % d == 0)
                        return 0;
        return 1;
}



int main()                                                                             
{     
  int n, status, i;
  scanf("%d", &n);
  for(i = 0; i <= n; ++i)
        {                
                if (fork() == 0)
                {                                                                                          
			if (Prime(i))                                                                               
				exit(0);
                        exit(1);
		}              

	  	wait(&status);
	  	if(WEXITSTATUS(status) == 0)
                	printf("%d\n", i);    
  	}               
	return 0;           
}               