#include<stdio.h>

using namespace std;

int main()
{
	int degree[9];

	for(int i = 1; i < 9; i++)
	{
		scanf("%d", &degree[i]);
	}

	int check1 = 1;
	int check2 = 1;

	for(int i = 1; i< 9; i++)
	{
		if(i != degree[i])
		{
			check1 = 0;
		}

		if( 9 - i != degree[i])
		{
			check2 = 0;
		}

		if(check1 == 0 && check2 == 0)
		{
			printf("mixed\n");
			break;
		}
	}

	if(check1 == 1)
	{
		printf("ascending\n");
	}
	else if(check2 == 1)
	{
		printf("descending\n");
	}

	return 0;
}