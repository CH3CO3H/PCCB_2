#include <stdio.h>
#include "../../bsc/srt/srt_arr.h"

#define N 15

unsigned int n;
unsigned int r;
unsigned int x[N];

void ipt()
{
	scanf("%d %d", &n, &r);
	unsigned int i;
	for (i=0;i<n;i++)
		scanf("%d", &x[i]);
}

int main(void)
{
	ipt();
	srt_arr(x, 0, n-1);
	int i=r=0;
	while (i<n) {
		int s=x[i++];
		while (i<n && x[i]<=s+r)
			i++;
		int p=x[i-1];
		while (i<n && x[i]<=p+r)
			i++;
		r++;
	}
	printf("%d\n", r);
}
