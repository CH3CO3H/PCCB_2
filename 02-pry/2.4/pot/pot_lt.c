#include "pot.h"

short pot_lt(pot x, unsigned int m, unsigned int n)
{
	return x->a[m]>x->a[n];
}
