#include <stdio.h>
#include "../bsc/que.h"

#define INF (1<<10)
#define MAX_R 15
#define MAX_C 15

char maz[MAX_R][MAX_C];
int r, c;
int sx, sy;
int ex, ey;

static void input();
static void setSnE();
static int bfs();

int main(void)
{
	input();
	setSnE();
	printf("%d\n", bfs());

	return 0;
}

void input(void)
{
		scanf("%d%d\n", &r, &c);
		int i, j;
		for (i=0;i<r;i++) {
				for (j=0;j<c;j++)
						scanf("%c", &maz[i][j]);
				getchar();
		}
}

void setSnE(void)
{
		int i,j;
		for (i=0;i<r;i++)
				for (j=0;j<c;j++)
						if (maz[i][j]=='S')
								sx=i, sy=j;
						else if (maz[i][j]=='G')
								ex=i, ey=j;
}

int bfs()
{

	int d[MAX_R][MAX_C];
	int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
	int i, j;
	for (i=0;i<r;i++)
			for (j=0;j<c;j++)
					d[i][j]=INF;
	struct QUE point={};
	que_t start={sx, sy};
	que_psh(start, &point);
	d[sx][sy]=0;

	while (!que_ety(&point)) {
		que_t p=que_pop(&point);
		if (p.x==ex && p.y==ey) break;
		for (i=0;i<4;i++) {
			int nx=p.x+dx[i], ny=p.y+dy[i];
			if (nx>=0 && nx<r && ny>=0 && ny<c && maz[nx][ny]!='#' && d[nx][ny]==INF) {
				que_t t={nx, ny};
				que_psh(t, &point);
				d[nx][ny]=d[p.x][p.y]+1;
			}
		}
	}
	return d[ex][ey];
}

