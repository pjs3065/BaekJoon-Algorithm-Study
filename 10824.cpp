#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s[4];
	for(int i = 0; i< 4; i++)
	{
		cin >> s[i];
	}

	long long AB = stoll(s[0] + s[1]);
	long long CD = stoll(s[2] + s[3]);

	printf("%lld\n", AB+CD);
}