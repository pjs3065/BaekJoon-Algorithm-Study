#include<iostream>

using namespace std;

int board[9][9];
int c1[9][10]; //행기준
int c2[9][10]; //열기준
int c3[9][10];
const int n = 9;

int square(int i, int j)
{
	return (i/3)*3 + (j/3);
}

void go(int z)
{
	//모두 체크했을 경우
	if(z == 81)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}

	int x = z / n;
	int y = z % n;

	//현재 스도쿠 번호가 있을 경우 다음으로
	if(board[x][y] != 0) 
	{
		go(z+1);
	}
	//현재 스도쿠 번호가 없을 경우 없는 번호 찾아서 넣어주기
	else
	{
		for(int i = 1; i <= n; i++)
		{
			if(c1[x][i] == 0 && c2[y][i] == 0 && c3[square(x,y)][i] == 0)
			{
				//해당값 넣어주기
				c1[x][i] = true;
				c2[y][i] = true;
				c3[square(x,y)][i] = true;
				board[x][y] = i;
				
				go(z+1);

				//다시 돌리기
				c1[x][i] = false;
				c2[y][i] = false;
				c3[square(x,y)][i] = false;
				board[x][y] = 0;
			}
		}
	}


}

int main()
{
	//input
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	//행, 열, 사각형 기준으로 true값 체크
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(board[i][j] != 0)
			{
				c1[i][board[i][j]] = true;
				c2[j][board[i][j]] = true;
				c3[square(i,j)][board[i][j]] = true;
			}
		}
	}

	go(0);
	return 0;
}