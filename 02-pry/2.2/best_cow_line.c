#include <stdio.h>

#define L 15

int n;
char s[L];

void ipt()
{
	int i;
	scanf("%d\n", &n);
	for (i=0;i<n;i++)
		s[i]=getchar();
}

int main(void)
{
	ipt();
	int a=0, b=n-1;
	while (a<b) {
		short l=0;
		unsigned int i;
		for (i=0;a+i<b-i;i++)
			if (s[a+i]<s[b-i]) {
				l=1;
				break;
			}
		if (l) putchar(s[a++]);
		else
			putchar(s[b--]);
	}
	putchar(s[a]);
	putchar('\n');
	return 0;
}
