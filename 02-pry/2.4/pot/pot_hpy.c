#include "pot.h"

extern void pot_bud(pot, unsigned int);

void pot_hpy(pot x)
{
		unsigned int i;
		for (i=x->n/2;i>0;i--)
				pot_bud(x, i);
}

