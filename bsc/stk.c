#include "stk.h"

void stk_psh(stk_t t, struct STK s)
{
		s.a[s.l++]=t;
}

stk_t stk_pop(struct STK s)
{
		return s.a[--s.l];
}

int stk_ety(struct STK s)
{
		return s.l==0;
}
