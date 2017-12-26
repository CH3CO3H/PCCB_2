#ifndef STK_H
#define STK_H

struct P {
		int x;
		int y;
};

#define stk_t struct P
#define STK_VOL 1024

struct STK {
		stk_t a[STK_VOL];
		unsigned int l;
};

#define stk(n)\
struct STK n;

extern void stk_psh(stk_t, struct STK);
extern stk_t stk_pop(struct STK);
extern int stk_ety(struct STK);

#endif
