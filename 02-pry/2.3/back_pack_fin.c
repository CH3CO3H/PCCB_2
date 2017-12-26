#include <stdio.h>

#define N 15
#define M 15

unsigned int dp[N][M];
unsigned int n=4, m=5;
unsigned int w[N]={2,1,3,2}, v[N]={3,2,4,2};

unsigned int max(unsigned int i, unsigned int j)
{
	return i>j?i:j;
}

int main(void)
{
	int i, j;
	for (i=n-1,j=0;j<m;j++)
		if (w[i]>j+1)
			dp[i][j]=0;
		else
			dp[i][j]=v[i];
	for (i=n-2;i>=0;i--)
		for (j=0;j<m;j++)
			if (w[i]>j+1)
				dp[i][j]=dp[i+1][j];
			else if (j+1==w[i])
				dp[i][j]=max(dp[i+1][j], v[i]);
			else
				dp[i][j]=max(dp[i+1][j], dp[i+1][j-w[i]]+v[i]);
	printf("%d\n", dp[0][4]);
	return 0;
}
