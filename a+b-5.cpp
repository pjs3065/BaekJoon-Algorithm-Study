#include<stdio.h>
int main(void)
{
	int a,b,n;
	int sum[100] = {0,};
	int i = 0;

	while(1)
	{
		scanf("%d %d",&a, &b);
		if(a == 0 && b == 0)
			break;
		sum[i] = a + b;
		i++;
	}
	
	n = i;

	for(i = 0; i < n; i++)
	{
		printf("%d\n", sum[i]);
	}

	return 0;
}