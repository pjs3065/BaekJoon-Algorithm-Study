#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int total = 64;
	int short_stick = 64;

	int ans = 1;

	do
	{
		if(n == 64)
		{
			break;
		}

		short_stick = short_stick / 2;
		
		if(total - short_stick >= n)
		{
			total = total - short_stick;
		}
		
		else
		{
			ans++;
		}

	}while(total != n);

	printf("%d\n",ans);

	return 0;
}