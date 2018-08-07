#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);

	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		int len = s.length();
		int left = 0;
		int right = 0;

		bool vps = true;

		for(int j = 0; j < len; j++)
		{
			if(s[j] == '(')
				left ++;
			else if(s[j] == ')')
				right ++;

			if(left < right)
			{
				vps = false;
				break;
			}
		}

		if(left != right) vps = false;

		if(vps == false) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}