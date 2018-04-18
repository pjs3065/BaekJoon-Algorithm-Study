#include<iostream>
using namespace std;

int main()
{
	int n, s, ans = 0;
	cin >> n >> s;

	int n_line[10001];

	for(int i = 0; i < n; i++)
	{
		cin >> n_line[i];
	}

	int right = 0;
	int left = 0;
	int sum = n_line[0];

	while(right < n)
	{
		if(sum == s)
		{
			ans = ans + 1;
			right++;
			sum += n_line[right];
		}

		else if(sum > s)
		{
			if(right == left)
			{
				right++;
				sum += n_line[right];
			}
			else
			{
				left++;
				sum -= n_line[left - 1];
			}
		}

		else if(sum < s)
		{
			right++;
			sum += n_line[right];
		}
	}

	cout << ans << '\n';
	return 0;

}
