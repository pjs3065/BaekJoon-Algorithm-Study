#include<stdio.h>

int main()
{
	char s[101];
	scanf("%s",s);

	int len = 0;

	for(int i = 0; s[i]; i++)
	{
		len ++;
	}
	
	printf("%d\n",len);
	
	return 0;
}