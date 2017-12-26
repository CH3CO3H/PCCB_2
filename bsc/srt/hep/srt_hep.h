#ifndef SRT_HEP_H
#define SRT_HEP_H

#define ARR_POT_L 1<<8
#define LT(x, y) x<y

typedef unsigned int e_t[ARR_POT_L];
typedef struct {
	e_t a;
	unsigned int n;
} pot;

#endif
