#include <stdio.h>
#include <string.h>

#define MAX_N 100
#define MAX_W 10000

int n, w_top;
int w[MAX_N], v[MAX_N];
int dp[MAX_N+1][MAX_W+1];

static inline int max(int, int);
static int rec(int, int);

int main(void) {
	scanf("%d%d", &n, &w_top);
	for (int i=0;i<n;i++) {
		scanf("%d%d", &w[i], &v[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", rec(0, w_top));
	return 0;
}

static int rec(int i, int j) {
	if (dp[i][j]>=0) return dp[i][j];
	int res;
	if (i==n) res=0;
	else if (j<w[i]) res=rec(i+1, j);
	else res=max(rec(i+1, j), rec(i+1, j-w[i]+v[i]));
	return dp[i][j]=res;
}

static inline int max(int a, int b) {
	return a>b?a:b;
}
