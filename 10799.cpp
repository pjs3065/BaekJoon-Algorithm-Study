#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int len = s.length();

	stack<int> stick;

	int ans = 0;

	for(int i = 0; i < len ; i++)
	{
		if(s[i] == '(')
		{
			stick.push(i);
		}
		else
		{
			if(stick.top() + 1 == i)
			{
				stick.pop();
				ans += stick.size();
			}
			else
			{
				stick.pop();
				ans += 1;
			}
		}
	}

	printf("%d\n",ans);

	return 0;
}