#include<cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	int i;
	for(i = 1; i < n ; n -= i++);
	if(i % 2 == 0) printf("%d/%d\n",n,i-n+1);
	else printf("%d/%d\n",i-n+1,n);
	return 0;
}