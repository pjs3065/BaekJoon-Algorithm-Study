#include<stdio.h>
int main(void)
{
	int n;
	int a[100] ={0,};
	int b[100] = {0,};
	int sum[100] = {0,};
	
	scanf("%d",&n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		sum[i] = a[i] + b[i];
	}

	for(int i = 0; i < n; i++)
	{
		printf("Case #%d: %d + %d = %d\n", i+1, a[i], b[i], sum[i]);
	}
	return 0;
}