#include <stdio.h>
#include <stdbool.h>

#define N_MAX 1000

#define max(x, y) ((x)>(y)?(x):(y))

unsigned n;
unsigned k;
double l[N_MAX];

bool isget(double x);
static double maxc(double l[]);
double maxlen(double s, double e);

int main(void) {
	scanf("%u%u", &n, &k);
	for (int i=0;i<n;i++) {
		scanf("%le", &l[i]);
	}
	double s=0;
	double e=maxc(l);
	printf("%.2f\n", maxlen(s, e));
	return 0;
}

static double maxc (double l[]) {
	double ret=0;
	for (int i=0;i<n;i++) {
		ret=max(ret, l[i]);
	}
	return ret;
}

double maxlen(double s, double e) {
	if (e-s<0.005) return s;
	double m=(s+e)/2;
	if (isget(m)) return maxlen(m, e);
	else return maxlen(s, m);
}

bool isget(double x) {
	unsigned num=0;
	for (int i=0;i<n;i++) {
		num+=(unsigned)(l[i]/x);
	}
	return num>=k;
}
