#include <stdio.h>
#include <stdbool.h>

bool isprime(unsigned x);

unsigned x;

int main(void) {
	scanf("%u", &x);
	if (isprime(x)) puts("Yes");
	else puts("No");
	return 0;
}

bool isprime(unsigned x) {
	if (x==1) return false;
	for (int i=2;i*i<=x;i++) {
		if (!(x%i)) return false;
	}
	return true;
}
