#include <stdio.h>
#include <stdbool.h>

#define MAX_M 100
#define MAX_N 100

typedef struct pair {
	int x;
	int y;
} pair;

char maze[MAX_N][MAX_M];
const int inf=100000;
int n, m;
int sx, sy;
int gx, gy;
int d[MAX_N][MAX_M];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
pair que[10000];
size_t pos;

static int bfs(void);
static void push(pair p);
static pair pop(void);
static bool is_empty(void);
static void print_maze(void);

int main(void) {
	scanf("%d%d\n", &n, &m);
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			scanf("%c", &maze[i][j]);
			if (maze[i][j]=='G') {
				gx=i;
				gy=j;
			} else if (maze[i][j]=='S') {
				sx=i;
				sy=j;
			}
		}
		getchar();
	}
//	print_maze();
	int res=bfs();
	printf("%d\n", res);
	return 0;
}

static int bfs(void) {
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			d[i][j]=inf;
		}
	}
	pair start = {sx, sy};
	push(start);
	d[sx][sy]=0;
	while(!is_empty()) {
		pair p=pop();
		if (p.x==gx && p.y==gy) break;
		for (int i=0;i<4;i++) {
			int nx=p.x + dx[i];
			int ny=p.y+dy[i];
			if (nx>=0 &&
					nx<n &&
					ny>=0 &&
					ny<m &&
					maze[nx][ny]!='#' &&
					d[nx][ny]==inf) {
				pair t={nx, ny};
				push(t);
				d[nx][ny]=d[p.x][p.y]+1;
//				printf("point: (%d, %d). dis: %d", nx, ny, d[nx][ny]);
			}
		}
	}
	return d[gx][gy];
}

static inline void push(pair p) {
//	printf("point: (%d, %d)pushed\n", p.x, p.y);
	que[pos++]=p;
}

static inline pair pop(void) {
	return que[--pos];
}

static inline bool is_empty(void) {
	return !pos;
}

static void print_maze(void) {
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			printf("%c", maze[i][j]);
		}
		putchar('\n');
	}
}
