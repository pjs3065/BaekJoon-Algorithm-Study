#include<iostream>

using namespace std;

bool board[15][15];
int n;
int ans = 0;

int check(int row, int col)
{

	// 위와 아래에 있는지 확인해야한다.
	for(int i = 0; i < n; i++)
	{
		if(i == row) continue;
		else if(board[i][col])
		{
			return false;
		}
	}

	//왼쪽 위 대각선 확인

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

	//오른쪽 위 대각선 확인

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

	//모든 조건이 만족하면 true를 리턴한다.
	return true;
}

void cal(int row)
{
	//보드 마지막 행을 넘을 경우
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
		//백 트레킹
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