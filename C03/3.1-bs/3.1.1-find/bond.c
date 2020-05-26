#include <stdio.h>

#define N_MAX 1000

unsigned n;
unsigned a[N_MAX];
unsigned k;

unsigned bs(unsigned l, unsigned u);

int main(void) {
	scanf("%u", &n);
	for (size_t i=0;i<n;i++) {
		scanf("%u", &a[i]);
	}
	scanf("%u", &k);
	printf("%u\n", bs(0, n));
	return 0;
}

unsigned bs(unsigned l, unsigned u) {
	if (u-l==2) {
		if (a[l]>=k) {
			return l;
		} else {
			return l+1;
		}
	}
	unsigned m=(u+l)/2;
	if (a[m]>=k) {
		return bs(l, m+1);
	}
	return bs(m+1, u);
}
