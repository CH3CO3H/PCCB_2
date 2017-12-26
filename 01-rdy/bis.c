int bis(int a[], int x, int s, int e)
{
	if (s==e)
		if (a[s]==x)
			return 0;
		else
			return 1;
	else {
		int m=(s+e)/2;
		if (a[m]==x)
			return 0;
		if (a[m]>x)
			bis(a, x, s, m-1);
		else
			bis(a, x, m+1, e);
	}
}

