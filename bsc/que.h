#ifndef QUE_H
#define QUE_H

/*define que_t here*/
struct P {
	unsigned int x;
	unsigned int y;
};
/*end def*/

#define que_t struct P
#define QUE_VOL 1<<10

struct QUE {
	que_t a[QUE_VOL];
	unsigned int s;
	unsigned int e;
};

#define que(n)\
struct QUE n={};

extern int que_ety(struct QUE*);
extern void que_psh(que_t, struct QUE*);
extern que_t que_pop(struct QUE*);

#endif
