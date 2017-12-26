#include "srt_hep.h"

void dlt_max(pot*);
void hpy(pot*);

void srt_hep(pot* p)
{
	unsigned k=p->n;
	hpy(p);
	while (p->n>1)
		dlt_max(p);
}
