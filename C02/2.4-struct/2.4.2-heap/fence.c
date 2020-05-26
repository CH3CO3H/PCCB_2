#include <stdio.h>

#define N_MAX 2000

typedef struct pot pot;
struct pot {
	unsigned a[N_MAX];
	unsigned size;
};

static unsigned pot_push(pot* p, unsigned x);
static unsigned pot_pop(pot* p);
static void pot_swap(pot* p, unsigned x, unsigned y);

unsigned n;
unsigned l[N_MAX];

int main(void) { 
	scanf("%u", &n);
	for (int i=0;i<n;i++) {
		scanf("%u", &l[i]);
	}

	pot p;
	p.size=0;
	for (int i=0;i<n;i++) {
		pot_push(&p, l[i]);
	}
	unsigned ret=0;
	while (p.size>1) {
		unsigned min1=pot_pop(&p);
		unsigned min2=pot_pop(&p);
		unsigned t=min1+min2;
		ret+=t;
		pot_push(&p, t);
	}
	printf("%u\n", ret);
	return 0;
}

static inline void pot_clear(pot* p) {
	p->size=0;
}

static unsigned pot_push(pot* p, unsigned x) {
	unsigned k=p->size;
	p->a[k]=x;
	p->size++;
	while (k>0) {
		unsigned f=(k-1)/2;
		if (p->a[f]<=p->a[k]) break;
		pot_swap(p, k, f);
		k=f;
	}
	return p->a[k];
}

static unsigned pot_pop(pot* p) {
	p->size--;
	if (p->size==0)
		return p->a[0];
	pot_swap(p, 0, p->size);
	unsigned k=0;
	while (2*k+1<p->size) {
		unsigned s=2*k+1;
		if (s+1<p->size && p->a[s+1]<p->a[s])
			s++;
		pot_swap(p, k, s);
		k=s;
	}
	return p->a[p->size];
}

static void pot_swap(pot* p, unsigned x, unsigned y) {
	unsigned t=p->a[x];
	p->a[x]=p->a[y];
	p->a[y]=t;
}
