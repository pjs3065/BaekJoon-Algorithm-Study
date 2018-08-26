#include<stdio.h>
#include<iostream>

using namespace std;

int sub[1001];
int d[1001];

int main()
{
	int n;
	scanf("%d",&n);

	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&sub[i]);
	}

	d[1] = 1;

	for(int i = 2; i <= n; i++)
	{
		for(int j = i - 1; j >= 1; j--)
		{
			if(sub[i] > sub[j])
			{
				d[i] = max(d[i], d[j]);
			}
		}

		d[i] = d[i] + 1;
	}

	int ans = 0;

	for(int i = 1; i <= n; i++)
	{
		ans = max(ans,d[i]); 
	}

	printf("%d\n",ans);

	return 0;
}