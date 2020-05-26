#include <stdio.h>

#define N_MAX 1000

int n;
int s;
int a[N_MAX];

int main(void) {
	scanf("%d%d", &n, &s);
	for (int i=0;i<n;i++) {
		scanf("%d", &a[i]);
	}
	int sum[N_MAX];
	sum[0]=a[0];
	for (int i=1;i<n;i++) {
		sum[i]=sum[i-1]+a[i];
	}
	if (sum[n-1]<s) {
		printf("0\n");
		return 0;
	}
	int res=
