#include<stdio.h>
int main(void)
{
	char s[101];

	while(fgets(s,100,stdin))
	{
		printf("%s",s);
	}
	return 0;
}