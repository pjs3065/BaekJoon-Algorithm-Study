#include<stdio.h>
#include<vector>

using namespace std;
vector< vector<int> > map;

void calculate_star(int n, int t, int d)
{
	if(n == 3)
	{
		map[t][d] = 1;
		map[t+1][d-1] = 1;
		map[t+1][d+1] = 1;

		for(int i = d - 2; i <= d + 2; i++)
		{
			map[t+2][i] = 1;
		}

		return;
	}

	int half = n / 2;

	//»ï°ÝÇü ¼¼°³
	calculate_star(half,t, d);
	calculate_star(half,t + half, d - half);
	calculate_star(half,t + half, d + half);
}

void print_star(int n)
{
		for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 2 * n; j++)
		{
			if(map[i][j] == 1)
			{
				printf("*");
			}
			else
				printf(" ");
		}
		printf("\n");
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);

	for(int i = 0; i < n; i++)
	{
		vector<int> element(2*n);
		map.push_back(element);
	}

	calculate_star(n, 0, n-1);
	print_star(n);

	return 0;
}