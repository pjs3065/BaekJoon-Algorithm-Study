#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> number(n);

	for(int i = 0; i <n; i++)
	{
		scanf("%d",&number[i]);
	}

	sort(number.begin(), number.end());

	for(int i = 0; i< n; i++)
	{
		printf("%d\n",number[i]);
	}
	return 0;
}