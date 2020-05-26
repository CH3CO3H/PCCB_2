#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N_MAX 500

unsigned n;
unsigned m;
int x[N_MAX];

int compare_x (const void* a, const void* b);
void solve (int s, int e, int rlt[]);
bool cod (int k, int rlt[]);
void print_rlt(int rlt[]);

int main(void) {
	scanf("%u%u", &n, &m);
	for (int i=0;i<n;i++) {
		scanf("%u", &x[i]);
	}

	qsort (x, n, sizeof (int), compare_x);
	int rlt[m];
	int du=x[n-1]-x[0];
	int dl=0;
	solve(dl, du, rlt);
	return 0;
}

int compare_x (const void* a, const void* b) {
	return *(int*)a-*(int*)b;
}

void solve (int s, int e, int rlt[]) {
	if (e-s==1) {
		if (cod(e,rlt)) {
			print_rlt(rlt);
		} else {
			cod(s, rlt);
			print_rlt(rlt);
		}
		return;
	}
	int m=(e+s)/2;
	if (cod(m,rlt)) {
		solve(m, e, rlt);
	} else {
		solve(s, m, rlt);
	}
}

bool cod (int k, int rlt[]) {
	int last=0;
	rlt[0]=0;
	for (int i=1;i<m;i++) {
		int nxt=last+1;
		while (nxt<n && x[last]+k>x[nxt]) {
			nxt++;
		}
		if (nxt==n) return false;
		last=nxt;
		rlt[i]=last;
	}
	return true;
}

void print_rlt(int rlt[]) {
	for (int i=0;i<m;i++) {
		printf("%d\t", x[rlt[i]]);
	}
	putchar('\n');
}
