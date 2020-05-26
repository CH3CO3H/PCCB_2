#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N_MAX 100

typedef struct cell cell;
struct cell {
	unsigned no;
	unsigned l;
	cell* nxt;
};
typedef cell* graph[N_MAX];
struct arcinfo {
	unsigned from;
	cell* arc;
};
typedef struct arcinfo arcinfo;
typedef arcinfo arcset[2*N_MAX];

graph g;
unsigned n, arc;
arcset arcs;

void graph_input(void);
void kruskal(graph ret);
void graph_print(graph g);
static cell* graph_addarc(graph g, unsigned u, unsigned v, unsigned l);
static inline void set_add(unsigned pos, cell* t, unsigned u);
void set_sort(unsigned s, unsigned e);
void merge(unsigned s, unsigned m, unsigned e);
void moveright(unsigned s, unsigned e);
bool graph_path(graph g, unsigned u, unsigned v);
void graph_dfs(graph g, bool mark[], unsigned u, unsigned v);

int main(void) {
	graph_input();
	graph ret;
	for (int i=0;i<n;i++) ret[i]=NULL;
	kruskal(ret);
	graph_print(ret);
	return 0;
}

void graph_input(void) {
	scanf("%u%u", &n, &arc);
	for (int i=0;i<arc;i++) {
		unsigned u, v, l;
		scanf("%u%u%u", &u, &v, &l);
		cell* t=graph_addarc(g, u, v, l);
		set_add(i, t, u);
		graph_addarc(g, v, u, l);
	}
}

static cell* graph_addarc(graph g, unsigned u, unsigned v, unsigned l) {
	cell** t=&g[u];
	while (*t) t=&(*t)->nxt;
	*t=malloc(sizeof(cell*));
	(*t)->no=v;
	(*t)->l=l;
	(*t)->nxt=NULL;
	return *t;
}

static inline void set_add(unsigned pos, cell* t, unsigned u) {
	arcs[pos].from=u;
	arcs[pos].arc=t;
}

void kruskal(graph ret) {
	set_sort(0, arc);
	for (int i=0;i<arc;i++) {
		unsigned u, v, l;
		u=arcs[i].from;
		v=arcs[i].arc->no;
		l=arcs[i].arc->l;
		if (!graph_path(ret, u, v)) {
			graph_addarc(ret, v, u, l);
			graph_addarc(ret, u, v, l);
		}
	}
}

void graph_print(graph g) {
	for (int i=0;i<n;i++) {
		printf("%d", i);
		for (cell* t=g[i];t;t=t->nxt) {
			printf("->%u(%u)", t->no, t->l);
		}
		putchar('\n');
	}
}

void set_sort(unsigned s, unsigned e) {
	if (s==e || e-s==1) return;
	unsigned m=(s+e)/2;
	set_sort(s, m);
	set_sort(m, e);
	merge(s, m, e);
}

void merge(unsigned s, unsigned m, unsigned e) {
	for (unsigned t1=s;t1<m&&m<e;) {
		if (arcs[m].arc->l<arcs[t1].arc->l) {
			moveright(t1, m);
			m++;
		}
		t1++;
	}
}

void moveright(unsigned t1, unsigned t2) {
	arcinfo tmp=arcs[t2];
	for (int i=0;i<t2-t1;i++) {
		arcs[t2-i]=arcs[t2-i-1];
	}
	arcs[t1]=tmp;
}

bool graph_path(graph g, unsigned u, unsigned v) {
	bool mark[n];
	for (int i=0;i<n;i++) {
		mark[i]=0;
	}
	graph_dfs(g, mark, u, v);
	if (mark[v]) return true;
	return false;
}

void graph_dfs(graph g, bool mark[], unsigned u, unsigned v) {
	if (mark[u]) return;
	mark[u]=true;
	for (cell* t=g[u];t;t=t->nxt) {
		graph_dfs(g, mark, t->no, v);
	}
}
