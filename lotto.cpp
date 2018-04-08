#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n;


	while(1)
	{
		cin >> n;

		if(n == 0)
		{
			return 0;
		}

		vector<int> s(n);
		vector<int> order(n);

		for(int i = 0; i < n; i++)
		{
			cin >> s[i];

			if(i < 6)
			{
				order[i] = 1;
			}
			else
				order[i] = 0;
		}

		do
		{
			for(int i = 0; i < n; i++)
			{
				if(order[i])
				{
					cout << s[i] << ' ' ;
				}
			}
			cout << '\n';
		}while(prev_permutation(order.begin(), order.end()));
		
		cout << '\n';

	}
	return 0;
}