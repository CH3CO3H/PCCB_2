#include <stdio.h>

int ind(int a[], int* x, int* y)
{
	scanf("%d %d", x, y);
	for (int i=0;i<*x;i++)
		scanf("%d", &a[i]);

	return 0;
}

