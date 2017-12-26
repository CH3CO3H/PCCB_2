#include <stdio.h>
#define N 15
#define M 15

int m, n;
char s[N], t[M];
int dp[N][M];

void ipt()
{
	int i;
	scanf("%d %d\n", &n, &m);
	for (i=0;i<n;i++)
		scanf("%c", &s[i]);
	getchar();
	for (i=0;i<m;i++)
		scanf("%c", &t[i]);
}

int max(int i, int j)
{
	return i>j?i:j;
}

int main(void)
{
	ipt();
	int i, j;
	if (s[0]==t[0])
		dp[0][0]=1;
	for (i=1;i<m;i++)
		if (s[0]==t[i])
			dp[0][i]=1;
		else
			dp[0][i]=dp[0][i-1];
	for (i=1;i<n;i++)
		if (s[i]==t[0])
			dp[i][0]=1;
		else
			dp[i][0]=dp[i-1][0];
	for (i=1;i<n;i++)
		for (j=1;j<m;j++)
			if (s[i]==t[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
	printf("%d\n", dp[n-1][m-1]);
	return 0;
}
