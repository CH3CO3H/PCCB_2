#include <stdio.h>
#include <stdlib.h>
#include "pot.h"

int main(void)
{
	pot x=malloc(sizeof(struct POT));
	unsigned int art[]={18, 18, 16, 9, 7, 1, 9, 3, 7, 5};
	int i;
	for (i=0;i<10;i++)
		x->a[i]=art[i];
	x->n=10;
	printf("%u\n", pot_dlt_max(x));
	printf("%u\n", x->n);
	for (i=0;i<10;i++)
		printf("%u  ", x->a[i]);
	return 0;
}
