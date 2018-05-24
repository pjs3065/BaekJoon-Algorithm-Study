#include<stdio.h>
int main()
{
	int in[4];
	int out[4];

	int total = 0;
	int max = -1;

	for(int i = 0; i < 4; i++)
	{
		scanf("%d %d", &in[i], &out[i]);
		total = total + out[i] - in[i];

		if(max < total)
		{
			max = total;
		}
	}

	printf("%d\n", max);
	return 0;
}