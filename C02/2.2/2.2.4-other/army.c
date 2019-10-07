#include <stdio.h>

#define N_MAX 1000

void sort(unsigned x[]);

unsigned n;
unsigned r;
unsigned x[N_MAX];

int main(void) {
	scanf("%u%u", &n, &r);
	for (int i=0;i<n;i++) {
		scanf("%u", &x[i]);
	}

	sort(x);
	int i=0;
	unsigned ans=0;
	while (i<n) {
		int s=x[i++];
		while (i<n && x[i]<=s+r) i++;
		int p=x[i-1];
		while (i<n && x[i]<=p+r) i++;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}

void sort(unsigned x[]) {}
