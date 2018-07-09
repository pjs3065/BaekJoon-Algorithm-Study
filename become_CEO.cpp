#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int t, count = 1;
	scanf("%d", &t);


	while(count <= t)
	{
		int k, n;
		scanf("%d %d", &k,&n);

		vector< vector<int> > building;

		for(int i = 0; i <= k; i++)
		{
			vector<int> room(n + 1);
			building.push_back(room);
		}

		for(int i = 0; i <= k; i++)
		{
			building[k-i][1] = 1; 
		}

		for(int j = 1; j <= n; j++)
		{
			building[k][j] = j;
		}

		for(int i = 1; i <= k; i++)
		{
			for(int j = 2; j <= n; j++)
			{
				building[k-i][j] = building[k-i][j-1] + building[k-i+1][j];
			}
		}

		printf("%d\n",building[0][n]);
		count++;
	}
	return 0;
}