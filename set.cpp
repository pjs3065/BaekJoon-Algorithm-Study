#include<stdio.h>
#include<string.h>

int main(void)
{
	int c, s;
	int b = 0;
	char o[10] ={0,};

	scanf("%d",&c);

	for(int i = 0; i < c; i++)
	{
		scanf("%s %d",o ,&s);

		if(strcmp(o,"add") == 0)
		{
			b = b | 1 << (s-1);
		}

		else if(strcmp(o,"check") == 0)
		{
			printf("%d\n",(b & 1<<(s-1)) >> (s-1));

			/* instead of up line
			if(b & 1<<(s-1))
			{
				printf("1\n");
			}
			else
				printf("0\n");
			*/
		}

		else if(strcmp(o, "remove") == 0)
		{
			b = b & ~(1 << (s-1));
		}

		else if(strcmp(o, "toggle") == 0)
		{
			b = b ^ (1 << (s-1));

			
		}

		else if(strcmp(o, "all") == 0)
		{
			b = b | (1 << 20) - 1;
		}

		else if(strcmp(o, "empty") == 0)
		{
			b = b & 0;
		}
	}
	return 0;
}