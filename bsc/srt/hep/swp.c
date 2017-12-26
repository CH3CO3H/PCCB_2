#include "srt_hep.h"

void swp(pot* p, unsigned int x, unsigned int y)
{
	if (x<n && y<n) {
		p->a[x]^=p->a[y];
		p->a[y]^=p->a[x];
		p->a[x]^=p->a[y];
	}
}
