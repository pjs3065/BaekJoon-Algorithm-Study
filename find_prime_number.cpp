#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);

	vector<int> number(t);

	for(int i = 0; i < t; i++)
	{
		scanf("%d",&number[i]);
	}

	int ans = 0;

	for(int i = 0; i < t; i++)
	{
		int ischeck = 0;

		for(int j = 2; j < number[i]; j++)
		{
			if(number[i] % j == 0)
			{
				ischeck = 1;
				break;
			}
		}

		if(!ischeck && number[i] > 1)
		{
			ans++;
		}
	}

	printf("%d\n",ans);

	return 0;
}