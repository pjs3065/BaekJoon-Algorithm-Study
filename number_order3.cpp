#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	vector<int>	order(10000);
	int number;
	int max = 0;

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &number);
		order[number]++;

		if(max < number)
		{
			max = number;
		}
	}

	for(int i = 1; i <= max; i++)
	{
		for(int j = 0; j < order[i]; j++)
		{
			printf("%d\n",i);
		}
	}

	return 0;
}