#include <stdio.h>
#include <string.h>

#define N 15
#define W 15

int dp[N][W];
int n, m;
int w[N], v[N];

void ipt()
{
	int i;
	scanf("%d\n", &n);
	for (i=0;i<n;i++)
		scanf("%d %d", &w[i], &v[i]);
	scanf("%d", &m);
}

int max(int i, int j)
{
	return i>j?i:j;
}

int rec(int i, int j)
{
	if (dp[i][j]>=0)
		return dp[i][j];
	int r;
	if (i==n)
		r=0;
	else if (j<w[i])
		r=rec(i+1, j);
	else
		r=max(rec(i+1, j), rec(i+1, j-w[i])+v[i]);
	return dp[i][j]=r;
}

int main(void)
{
	ipt();
	memset(dp, -1, sizeof(dp));
	printf("%d\n", rec(0, m));
	return 0;
}
