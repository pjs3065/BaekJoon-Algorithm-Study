#include<iostream>

using namespace std;

int r, c;
char board[20][20];
bool alpha[26];

const int mx[4] = {-1, 0, 1, 0};
const int my[4]= {0, 1, 0, -1};

void move (int x, int y, char** board, int cnt)
{
	for(int i = 0; i < 4; i++)
	{
		int px = mx[i] + x;
		int py = my[i] + y;

		//��, ��, ��, �� ���� ���� ����
		if(px >= 0 && px < r && py >= 0 && py < c && !alpha[board[px][py] - 'A'])
		{

		}
	}
}



int main()
{
	cin >> r >> c;

	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			cin >> board[i][j];
		}
	}

	//ó�� ���� ��� ���ĺ� ���
	alpha[board[0][0] - 'A'] = true;
	move(0,0,*board,0);

	return 0;
}