#include<iostream>

using namespace std;

int ans = 0;

bool line[15];
bool diag1[30];
bool diag2[30];

int n;

bool check(int row, int col)
{
	// row�� �������
	if(line[col])
	{
		return false;
	}

	// �밢�� 1
	if(diag1[row + col])
	{
		return false;
	}

	// �밢�� 2
	if(diag2[row - col + n])
	{
		return false;
	}

	// ��� ������ ����
	return true;
}


void cal(int row)
{
	if(row == n)
	{
		ans += 1;
		return;
	}


	for(int col = 0; col < n; col++)
	{
		if(check(row,col))
		{
			//üũ�� ����
			line[col] = true;
			diag1[row + col] = true;
			diag2[row - col + n] = true;

			cal(row + 1);

			//����� ��������
			line[col] = false;
			diag1[row + col] = false;
			diag2[row - col + n] = false;
		}
	}
}

int main()
{
	cin >> n;
	cal(0);
	cout << ans << '\n';
	return 0;
}