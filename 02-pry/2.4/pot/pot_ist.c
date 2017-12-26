#include "pot.h"

extern void pot_bup(pot, unsigned int);

void pot_ist(pot x, pot_t z)
{
	x->a[x->n++]=z;
	pot_bup(x, x->n-1);
}

