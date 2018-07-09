#include<cstdio>
int t, h, w, n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&h,&w,&n);
		int f_n = n % h == 0 ? h : n % h;
		int r_n;

		if(n / h == 0)
		{
			r_n  = 1;
		}
		else
		{
			r_n = n % h == 0 ? n / h : n / h + 1;
		}

		if(r_n < 10) printf("%d%c%d\n", f_n,'0',r_n);
		else printf("%d%d\n",f_n,r_n);
	}
	return 0;
}