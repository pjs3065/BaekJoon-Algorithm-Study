#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	vector<int> n(3);

	for(int i = 0; i < 3; i++)
	{
		scanf("%d", &n[i]);
	}

	sort(n.begin(), n.end());
	printf("%d\n", n[1]);
}