#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;

	while(getline(cin,s))
	{
		int len = s.length();
		int alpha[4]= {0,};

		for(int i = 0; i < len; i++)
		{
			if(s[i] >= 'a' && s[i] <= 'z') alpha[0]++;
			else if(s[i] >= 'A' && s[i] <= 'Z') alpha[1]++;
			else if(s[i] >= '0' && s[i] <= '9') alpha[2]++;
			else alpha[3]++;
		}
		
		for(int i = 0; i< 4; i++)
		{
			if(i == 0) cout << alpha[i];
			else cout << ' ' << alpha[i];
		}

		cout << '\n';
	}
	return 0;
}