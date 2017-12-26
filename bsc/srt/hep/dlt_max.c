#include "srt_hep.h"

extern void swp(pot*, unsigned int, unsigned int);
extern void bud(pot*, unsigned int);

void dlt_max(pot* p)
{
	swp(p, 0, p->n-1);
	p->n--;
	bud(p, 0);
}
