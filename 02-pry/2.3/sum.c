#include <stdio.h>
#include <string.h>

#define N 15
#define K 32

extern void ipt(void);

int n, k;
int a[N], m[N];
int dp[K+1];

int main(void)
{
	ipt();
	memset(dp, -1, sizeof(dp));
	dp[0]=0;
	int i, j;
	for (i=0;i<n;i++)
		for (j=0;j<=k;j++)
			if (dp[j]>=0)
				dp[j]=m[i];
			else if (j<a[i] || dp[j-a[i]]<=0)
				dp[j]=-1;
			else
				dp[j]=dp[j-a[i]]-1;
	if (dp[k]>=0)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
