#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

int check(string password)
{
	//������ ����
	int ja = 0;
	int mo = 0;

	for(char c : password)
	{
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			mo++;
		else
			ja++;
	}

	//���� 2�� �̻� ���� 1�� �̻�
	return (mo >= 1 && ja >= 2); 
}

void make(int L, vector<char>&alpa, string password, int i)
{
	//�н����尡 ���̰� �����ɶ� ����, ���� ���� üũ
	if(password.length() == L)
	{
		if(check(password))
		{
			cout << password << '\n';
			return;
		}
	}

	//����ϰų� �Ȼ���ϰų�
	if(i >= alpa.size()) return;
	make(L, alpa, password + alpa[i], i+1);
	make(L, alpa, password, i+1);
}


int main()
{
	int L, C;
	string password = "";
	cin >> L >> C;
	
	vector<char> alpa(C);

	//input alphabet
	for(int i = 0; i < C; i++)
	{
		cin >> alpa[i];
	}

	sort(alpa.begin(),alpa.end());
	make(L, alpa, password, 0);

}