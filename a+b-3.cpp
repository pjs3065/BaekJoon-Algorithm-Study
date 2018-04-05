#include<stdio.h>
int main(void)
{
	int n,a,b;
	int sum;

	scanf("%d",&n);
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d",&a,&b);
		sum = a + b;
		printf("%d\n", sum);
	}
	return 0;
}