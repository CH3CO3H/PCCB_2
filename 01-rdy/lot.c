#include <stdio.h>

#define MAX_N 50

int main()
{
	int m, n, k[MAX_N];

	scanf("%d %d", &n, &m);
	for (int i=0;i<n;i++) {
		scanf("%d", &k[i]);
	}

	int l=0;

	for (int a=0;a<n;a++) {
		for (int b=0;b<n;b++) {
			for (int c=0;c<n;c++) {
				for (int d=0;d<n;d++) {
					if (k[a]+k[b]+k[c]+k[d]==m) {
						l=1;
						break;
					}
				}
			}
		}
	}

	if (l) puts("Yes");
	else puts("No");

	return 0;
}

