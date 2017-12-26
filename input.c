#include <stdio.h>

void input(unsigned int* x, int a[])
{
		scanf("%d", x);
		int i;
		for (i=0;i<*x;i++)
				scanf("%d", &a[i]);
}
