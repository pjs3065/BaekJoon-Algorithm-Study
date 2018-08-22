#include<cstdio>
#include<iostream>
using namespace std;

long long sticker[100001][2];
long long d[100001][3];

int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int n;
		scanf("%d", &n);

		// 스티커 점수
		for(int i = 0; i < 2; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				scanf("%lld",&sticker[j][i]);
			}
		}

		//첫 스티커는 모두 0이라고 둔다.
		d[0][0] = d[0][1] = d[0][2] = 0;

		for(int i = 1; i <= n; i++)
		{
			d[i][0] = max(d[i-1][0],max(d[i-1][1],d[i-1][2]));
			d[i][1] = max(d[i-1][0],d[i-1][2]) + sticker[i][0];
			d[i][2] = max(d[i-1][0],d[i-1][1]) + sticker[i][1];
		}

		printf("%lld\n",max(d[n][0],max(d[n][1],d[n][2])));
	}
	return 0;
}