#include<cstdio>
#include<queue>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d",&n, &m);

	queue<int> jo;

	for(int i = 1; i <= n; i++)
	{
		jo.push(i);
	}

	printf("<");
	while(!jo.empty())
	{
		if(jo.size() > 1)
		{
			for(int i = 0; i < m - 1; i++)
			{
				jo.push(jo.front());
				jo.pop();
			}

			printf("%d, ",jo.front());
		}

		else printf("%d>\n",jo.front());
		jo.pop();
	}
	return 0;
}
