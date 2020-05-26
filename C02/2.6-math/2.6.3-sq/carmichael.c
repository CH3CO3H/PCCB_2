#include <stdio.h>
#include <stdbool.h>

unsigned n;

int main(void) {
	scanf("%u", &n);
	bool iscar=true;
	for (unsigned x=2;x<n;x++) {
		unsigned res=1;
		while (n>0) {
			if (n&1) {
				res=res*x%n;
			}
			x=x*x%n;
			n>>=1;
		}
		if (res!=x) {
			iscar=false;
		}
	}
	if (iscar) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
