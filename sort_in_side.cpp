#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> number; 
	char n;

	while(1)
	{
		n = getchar();
		if(n == '\n')
			break;

		number.push_back(n-'0');
	}

	sort(number.rbegin(), number.rend());

	int len = number.size();
	for(int i = 0; i < len; i++)
	{
		printf("%d",number[i]);
	}
	printf("\n");

	return 0;
}