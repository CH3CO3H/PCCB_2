#include <stdio.h>

#define MAX_N 100

int max(int, int, int);

int main()
{
	int n, a[MAX_N];
	int r=0;

	scanf("%d", &n);
	for (int i=0;i<n;i++)
		scanf("%d", &a[i]);

	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			for (int k=j+1;k<n;k++) {
				int len=a[i]+a[j]+a[k];
				int mx=max(a[i], a[j], a[k]);
				int rst=len-mx;

				if (mx<rst)
					r=len>r?len:r;
			}
		}
	}
	printf("%d\n", r);

	return 0;
}

int max(int a, int b, int c)
{
	int t=a>b?a:b;
	return t>c?t:c;
}

