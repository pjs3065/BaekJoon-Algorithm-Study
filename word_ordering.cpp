#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool cmp(const pair<int, string>&v1, const pair<int, string>&v2)
{
	if(v1.first == v2.first)
		return v1.second < v2.second;
	return v1.first < v2.first;
}


int main()
{
	int n;
	scanf("%d",&n);

	vector< pair<int,string> > v(n);
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		int len = s.length();

		v[i].first = len;
		v[i].second = s;
	}

	sort(v.begin(), v.end(), cmp);

	for(int i = 0; i < n; i++)
	{
		if(i > 0 && v[i].second == v[i-1].second)
		{
			continue;
		}

		cout << v[i].second << '\n';
	}

	return 0;
}
