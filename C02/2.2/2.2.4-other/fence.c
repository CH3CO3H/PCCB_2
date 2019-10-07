#include <stdio.h>

#define MAX_N 20000

void swap(int* a, int* b);

unsigned n, l[MAX_N];

int main(void) {
	scanf("%u", &n);
	for (int i=0;i<n;i++) {
		scanf("%u", &l[i]);
	}
	unsigned long ans=0;
	while (n>1) {
		int min1=0, min2=1;
		for (int i=2;i<n;i++) {
			if (l[i]<l[min1]) {
				min2=min1;
				min1=i;
			} else if (l[i]<l[min2]) {
				min2=i;
			}
		}
		int t=l[min1]+l[min2];
		ans+=t;
		if (min1==n-1) swap(&min1, &min2);
		l[min1]=t;
		if (min2!=n-1) {
			l[min2]=l[n-1];
		}
		n--;
	}
	printf("%lu\n", ans);
	return 0;
}

void swap(int* a, int* b) {
	int t=*a;
	*a=*b;
	*b=t;
}
