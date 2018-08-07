#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main()
{
	string s;
	cin >> s;

	int len = s.length();
	vector<int> alpha (26);

	for(int i = 0; i < len; i++)
	{
		alpha[s[i]-'a']++;
	}

	for(int i = 0; i < 26; i++)
	{
		cout << alpha[i] << " ";
	}

	cout << '\n';
	return 0;
}