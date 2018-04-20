#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int distance(int x1, int y1, int x2, int y2)
{
	int d;
	d = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
	return d;
}

int main(void)
{
	int t;
	int count = 1;
	bool result_count1[100000];
	bool result_count2[100000];

	int x1,y1,x2,y2;
	int r1, r2;

	//몇번 입력할지?
	scanf("%d",&t);

	//입력한 만큼  반복
	while(count <= t)
	{
		scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);

		for(int i = x1-r1; i <= x1 + r1; i++)
		{
			for(int j = y1-r1; j <= y1 + r1; j++)
			{
				int dis = distance(i,j,x1,y1);
				if(dis == r1)
				{
					result_count1[dis] = true;
				}
			}
		}


		for(int i = x2-r2; i<= x2+r2; i++)
		{
			for(int j= y2-r2; j<= y2+r2; j++)
			{
			
				int dis = distance(i,j,x2,y2);
				if(dis == r2)
				{
					result_count2[dis] = true;
				}
			}
		}

		int ans = 0;

		for(int i = 0; i<= 30000; i++)
		{
			if(result_count1 == result_count2)
			{
				ans++;
			}
		}
		scanf("%d\n", ans);
		count++;
	}
	return 0;
}