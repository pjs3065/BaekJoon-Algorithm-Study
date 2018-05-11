#include<stdio.h>
int main()
{
	int a, b, c;
	int mod1, mod2, mod3, mod4;
	scanf("%d %d %d", &a, &b, &c);

	mod1 = (a+b)%c;
	mod2 = (a%c + b%c)%c;
	mod3 = (a*b)%c;
	mod4 = (a%c * b%c)%c;

	printf("%d\n%d\n%d\n%d\n",mod1,mod2,mod3,mod4);	
}