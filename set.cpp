#include<stdio.h>
#include<string.h>
#define lengh 10
int main(void)
{
	char s[lengh];
	int c,n;
	int b = 0;

	scanf("%d",&c);
	while(c--)
	{
		for(int i = 0; i < lengh; i++)
		{
			s[i] = '\0';
		}

		scanf("%s",s);

		if(strcmp(s,"add") == 0)
		{
			scanf("%d",&n);
			b = b | (1 << (n-1));
		}

		else if(strcmp(s,"remove") == 0)
		{
			scanf("%d",&n);
			b = b & ~(1 << (n-1));
		}

		else if(strcmp(s,"check") == 0)
		{
			scanf("%d",&n);
			if((b & (1 << (n-1))) != 0)
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}

		else if(strcmp(s,"toggle") == 0)
		{
			scanf("%d",&n);
			if((b & (1 << (n-1))) != 0)
			{
				b = b & ~(1 << (n-1));
			}
			else
			{
				b = b | (1 << (n-1));
			}
		}

		else if(strcmp(s,"all") == 0)
		{
			b = ~(b & 0);
		}

		else if(strcmp(s,"empty") == 0)
		{
			b = b & 0;
		}
	}

	return 0;
}