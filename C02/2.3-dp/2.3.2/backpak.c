#include <stdio.h>

#define MAX_N 100
#define MAX_W 10000

static inline int max(int, int);

int n;
int w[MAX_N];
int v[MAX_N];
int wl;
int dp[MAX_N+1][MAX_W+1];

int main(void) {
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d%d", &w[i], &v[i]);
	}
	scanf("%d", &wl);

	for (int i=0;i<n;i++) {
		for (int j=0;j<=wl;j++) {
			if (j<w[i]) {
				dp[i+1][j]=dp[i][j];
			} else {
				dp[i+1][j]=max(dp[i][j], dp[i+1][j-w[i]]+v[i]);
			}
		}
	}
	printf("%d\n", dp[n][wl]);

	return 0;
}

static inline int max(int x, int y) {
	return x>y?x:y;
}
