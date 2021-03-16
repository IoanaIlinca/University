#include <stdio.h>  

void hexafile(int);

int  main()
{
	int nr;
	int i=0;
	int maxim = -1000000;
	scanf("%d", &nr);
	if (nr > maxim)
		maxim = nr;
	while (nr!=0)
	{
		scanf("%d", &nr);
		if (nr > maxim)
			maxim = nr;
	}
	hexafile(maxim);
	return 0;
}