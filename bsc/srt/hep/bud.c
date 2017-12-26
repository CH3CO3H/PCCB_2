#include "srt_hep.h"

extern void swp(pot*, unsigned int, unsigned int);

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
