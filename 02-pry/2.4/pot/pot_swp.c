#include "pot.h"

void pot_swp(pot x, unsigned int i, unsigned int j)
{
	if(i<x->n && j<x->n) {
		x->a[i]^=x->a[j];
		x->a[j]^=x->a[i];
		x->a[i]^=x->a[j];
	}
}

