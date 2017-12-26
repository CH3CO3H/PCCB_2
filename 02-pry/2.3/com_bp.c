#include <stdio.h>

#define N 15
#define M 15

int n, m;
int w[N], v[N];
int dp[N+1][M+1];

void ipt()
{
	int i;
	scanf("%d %d", &n, &m);
	for (i=0;i<n;i++)
		scanf("%d %d", &w[i], &v[i]);
}

int max(int x, int y)
{
	return x>y?x:y;
}

int main()
{
	ipt();
	int i, j;
	for (i=0;i<n;i++)
		for (j=0;j<=m;j++)
			if (j<w[i])
				dp[i+1][j]=dp[i][j];
			else
				dp[i+1][j]=max(dp[i][j], dp[i+1][j-w[i]]+v[i]);
	printf("%d\n", dp[n][m]);
	return 0;
}
