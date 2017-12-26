#define MAX_N 1<<8

unsigned int n, s[MAX_N], t[MAX_N];
struct {
	unsigned int s;
	unsigned int e;
} works[MAX_N];

static void input();
static void srt();
static void mrg();

int main(void)
{
	input();
	srt();

	unsigned int i, r=0, t=0;

	for(i=0;i<n;i++)
		if(t<works[i].s) {
			r++;
			t=works[i].e;
		}
	printf("%d\n", r);

	return 0;
}

void mrg(unsigned int s, unsigned int m, unsigned int e)
{
	if (s>m||m+1>e)
		return;
	if (works[s].e<=works[m+1].e)
		mrg(s+1, m, e);
	else {
		struct wk t=works[m+1];
		for (int i=0;i<m-s+1;i++)
			works[m+1-i]=works[m-i];
		works[s]=t;
		mrg(a, s, m+1, e);
	}
}

void srt(unsigned int s, unsigned e)
{
	if (e-s>1) {
		unsigned int m=(e+s)/2;
		srt(s, m);
		srt(m+1, e);
		mrg(s, m, e);
	} else {
		mrg(s, s, e);
	}
}

