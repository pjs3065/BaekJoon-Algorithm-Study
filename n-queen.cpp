#include<iostream>

using namespace std;

bool board[15][15];
int n;
int ans = 0;

int check(int row, int col)
{

	// ���� �Ʒ��� �ִ��� Ȯ���ؾ��Ѵ�.
	for(int i = 0; i < n; i++)
	{
		if(i == row) continue;
		else if(board[i][col])
		{
			return false;
		}
	}

	//���� �� �밢�� Ȯ��

	int x = row -1;
	int y = col -1;

	while(x >= 0 && y >= 0)
	{
		if(board[x][y])
		{
			return false;
		}
		
		x -= 1;
		y -= 1;
	}

	//������ �� �밢�� Ȯ��

	x = row - 1;
	y = col + 1;

	while(x >= 0 && y < n)
	{
		if(board[x][y])
		{
			return false;
		}

		x -= 1;
		y += 1;
	}

	//��� ������ �����ϸ� true�� �����Ѵ�.
	return true;
}

void cal(int row)
{
	//���� ������ ���� ���� ���
	if(row == n)
	{
		ans += 1;
		return;
	}

	for(int col = 0; col < n; col++)
	{
		board[row][col] = true;

		if(check(row,col) == true)
		{
			cal(row + 1);
		}
		//�� Ʈ��ŷ
		board[row][col] = false;
	}
}

int main()
{
	cin >> n;
	cal(0);
	cout << ans << '\n';
	return 0;
}