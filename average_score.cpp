#include<stdio.h>

int main()
{
	int score[5];
	int sum = 0;

	for(int i = 0; i < 5; i++)
	{
		scanf("%d", &score[i]);

		if(score[i] < 40)
		{
			score[i] = 40;
		}

		sum += score[i];
	}

	int avg = sum/5;

	printf("%d\n",avg);

	return 0;
}