#include <stdio.h>

#define N 15
#define M 15

int n, m;
int w[N], v[N];
int dp[N][M];

void ipt()
{
	scanf("%d%d", &n, &m);
	int i;
	for (i=0;i<n;i++)
		scanf("%d%d", &w[i], &v[i]);
}

int max(int x, int y)
{
	return x>y?x:y;
}

int main(void)
{
	ipt();
	int i, j;
	for (j=0;j<m;j++)
		if (w[0]>j+1)
			dp[0][j]=0;
		else if (w[0]<j+1)
			dp[0][j]=v[0]+dp[0][j-w[0]];
		else
			dp[0][j]=v[0];
	for (i=1;i<n;i++)
		for (j=0;j<m;j++)
			if (w[i]>j+1)
				dp[i][j]=dp[i-1][j];
			else if (w[i]<j+1)
				dp[i][j]=max(dp[i-1][j], dp[i][j-w[i]]+v[i]);
			else
				dp[i][j]=max(v[i], dp[i-1][j]);
	//printf("%d\n", dp[n-1][m-1]);
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++)
			printf("%d ", dp[i][j]);
		putchar('\n');
	}

	return 0;
}
