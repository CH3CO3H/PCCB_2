#include <stdio.h>
#include <stdbool.h>

#define MAX_N 2000

int n;
char s[MAX_N+1];

int main(void) {
	scanf("%d\n", &n);
	for (int i=0;i<n;i++) {
		scanf("%c", &s[i]);
	}
	int a=0;
	int b=n-1;
	while (a<=b) {
		bool left=false;
		for (int i=0;a+i<=b;i++) {
			if (s[a+i]<s[b-i]) {
				left=true;
				break;
			} else if (s[a+i]>s[b-i]) {
				left=false;
				break;
			}
		}
		if (left) putchar(s[a++]);
		else putchar(s[b--]);
	}
	putchar('\n');
	return 0;
}
