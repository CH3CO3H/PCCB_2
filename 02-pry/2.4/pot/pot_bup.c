#include "pot.h"

extern void pot_swp(pot, unsigned int, unsigned int);
extern short pot_lt(pot, unsigned int, unsigned int);

void pot_bup(pot x, unsigned int i)
{
	unsigned int t;
	if (i&1)
		t=i/2;
	else
		t=i/2-1;
	if(i && pot_lt(x, i, t)) {
		pot_swp(x, i, t);
		pot_bup(x, t);
	}
}

