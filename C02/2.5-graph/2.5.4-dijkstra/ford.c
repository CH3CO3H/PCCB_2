#include <stdio.h>
#include <stdbool.h>

#define N_MAX 100
#define E_MAX 200
#define INF 0XFF

struct edge {
	unsigned from;
	unsigned to;
	int l;
};
typedef struct edge edges[E_MAX];

void graph_input(void);

edges e;
int d[N_MAX];
unsigned n;
unsigned arc;

int main(void) {
	graph_input();
	for (int i=0;i<arc;i++) {
		d[i]=INF;
	}
	d[0]=0;
	for (;;) {
		bool isupdate=false;
		for (int i=0;i<arc;i++) {
			struct edge te=e[i];
			if (d[te.from]<INF && d[te.to]>d[te.from]+te.l) {
				d[te.to]=d[te.from]+te.l;
				isupdate=true;
			}
		}
		if (!isupdate) break;
	}
	for (int i=0;i<n;i++) {
		printf("%d\t", d[i]);
	}
	putchar('\n');
	return 0;
}

void graph_input(void) {
	scanf("%u%u", &n, &arc);
	for (int i=0;i<arc;i++) {
		scanf("%u%u%d", &e[i].from, &e[i].to, &e[i].l);
	}
}
