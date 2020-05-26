#include <stdio.h>

void extgcd(unsigned a, unsigned b, int* x, int* y);
void swap(int* x, int* y);

unsigned a, b;

int main(void) {
	scanf("%u%u", &a, &b);
	if (a<b) swap(&a, &b);
	int x, y;
	extgcd(a, b, &x, &y);
	printf("%d %d\n", x, y);
	return 0;
}

void extgcd(unsigned a, unsigned b, int* x, int* y) {
	if (!b) {
		*x=1;
		*y=0;
	} else {
		extgcd(b, a%b, x, y);
		int ox=*x;
		*x=*y;
		*y=ox-(a/b)*(*y);
	}
}

void swap(int* x, int* y) {
	int t=*x;
	*x=*y;
	*y=t;
}
