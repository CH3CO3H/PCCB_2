#include <stdio.h>

#define N 15
#define M 15

int n, m;
int w[N], v[N];
int dp[N+1][N*M+1];

void ipt()
{
	
}

int min()
{
	return a<b?a:b;
}

int main(void)
{
	int i;
	for (i=0;i<N*M+1;i++)
		dp[0][i]=INF;
	for (i=0;i<n;i++)
		for (j=0;j<=N*M;j++)
			if (j<v[i])
				dp[i+1][j]=dp[i][j];
			else
				dp[i+1][j]=min(dp[i][j], dp[i][j-v[i]]+w[i]);
	int r=0;
	for(i=0;i<=N*M;i++)
		if (dp[n][i]<=m)
			r=i;
	printf("%d\n", r);
	return 0;
}
