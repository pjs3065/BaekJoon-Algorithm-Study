#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	vector<int> f(10);
	char ch;
	while((ch = getchar()) != '\n') f[ch-'0']++;

	int max = 0;
	int index;

	for(int i = 0; i < 10; i++)
	{
		if(max < f[i])
		{
			max = f[i];
			index = i;
		}
	}

	if(index == 9 || index == 6)
	{
		max = f[6] + f[9] + 1;

		printf("%d\n", max/2);
	}
	else
	{
		printf("%d\n",max);
	}

	return 0;
}