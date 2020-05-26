#include <stdio.h>
#include <stdbool.h>

#define N_MAX 1000

unsigned prime[N_MAX];
bool isprime[N_MAX];
unsigned n;

int main(void) {
	scanf("%u", &n);
	for (int i=2;i<n;i++) {
		isprime[i]=true;
	}
	isprime[0]=false;
	isprime[1]=false;
	unsigned p=0;
	for (int i=2;i<=n;i++) {
		if (isprime[i]) {
			prime[p++]=i;
			for (int j=2*i;j<=n;j+=i) {
				isprime[j]=false;
			}
		}
	}
	for (int i=0;i<p;i++) {
		printf("%u\t", prime[i]);
	}
	putchar('\n');
	return 0;
}
