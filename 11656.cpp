#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int len = s.length();

	vector<string> sub;

	for(int i = 0; i < len; i++)
	{
		sub.push_back(s.substr(i,len-i));
	}

	sort(sub.begin(),sub.end());

	for(int i = 0; i < sub.size(); i++)
	{
		cout << sub[i] <<'\n';
	}

	return 0;
}