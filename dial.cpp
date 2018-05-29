#include<stdio.h>

int main()
{
	char c;
	int timer = 0;

	while(scanf("%c",&c) == 1 && c != '\n')
	{
		if(c == 'Z') c--;
		if(c >= 'S') c--;

		int num = (c-'A')/3 + 3;
		timer += num;
	}

	printf("%d\n", timer);
	return 0;
}