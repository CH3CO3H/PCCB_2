int hep[N], n=0;
void psh(int x)
{
	int i=n++;
	while (i>0) {
		int p=(i-1)/2;
		if (hep[p]<=x)
			break;
		hep[i]=hep[p];
		i=p;
	}
	hep[i]=x;
}

int pop() {
	int r=hep[0];
	int x=hep[--n];
	int i=0;
	while (i*2+1<n) {
		int a=i*2+1, b=i*2+2;
		if (b<n && hep[b]<hep[a])
			a=b;
		if (hep[a]>=x)
			break;
		hep[i]=hep[a];
		i=a;
	}
	hep[i]=x;
	return r;
}

