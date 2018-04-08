#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	vector<int> a(5);

	for(int i = 0; i < 5; i++)
	{
		a.push_back(i);
	}

	cout << a.size() << '\n';

	for(int i = 0; i < a.size(); i++)
	{
		cout << a[i];
	}
}