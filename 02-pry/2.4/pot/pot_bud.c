#include "pot.h"

extern void pot_swp(pot, unsigned int, unsigned int);
extern short pot_lt(pot, unsigned int, unsigned int);

void pot_bud(pot x, unsigned int i)
{
		unsigned int c;
		c=2*i+1;
		if (c+1<x->n && pot_lt(x, c+1, c))
				c++;
		if (c<x->n && pot_lt(x, c, i)) {
				pot_swp(x, i, c);
				pot_bud(x, c);
		}
}

