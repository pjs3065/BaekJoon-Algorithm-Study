#include<stdio.h>
int main()
{
	int t, count = 1;
	scanf("%d", &t);

	while(count <= t)
	{
		int a, b;
		int sum = 0;
		
		scanf("%d %d",&a,&b);

		sum = a + b;
		printf("%d\n", sum);

		count++;
	}
}