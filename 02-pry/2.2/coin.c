#include <stdio.h>

static void input(void);
static int min(int, int);

int c[6];
const int V[6]={1,5,10,50,100,500};
int a;

int main(void)
{
	int r=0;
	int i;
	input();
	for (i=5;i>=0;i--) {
		int t=min(a/V[i], c[i]);
		a-=t*V[i];
		r+=t;
	}

	printf("%d\n", r);

	return 0;
}

void input(void)
{
	int i;
	for (i=0;i<6;i++)
		scanf("%d", &c[i]);
	scanf("%d", &a);
}

int min(int a, int b)
{
	return a>b?b:a;
}

