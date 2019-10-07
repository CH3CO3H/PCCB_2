#include <stdio.h>

#define MAX_N 100000

int n;
int s[MAX_N];
int t[MAX_N];

struct section {
	int s;
	int e;
};
typedef struct section section;
section itv[MAX_N];

static void sort(void);
static void mergsort(int s, int e);
static void merg(int s, int e);

int main(void) {
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &s[i]);
	}
	for (int i=0;i<n;i++) {
		scanf("%d", &t[i]);
	}
	for (int i=0;i<n;i++) {
		itv[i].s=s[i];
		itv[i].e=t[i];
	}
	sort();
	int ans=0;
	int fin=0;
	for (int i=0;i<n;i++) {
		if (fin<itv[i].s) {
			ans++;
			fin=itv[i].e;
		}
	}
	printf("%d\n", ans);
	return 0;
}

static void sort(void) {
	mergsort(0, n-1);
}

static void mergsort(int s, int e) {
	if (s==e) return;
	mergsort(s, (s+e)/2);
	mergsort((s+e)/2+1, e);
	merg(s, e);
}

static void merg(int s, int e) {
	int p1, p2;
	int m=(e+s)/2;
	for (p1=s,p2=m+1;p1<=m && p2<=e;) {
		if (itv[p1].e>itv[p2].e) {
			section ts=itv[p2];
			for (int i=p2;i>p1;i--) {
				itv[i]=itv[i-1];
			}
			itv[p1]=ts;
			p1++;
			p2++;
		} else {
			p1++;
		}
	}
	if (p1<=m) {
		int len=m-p1+1;
		section ta[len];
		for (int i=0;i<len;i++) {
			ta[i]=itv[p1+i];
		}
		for (int i=m+1;i<=e;i++) {
			itv[i-len]=itv[i];
		}
		for (int i=0;i<len;i++) {
			itv[e-len+1+i]=ta[i];
		}
	}
}
