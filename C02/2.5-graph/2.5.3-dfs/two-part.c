#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N_MAX 1000

typedef struct node node;
struct node {
	unsigned no;
	node* arcto;
};
typedef struct graph_node graph_node;
struct graph_node {
	node* arcs;
	short color;
};

static void graph_addarc(unsigned x, unsigned y);
static void graph_color(unsigned no, short color);
static void graph_print(void);

graph_node graph[N_MAX];
unsigned n;
bool iscolor;

int main(void) {
	unsigned arc;
	scanf("%u%u", &n, &arc);
	for (int i=0;i<arc;i++) {
		unsigned x, y;
		scanf("%u%u", &x, &y);
		graph_addarc(x, y);
	}
	graph_print();

	iscolor=true;
	graph_color(0, 1);
	if (iscolor) printf("Yes\n");
	else printf("No\n");
	return 0;
}

static void graph_addarc(unsigned x, unsigned y) {
	node** t=&graph[x].arcs;
	while (*t) t=&(*t)->arcto;
	*t=malloc(sizeof(node));
	(*t)->arcto=NULL;
	(*t)->no=y;
}

static void graph_color(unsigned no, short color) {
	graph[no].color=color;
	printf("node %u, color %hd\n", no, color);
	node* t=graph[no].arcs;
	while (t) {
		if (graph[t->no].color==color) iscolor=false;
		if (!graph[t->no].color) graph_color(t->no, -color);
		t=t->arcto;
	}
}

static void graph_print(void) {
	for (int i=0;i<n;i++) {
		printf("node %d: ", i);
		node* t=graph[i].arcs;
		while (t) {
			printf("%u\t", t->no);
			t=t->arcto;
		}
		putchar('\n');
	}
}
