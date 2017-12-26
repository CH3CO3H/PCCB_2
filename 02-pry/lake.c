#include <stdio.h>

#define MAX_M 32
#define MAX_N 32

unsigned int n, m;
char field[MAX_N][MAX_M];
static void dfs(unsigned int, unsigned int);
static void input(unsigned int*, unsigned int*, char[MAX_N][MAX_M]);

int main(void)
{
		input(&n, &m, field);
		unsigned int c=0;
		unsigned int i, j;
		for (i=0;i<n;i++)
				for (j=0;j<m;j++)
						if (field[i][j]=='W') {
								dfs(i, j);
								c++;
						}
		printf("%d\n", c);

		return 0;
}

void dfs(unsigned int x, unsigned int y)
{
		field[x][y]='.';
		int i, j;
		for (i=-1;i<2;i++)
				for (j=-1;j<2;j++) {
						int p, q;
						p=x+i;
						q=y+j;
						if (p>-1 && p<n && q>-1 && q<m && field[p][q]=='W')
								dfs(p, q);
				}
}

void input(unsigned int* n, unsigned int* m, char f[MAX_N][MAX_M])
{
		scanf("%d%d", n, m);
		unsigned int i, j;
		getchar();
		for (i=0;i<*n;i++) {
				for (j=0;j<*m;j++)
						scanf("%c", &f[i][j]);
				getchar();
		}
}

