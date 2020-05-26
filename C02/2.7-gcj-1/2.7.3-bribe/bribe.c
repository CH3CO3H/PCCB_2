#include <stdio.h>

#define P_MAX 10000
#define Q_MAX 100
#define INF P_MAX

#define min(x, y) ((x)>(y)?(y):(x))

unsigned bribe(unsigned x, unsigned y);

unsigned p, q, a[Q_MAX+2];
unsigned dp[Q_MAX+1][Q_MAX+2];

int main(void) {
	scanf("%u%u", &p, &q);
	for (int i=0;i<q;i++) {
		scanf("%u", &a[i+1]);
	}
	a[0]=0;
	a[q+1]=p+1;

	for (int i=0;i<=q;i++) {
		for (int j=i+1;j<q+2;j++) {
			dp[i][j]=INF;
		}
	}
	for (int i=0;i<=q;i++) {
		dp[i][i+1]=0;
	}

	printf("%u\n", bribe(0, q+1));
	return 0;
}

unsigned bribe (unsigned x, unsigned y) {
	if (dp[x][y]<INF) return dp[x][y];
	unsigned ret=INF;
	for (int k=x+1;k<y;k++) {
		unsigned t=a[y]-a[x]-2+bribe(x, k)+bribe(k, y);
		ret=min(ret, t);
	}
	dp[x][y]=ret;
	return ret;
}
