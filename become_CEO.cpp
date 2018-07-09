#include<cstdio>
int t,k,n,room[15];
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &k,&n);
		for(int i = 1; i <= n; i++) room[i] = i;
		for(int i = 0; i < k; i++)
		{
			for(int j = 2; j <= n; j++)
			{
				room[j] += room[j-1];  
			}
		}
		printf("%d\n",room[n]);
	}
}