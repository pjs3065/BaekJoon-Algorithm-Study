#include<stdio.h>
int main(void)
{
	char week[7][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int cur_day = 1;
	
	int mon, day;
	int total = 0;

	scanf("%d %d",&mon, &day);

	for(int i = 1; i < mon; i++)
	{
		total += days[i];
	}

	total += day - cur_day;
	printf("%s\n",week[total % 7]);

	return 0;
}