#include <stdio.h>

#define MAX_N 15

unsigned int n;
int a[MAX_N];
int k;

extern void input(unsigned int*, int[]);
static int dfs(int, int);

int main(void)
{
		input(&n, a);
		scanf("%d", &k);
		if (dfs(0,0)) puts("Yes");
		else puts("No");

		return 0;
}

int dfs(int i, int s)
{
		if (i==n) return s==k;
		if (dfs(i+1,s)) return 1;
		if (dfs(i+1,s+a[i])) return 1;
		return 0;
}
