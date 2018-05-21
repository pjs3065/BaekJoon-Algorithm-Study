#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int han[1001] = {0,};
	int n;
	scanf("%d", &n);

	if(n < 100)
	{
		printf("%d\n", n);
		return 0;
	}

	int m = 100;
	int ans = 99;

	for(int i = 100; i <= n; i++)
	{
		int number = i;
		vector<int> elements; 

		for(int j = m; j > 0; j = j / 10)
		{
			int d = number / j;
			number = number % j;
			elements.push_back(d);
		}

		int check = 1;
		int distance = elements[0] - elements[1];

		for(int i = 0; i < elements.size()-1; i++)
		{
			if(!(distance == (elements[i] - elements[i+1])))
			{
				check = 0;
			}
		}

		if(check == 1)
		{
			ans += 1;
		}
	}
	printf("%d\n", ans);
}