#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int n;
	int max = -1;

	scanf("%d", &n);

	vector<float> score;

	for(int i = 0; i < n; i++)
	{
		int number;
		scanf("%d", &number);
		score.push_back(number);

		if(max < number)
		{
			max = number;
		}
	}

	float sum = 0;

	for(int i = 0; i < n; i++)
	{
		float new_number = score[i]/max * 100;
		sum += new_number;
	}

	float avg = sum / n;

	printf("%.2f\n",avg);

	return 0;
}