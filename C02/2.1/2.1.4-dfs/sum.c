#include <stdio.h>
#include <stdbool.h>
#define MAX_N 20

static bool dfs(int i, int sum);

int a[MAX_N];
int n, k;

int main(void) {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &k);
	if (dfs(0, 0)) printf("Yes\n");
	else printf("No\n");
	return 0;
}

bool dfs(int i, int sum) {
	if (i==n) return sum==k;
	if (dfs(i+1, sum)) return true;
	if (dfs(i+1, sum+a[i])) return true;
	return false;
}
