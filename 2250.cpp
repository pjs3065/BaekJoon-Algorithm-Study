#include<stdio.h>
#include<math.h>
#include<vector>

using namespace std;

vector<int> tree[10001];
vector<int> check[10001];

int col= 1;

void infix(int s, int level)
{
	if(s == -1)
		return;

	infix(tree[s][0],level + 1);

	check[level].push_back(col++);
	
	infix(tree[s][1],level + 1);
}

int main()
{
	int n;
	scanf("%d", &n);

	int root;

	for(int i = 1; i <= n; i++)
	{
		int s, v1, v2;
		scanf("%d %d %d", &s, &v1, &v2);

		if(i == 1)
		{
			root = s;
		}

		tree[s].push_back(v1);
		tree[s].push_back(v2);
	}

	infix(root,1);

	/*
	for(int i = 1; i<= n + 1; i++)
	{
		printf("%d : ",i);
		for(int j = 0; j < check[i].size(); j++)
		{
			printf("%d ", check[i][j]);
		}
		printf("\n");
	}
	*/
	
	int max_distance = -1;
	int max_height = -1;

	for(int i = 1; i <= n + 1; i++)
	{
		int start = 0;
		int end = check[i].size() - 1;

		if(end != -1)
		{
			int distance = check[i][end] - check[i][start] + 1;

			if(max_distance < distance)
			{
				max_distance = distance;
				max_height = i;
			}
		}
	}

	printf("%d %d\n", max_height, max_distance);

	return 0;
}