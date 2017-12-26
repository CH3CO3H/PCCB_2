#include "pot.h"

extern void pot_bud(pot, unsigned int);
extern void pot_swp(pot, unsigned int, unsigned int);

pot_t pot_dlt_max(pot x)
{
	pot_swp(x, 0, x->n-1);
	x->n--;
	pot_bud(x, 0);
	return x->a[x->n];
}

