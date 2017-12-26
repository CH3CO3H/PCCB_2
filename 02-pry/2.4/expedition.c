#include "pot.h"
#include <stdio.h>
#include <stdlib.h>

#define N 1<<10
#define VOL 1<<7

unsigned int gas_n;
unsigned int dis;
unsigned int itl;
unsigned int gdis[N];
unsigned int vol[VOL];

void ipt()
{
	scanf("%ud%ud%ud", &gas_n, &dis, &itl);
	int i;
	for (i=0;i<gas_n;i++)
		scanf("%ud", &gdis[i]);
	for (i=0;i<gas_n;i++)
		scanf("%ud", &vol[i]);
}

int main(void)
{
	ipt();
	unsigned int pos=0;
	int i, r=0;
	unsigned int d;
	pot gs=malloc(sizeof(struct POT));
	gs->n=0;
	for (i=0;i<gas_n;i++) {
		d=gdis[i]-pos;
		while (itl-d<0) {
			if (pot_is_ety(gs)) {
				puts("-1");
				return 0;
			}
			itl+=pot_dlt_max(gs);
			r++;
		}
		itl-=d;
		pos=gdis[i];
		pot_ist(gs, vol[i]);
	}
	printf("%d\n", r);
	return 0;
}
