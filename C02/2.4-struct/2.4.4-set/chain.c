#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define K_MAX 100000

typedef struct node node;
struct node {
	unsigned h;
	unsigned no;
	node* f;
};

node** set_init(size_t n);
bool set_same(node** set, unsigned x, unsigned y);
void set_unite(node** set, unsigned x, unsigned y);
static node* set_find_root(node** set, unsigned x);

unsigned n;
unsigned k;
char t[K_MAX];
unsigned x[K_MAX], y[K_MAX];

int main(void) {
	scanf("%u%u", &n, &k);
	for (int i=0;i<k;i++) {
		scanf("%hhu%u%u", &t[i], &x[i], &y[i]);
	}

	node** sets=set_init(3*n);
	unsigned ret=0;
	for (int i=0;i<k;i++) {
		char type=t[i];
		unsigned xi=x[i]-1;
		unsigned yi=y[i]-1;
		if (xi>=n || yi>=n) {
			ret++;
			continue;
		}
		if (type==1) {
			if (set_same(sets, xi, yi+n) || set_same(sets, xi, yi+2*n)) {
				ret++;
			} else {
				set_unite(sets, xi, yi);
				set_unite(sets, xi+n, yi+n);
				set_unite(sets, xi+2*n, yi+2*n);
			}
		} else {
			if (set_same(sets, xi, yi) || set_same(sets, xi, yi+2*n)) {
				ret++;
			} else {
				set_unite(sets, xi, yi+n);
				set_unite(sets, xi+n, yi+2*n);
				set_unite(sets, xi+2*n, yi);
			}
		}
	}
	printf("%u\n", ret);
	return 0;
}

node** set_init(size_t n) {
	node** ret=calloc(n, sizeof(node**));
	for (int i=0;i<n;i++) {
		ret[i]=malloc(sizeof(node));
		ret[i]->f=NULL;
		ret[i]->h=1;
		ret[i]->no=i;
	}
	return ret;
}

bool set_same(node** set, unsigned x, unsigned y) {
	return set_find_root(set, x)==set_find_root(set, y);
}

static node* set_find_root(node** set, unsigned x) {
	node* ret=set[x];
	while (ret->f) ret=ret->f;
	return ret;
}

void set_unite(node** set, unsigned x, unsigned y) {
	node* xr=set_find_root(set, x);
	node* yr=set_find_root(set, y);
	if (xr->h>yr->h) {
		yr->f=xr;
	} else if (yr->h>xr->h) {
		xr->f=yr;
	} else {
		xr->f=yr;
		yr->h++;
	}
}
