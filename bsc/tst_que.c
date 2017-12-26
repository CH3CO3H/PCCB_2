#include <stdio.h>
#include "que.h"

int main(void)
{
	struct QUE point={};
	que_t a={3,0};
	que_t b={5,2};
	que_psh(a, &point);
	que_psh(b, &point);
	que_t t=que_pop(&point);
	printf("%d %d\n", t.x, t.y);

	return 0;
}

