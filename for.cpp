#include<stdio.h>
int main()
{
	double p = 1;
	p = 1;
	for(int i = 0; i < 5; i++, p *= i);
	printf("%.3f",p);
}