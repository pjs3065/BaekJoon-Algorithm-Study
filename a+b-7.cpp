#include<stdio.h>
int main(void)
{
	int n,a,b;
	int sum[100] = {0,};
	scanf("%d",&n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d %d",&a,&b);
		sum[i] = a + b;
	}

	for(int i = 0; i < n; i++)
	{
		printf("Case #%d: %d\n", i+1, sum[i]);
	}
	return 0;
}