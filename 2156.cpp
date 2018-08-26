#include<stdio.h>
#include<iostream>

using namespace std;

int d[10001][2];
int p[10001];

int main()
{
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&p[i]);
	}

	for(int i = 1; i <= n; i++)
	{
		//포도주가 2이하일 경우
		if(i <= 2)
		{
			d[i][0] = p[i-1];
			d[i][1] = p[i-1] + p[i];
			continue;
		}
		
		//현재 포도주를 먹지 않을 경우
		d[i][0] = max(d[i-1][0], d[i-1][1]);
		
		//현재 포도주를 먹을 경우
		d[i][1] = max(p[i] + d[i-2][0] + p[i-1], p[i] + d[i-1][0]);
	}

	printf("%d\n",max(d[n][0],d[n][1]));
	return 0;
}