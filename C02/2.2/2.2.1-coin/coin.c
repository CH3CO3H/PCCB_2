#include <stdio.h>

const int v[6]={1, 5, 10, 50, 100, 500};
int c[6];
int a;

static int min(int, int);

int main(void) {
	for (int i=0;i<6;i++) {
		scanf("%d", &c[i]);
	}
	scanf("%d", &a);
	int ans=0;
	for (int i=5; i; i--) {
		int t=min(a/v[i], c[i]);
		a-=t*v[i];
		ans+=t;
	}
	printf("%d\n", ans);
}

static inline int min(int x, int y) {
	return x>y?y:x;
}
