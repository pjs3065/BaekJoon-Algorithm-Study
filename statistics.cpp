#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;

	vector<int> f(500001);
	vector<int> m;

	scanf("%d",&n);
	
	int integer;

	float sum = 0;
	
	int max = -4001;
	int min = 4001;

	for(int i = 0; i < n; i++)
	{
		//input
		scanf("%d", &integer);
		sum += integer;

		// frequency
		f[integer]++;

		//middle
		m.push_back(integer);

		// min, max
		if(max < integer)
		{
			max = integer;
		}

		if(min > integer)
		{
			min = integer;
		}
	}

	//average
	float avg = sum/n;

	//middle
	sort(m.begin(),m.end());
	int mid = m[n/2];

	//range
	int range = max - min;


	return 0;
}