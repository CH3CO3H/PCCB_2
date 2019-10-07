#include <stdio.h>

#define MAX_M 100
#define MAX_N 100

static void dfs(int x, int y);

int n, m;
char field[MAX_N][MAX_M+1];

int main(void) {
	scanf("%d%d", &n, &m);
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			scanf("%c", &field[i][j]);
		}
	}

	int res=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (field[i][j]=='W') {
				dfs(i, j);
				res++;
			}
		}
	}
	printf("%d\n", res);
	return 0;
}

static void dfs(int x, int y) {
	field[x][y]='.';
	int nx, ny;
	for (int dx=-1;dx<2;dx++) {
		for (int dy=-1;dy<2;dy++) {
			nx=x+dx;
			ny=y+dy;
			if (nx>=0 &&
					nx<n &&
					ny>=0 &&
					ny<m &&
					field[nx][ny]=='W')
				dfs(nx, ny);
		}
	}
}
