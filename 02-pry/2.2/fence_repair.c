#include <stdio.h>
#define ARR_POT_L 1<<8
#define LT(x, y) x>y

typedef unsigned int e_t[ARR_POT_L];
typedef struct {
	e_t a;
	unsigned int n;
} pot;

void swp(pot* p, unsigned int x, unsigned int y)
{
	if (x<p->n && y<p->n) {
		p->a[x]^=p->a[y];
		p->a[y]^=p->a[x];
		p->a[x]^=p->a[y];
	}
}

void bud(pot* p, unsigned int m)
{
	unsigned int c=2*m+1;
	if (c<p->n-1 && LT(p->a[c], p->a[c+1]))
		c++;
	if (c<p->n && LT(p->a[m], p->a[c])) {
		swp(p, m, c);
		bud(p, c);
	}
}

void dlt_max(pot* p)
{
	swp(p, 0, p->n-1);
	p->n--;
	bud(p, 0);
}

void hpy(pot* p)
{
	unsigned int i;
	for (i=p->n/2-1;i>=0;i--)
		bud(p, i);
}

#define N 15

int n, l[N];

void ipt()
{
	scanf("%d\n", &n);
	int i;
	for (i=0;i<n;i++)
		scanf("%d", &l[i]);
}

void srt2(pot* p)
{
	dlt_max(p);
	dlt_max(p);
}

int fee(pot* p)
{
	if (p->n==2)
		return p->a[0]+p->a[1];
	srt2(p);
	return p->a[p->n] + p->a[p->n+1] + fee(p);
}

int main(void)
{
	ipt();
	pot x;
	x.n=n;
	int i;
	for (i=0;i<n;i++)
		x.a[i]=l[i];
	hpy(&x);
	printf("%d\n", fee(&x));
	return 0;
}
