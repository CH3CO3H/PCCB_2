#include <stdio.h>

#define MAX_N 1000
#define MAX_M 1000

static inline int max(int, int);

int n, m;
char s[MAX_N], t[MAX_N];
int dp[MAX_N+1][MAX_N+1];

int main(void) {
	scanf("%d", &n);
	scanf("%d", &m);
	getchar();
	fgets(s, MAX_N, stdin);
	fgets(t, MAX_N, stdin);

	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (s[i]==t[j]) {
				dp[i+1][j+1]=dp[i][j]+1;
			} else {
				dp[i+1][j+1]=max(dp[i+1][j], dp[i][j+1]);
			}
		}
	}
	printf("%d\n", dp[m][m]);
	return 0;
}

static inline int max(int x, int y) {
	return x>y?x:y;
}
