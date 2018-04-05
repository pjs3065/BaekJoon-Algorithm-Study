#include<stdio.h>

char s[100];
int main(void)
{
	while(scanf("%[^\n]\n",s) == 1)
	{
		printf("%s\n",s);
	}

	return 0;
}