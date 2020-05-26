#include <stdio.h>
#include <stdbool.h>

#define N_MAX 10000

typedef struct queue queue;
struct queue {
	unsigned a[N_MAX];
	unsigned p;
};

static inline void queue_clear(queue* q);
static inline bool queue_isempty(queue* q);
static void queue_push(queue* q, unsigned x);
static unsigned queue_pop(queue* q);
static void queue_swap(queue* q, unsigned m, unsigned n);

unsigned n, l, p;
unsigned a[N_MAX], b[N_MAX];

int main(void) {
	scanf("%u%u%u", &n, &l, &p);
	for (int i=0;i<n;i++) {
		scanf("%u", &a[i]);
	}
	for (int i=0;i<n;i++) {
		scanf("%u", &b[i]);
	}
	
	unsigned cnt=0, pos=p, tank=0;
	unsigned nxt=0;
	queue q;
	queue_clear(&q);
	while (pos<l) {
		int i;
		for (i=0;a[nxt+i]<=pos;i++) {
			queue_push(&q, b[nxt+i]);
		}
		nxt+=i;
		if (queue_isempty(&q)) {
			printf("-1\n");
			return 0;
		}
		tank=queue_pop(&q);
		cnt++;
		pos+=tank;
	}
	printf("%u\n", cnt);
	return 0;
}

static inline void queue_clear(queue* q) {
	q->p=0;
}

static inline bool queue_isempty(queue* q) {
	return !q->p;
}

static void queue_swap(queue* q, unsigned m, unsigned n) {
	unsigned t=q->a[m];
	q->a[m]=q->a[n];
	q->a[n]=t;
}

static void queue_push(queue* q, unsigned x) {
	q->a[q->p]=x;
	unsigned k=q->p;
	unsigned f=(k-1)/2;
	while (k && q->a[k]>q->a[f]) {
		queue_swap(q, k, f);
		k=f;
	}
	q->p++;
}

static inline unsigned queue_pop(queue* q) {
	queue_swap(q, 0, --q->p);
	unsigned k=0;
	while (2*k+1<q->p) {
		unsigned s=2*k+1;
		if (2*k+2<q->p && q->a[2*k+2]>q->a[s])
			s=2*k+2;
		if (q->a[s]>q->a[k])
			queue_swap(q, k, s);
		else
			break;
		k=s;
	}
	return q->a[q->p];
}
