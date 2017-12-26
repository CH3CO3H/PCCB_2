#include <stdio.h>
#include "cp.h"
#define MAX_N 1<<9

int main()
{
	int l, n;
	int x[MAX_N];

	scanf("%d %d", &l, &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &x[i]);
	}

	int miT=0, maT=0;
	for (int i=0;i<n;i++) {
		miT=max(miT, min(x[i], l-x[i]));
	}

	for (int i=0;i<n;i++) {
		maT=max(maT, max(x[i], l-x[i]));
	}

	printf("%d %d\n", miT, maT);

	return 0;
}

