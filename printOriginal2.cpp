#include<stdio.h>


int main(void)
{
	char s;
	while((s = getchar()) && s != EOF)
	{
		printf("%c",s);
	}

	return 0;
}