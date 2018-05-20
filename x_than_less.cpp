#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int n, x;
	scanf("%d %d", &n, &x);

	vector<int> less;

	for(int i = 0; i < n; i++)
	{
		int number;
		scanf("%d",&number);

		if(number < x)
		{
			less.push_back(number);
		}
	}

	int length = less.size();

	for(int i = 0; i < length; i++)
	{
		printf("%d ",less[i]);
	}

	return 0;
}