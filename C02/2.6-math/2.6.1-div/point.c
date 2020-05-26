#include <stdio.h>

#define abs(x) ((x)<0?-(x):x)

unsigned gcd(unsigned x, unsigned y);

int x1, x2, y_1, y2;

int main(void) {
	scanf("%d%d%d%d", &x1, &y_1, &x2, &y2);
	printf("%u\n", gcd(abs(x2-x1), abs(y2-y_1))-1);
	return 0;
}

unsigned gcd(unsigned x, unsigned y) {
	if (!y) return x;
	return gcd(y, x%y);
}
