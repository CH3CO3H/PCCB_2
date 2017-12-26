#include <stdio.h>

#define N 15

extern int n, k;
extern int a[N], m[N];

void ipt()
{
	int i;
	scanf("%d%d", &n, &k);
	for (i=0;i<n;i++)
		scanf("%d%d", &a[i], &m[i]);
}
