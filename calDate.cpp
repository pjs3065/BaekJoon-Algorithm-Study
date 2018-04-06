#include<iostream>
using namespace std;

int main()
{
	int e, s, m;
	int e_t = 0, s_t = 0, m_t = 0;
	int year = 0;

	cin >> e;
	cin >> s;
	cin >> m;

	while(1)
	{
		e_t ++;
		s_t ++;
		m_t ++;
		year ++;

		e_t = (e_t % 16) + ((e_t % 16) == 0 ? 1 : 0);
		s_t = (s_t % 29) + ((s_t % 29) == 0 ? 1 : 0);
		m_t = (m_t % 20) + ((m_t % 20) == 0 ? 1 : 0);
		
		if(e_t == e && s_t == s && m_t == m)
		{
			cout << year << '\n';
			break;
		}

	}
	return 0;
}