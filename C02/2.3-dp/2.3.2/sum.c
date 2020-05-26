#include <stdio.h>
#include <string.h>

#define MAX_N 100
#define MAX_K 100000

unsigned n;
unsigned k;
unsigned a[MAX_N], m[MAX_N];
int dp[MAX_K+1];

int main(void) {
	scanf("%u", &n);
	for (int i=0;i<n;i++) {
		scanf("%u%u", &a[i], &m[i]);
	}
	scanf("%u", &k);
	memset(dp, -1, sizeof dp);
	dp[0]=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<=k;j++) {
//			printf("%d\t", dp[j]);
			if (dp[j]>=0) {
				dp[j]=m[i];
			} else if (j<a[i] || dp[j-a[i]]<=0) {
				dp[j]=-1;
			} else {
				dp[j]=dp[j-a[i]]-1;
			}
		}
//		printf("\n");
	}
	if (dp[k]>=0) printf("Yes\n");
	else printf("No\n");
}

