#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int n, c = 1;
	int w, e;

	//테스트 케이스 입력
	scanf("%d", &n);

	while(c <= n)
	{
		//서쪽, 동쪽 입력
		scanf("%d %d",&w,&e);

		if(w == e)
		{
			printf("1\n");
			c++;
			continue;
		}

		else if(w == 1)
		{
			printf("%d\n",e);
			c++;
			continue;
		}

		int ans = 1;
		int dis = e - w + 1;

		for(int i = e; i >= dis; i--)
		{
			ans *= i;
		}

		printf("%d\n",ans);
		c++;
	}

	return 0;
}