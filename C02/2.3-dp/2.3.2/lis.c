#include <stdio.h>

#define MAX_N 1000
#define INF 0xFF

int n;
int a[MAX_N];
int dp[MAX_N];

static inline int min(int, int);

int main(void) {
	scanf("%u", &n);
	for (int i=0;i<n;i++) {
		scanf("%u", &a[i]);
	}

	for (int i=0;i<n;i++) {
		dp[i]=INF;
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<=i;j++) {
			if (j==0 | dp[j-1]<a[i]) {
				dp[j]=min(dp[j], a[i]);
			}
		}
	}
	int res=0;
	for (;dp[res]<INF;res++);
	printf("%d\n", res);
	return 0;
}

static inline int min(int x, int y) {
	return x<y?x:y;
}
