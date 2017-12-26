#include "srt_arr.h"

static void mrg(e_t[], unsigned int, unsigned int, unsigned int);

void srt_arr(e_t a[], unsigned int s, unsigned int e)
{
	if (e-s>1) {
		unsigned int m=(e+s)/2;
		srt_arr(a, s, m);
		srt_arr(a, m+1, e);
		mrg(a, s, m, e);
	} else {
		mrg(a, s, s, e);
	}
}

void mrg(e_t a[], unsigned int s, unsigned int m, unsigned int e)
{
	if (s>m||m+1>e)
		return;
	if (E_V(s)<=E_V(m+1))
		mrg(a, s+1, m, e);
	else {
		e_t t=a[m+1];
		unsigned int i;
		for (i=0;i<m-s+1;i++)
			a[m+1-i]=a[m-i];
		a[s]=t;
		mrg(a, s+1, m+1, e);
	}
}

