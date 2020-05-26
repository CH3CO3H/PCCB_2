#include <stdio.h>
#include <stdbool.h>

#define L_MAX 1000
#define SQRT_B_MAX 1000

typedef unsigned long ulong;

static ulong max(ulong a, ulong b);

bool isprime[L_MAX];
bool isprime_small[SQRT_B_MAX];

ulong a, b;

int main(void) {
	scanf("%lu%lu", &a, &b);
	for (int i=2;i*i<b;i++) {
		isprime_small[i]=true;
	}
	for (int i=0;i<b-a;i++) {
		isprime[i]=true;
	}
	for (int i=2;i*i<b;i++) {
		if (isprime_small[i]) {
			for (int j=2*i;j*j<b;j+=i) {
				isprime_small[j]=false;
			}
			for (ulong j=max(2, (a+i-1)/i)*i;j<b;j+=i) {
				isprime[j-a]=false;
			}
		}
	}
	for (ulong i=0;i<b-a;i++) {
		if (isprime[i]) {
			printf("%lu\t", i+a);
		}
	}
	printf("\n");
	return 0;
}

static ulong max(ulong x, ulong y) {
	return x>y?x:y;
}
