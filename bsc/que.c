#include "que.h"

void que_psh(que_t t, struct QUE* q)
{
	q->a[q->e++]=t;
	if (q->e==QUE_VOL) q->e=0;
}

que_t que_pop(struct QUE* q)
{
		que_t t=q->a[q->s++];
		if (q->s==QUE_VOL) q->s=0;
		return t;
}

int que_ety(struct QUE* q)
{
		return q->s==q->e;
}
