#include <stdio.h>

#define MAX_N 100
#define MAX_V 100

unsigned int n;
unsigned int v[MAX_N];
unsigned long w[MAX_N];
unsigned long wl;
unsigned int dp[MAX_N+1][MAX_N*MAX_V+1];

static inline unsigned min(unsigned x, unsigned y);

int main(void) {
	scanf("%u", &n);
	for (int i=0;i<n;i++) {
		scanf("%lu%u", &w[i], &v[i]);
	}
	scanf("%lu", &wl);

	for (int i=0;i<MAX_N*MAX_V;i++) dp[0][i+1]=0xFFFFFFF;
	dp[0][0]=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<=MAX_N*MAX_V;j++) {
			if (j<v[i]) {
				dp[i+1][j]=dp[i][j];
			} else {
				dp[i+1][j]=min(dp[i][j], dp[i][j-v[i]]+w[i]);
			}
		}
	}
	unsigned int res=0;
	for (int i=0;i<=MAX_N*MAX_V;i++) if (dp[n][i]<=wl) res=i;
	printf("%d\n", res);

	return 0;
}

static inline unsigned int min(unsigned x, unsigned y) {
	return x>y?y:x;
}
