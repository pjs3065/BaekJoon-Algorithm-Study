#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int t, count = 1;
	scanf("%d", &t);

	while(count <= t)
	{
		int n;
		scanf("%d", &n);

		vector<int> score(n);
		float sum = 0;

		for(int i = 0; i < n; i++)
		{
			scanf("%d", &score[i]);
			sum += score[i];
		}

		float avg = sum / n;
		float student = 0;

		for(int i = 0; i < n; i++)
		{
			if(score[i] > avg)
			{
				student += 1;
			}
		}

		float percent = (student/n) * 100;
		printf("%.3f%%\n",percent);

		count++;
	}

	return 0;
}