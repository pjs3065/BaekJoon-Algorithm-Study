#include<iostream>
#include<vector>

using namespace std;

int subset[20];
int n, s;
int ans = 0;

void check(int i, int sum)
{
	//��� ���ҳ� üũ
	if(i == n)
	{
		if(sum == s)
		{
			ans += 1;
		}
		return;
	}

	//���� ���� ���Ұ��ΰ�?
	check(i+1, sum + subset[i]);

	//���� ���� ������ ���� ���ΰ�?
	check(i+1, sum);
}


int main()
{
	cin >> n >> s;
	

	for(int i = 0; i < n ; i++)
	{
		cin >> subset[i];
	}

	check(0,0);
	if(s == 0) ans -=1;
	cout << ans << '\n';
	return 0;
}