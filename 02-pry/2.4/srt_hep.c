#include "pot.h"

extern void pot_dlt_max(pot);
extern void pot_hpy(pot);

void srt_hep(pot x)
{
	hpy(x);
	while(x->n)
		pot_dlt_max(x);
}
