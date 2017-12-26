#include <stdio.h>

#define N 15

int n, l[N];

void swp(int* x, int* y)
{
	*x^=*y;
	*y^=*x;
	*x^=*y;
}

int main(void)
{
	scanf("%d\n", &n);
	unsigned int i;
	for(i=0;i<n;i++)
		scanf("%d", &l[i]);
	int r=0;
	while (n>1) {
		int m1=0, m2=1;
		if (l[m1]>l[m2])
			swp(&m1, &m2);
		for (i=2;i<n;i++)
			if (l[i]<l[m1]) {
				m2=m1;
				m1=i;
			} else if (l[i]<l[m2])
				m2=i;
		int t=l[m1]+l[m2];
		r+=t;
		if (m1==n-1)
			swp(&m1, &m2);
		l[m1]=t;
		l[m2]=l[n-1];
		n--;
	}
	printf("%d\n", r);
	return 0;
}
