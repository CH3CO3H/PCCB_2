#ifndef POT_H
#define POT_H

#define POT_L 1<<7
typedef unsigned int pot_t;

struct POT {
	pot_t a[POT_L];
	unsigned int n;
};
typedef struct POT* pot;

extern pot_t pot_dlt_max(pot);
extern void pot_ist(pot, pot_t);
extern short pot_is_ety(pot);

#endif
