#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N_MAX 1000
#define INF 0xFFFF

typedef struct pot pot;
struct pot {
	unsigned a[N_MAX];
	unsigned s;
};

typedef struct cell cell;
struct cell {
	unsigned n;
	unsigned l;
	cell* nxt;
};

typedef struct graph_node graph_node;
struct graph_node {
	cell* arc;
	unsigned dist;
	unsigned dist2;
	unsigned top;
};
typedef graph_node graph[N_MAX];

graph g;
unsigned n;
pot p;

unsigned dijkstar(unsigned x, unsigned y);
static unsigned pot_pop(void);
static void inl(unsigned start);
static void pot_swap(unsigned x, unsigned y);
static unsigned min(unsigned x, unsigned y);
void graph_input(void);
static void graph_addarc(unsigned u, unsigned v, unsigned l);
static void pot_boubleup(unsigned x);

static unsigned pot_pop(void) {
	if (!p.s) {
		fprintf(stderr, "Pop empty pot");
		exit(1);
	}
	pot_swap(0, --p.s);
	for (unsigned k=0;;) {
		unsigned s=2*k+1;
		if (s+1<p.s && g[p.a[s+1]].dist<g[p.a[s]].dist)
			s++;
		if (s<p.s && g[p.a[s]].dist<g[p.a[k]].dist) {
			pot_swap(k, s);
			k=s;
		} else break;
	}
	return p.a[p.s];
}

unsigned dijkstra(unsigned a, unsigned b) {
	inl(a);
	while (p.s) {
		unsigned u=pot_pop();
		cell* ua=g[u].arc;
		for (;ua;ua=ua->nxt) {
			if (g[ua->n].dist > g[u].dist+ua->l) {
				g[ua->n].dist2=min(g[ua->n].dist2, g[ua->n].dist);
				g[ua->n].dist=g[u].dist+ua->l;
			} else {
				g[ua->n].dist2=min(g[ua->n].dist2, g[u].dist+ua->l);
			}
			pot_boubleup(g[ua->n].top);
		}
		putchar('\n');
		for (int i=0;i<n;i++) {
			printf("%u\t", g[i].dist);
		}
		for (int i=0;i<p.s;i++)
			printf("%u ", p.a[i]);
		putchar('\n');
	}
	return g[b].dist;
}

static void inl(unsigned x) {
	for (int i=0;i<n;i++) {
		g[i].dist=INF;
		g[i].dist2=INF;
		p.a[i]=i;
		g[i].top=i;
	}
	g[x].dist=0;
	if (x) pot_swap(0, x);
	p.s=n;
}

static void pot_swap(unsigned x, unsigned y) {
	p.a[x]^=p.a[y];
	p.a[y]^=p.a[x];
	p.a[x]^=p.a[y];
	g[p.a[x]].top=x;
	g[p.a[y]].top=y;
}

static inline unsigned min(unsigned x, unsigned y) {
	return x>y?y:x;
}

int main(void) {
	graph_input();
	printf("Shortest path between:\n");
	unsigned u, v;
	scanf("%u%u", &u, &v);
	if (u>=n || v>=n) return 1;
	printf("Result: %u\n", dijkstra(u, v));
	printf("Secondary: %u\n", g[v].dist2);
	return 0;
}

void graph_input(void) {
	unsigned a;
	scanf("%u", &n);
	scanf("%u", &a);
	unsigned u, v, l;
	for (int i=0;i<a;i++) {
		scanf("%u%u%u", &u, &v, &l);
		graph_addarc(u, v, l);
		graph_addarc(v, u, l);
	}
}

static void graph_addarc(unsigned u, unsigned v, unsigned l) {
	cell** t=&g[u].arc;
	while (*t) t=&(*t)->nxt;
	*t=malloc(sizeof(cell));
	(*t)->l=l;
	(*t)->n=v;
	(*t)->nxt=NULL;
}

static void pot_boubleup(unsigned x) {
	if (!x) return;
	unsigned f=(x-1)/2;
	if (g[p.a[f]].dist>g[p.a[x]].dist) {
		pot_swap(x, f);
		pot_boubleup(f);
	}
}
