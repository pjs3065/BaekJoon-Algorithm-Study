#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

int check(string password)
{
	//자음과 모음
	int ja = 0;
	int mo = 0;

	for(char c : password)
	{
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			mo++;
		else
			ja++;
	}

	//자음 2개 이상 모음 1개 이상
	return (mo >= 1 && ja >= 2); 
}

void make(int L, vector<char>&alpa, string password, int i)
{
	//패스워드가 길이가 충족될때 자음, 모음 조건 체크
	if(password.length() == L)
	{
		if(check(password))
		{
			cout << password << '\n';
			return;
		}
	}

	//사용하거나 안사용하거나
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