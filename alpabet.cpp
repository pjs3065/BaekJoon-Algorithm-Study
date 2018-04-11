#include<iostream>
#include<vector>

using namespace std;

int r, c;
int maximum = 1; //시작지점부터
char board[20][20];

const int mx[4] = {-1, 0, 1, 0};
const int my[4]= {0, 1, 0, -1};

void move (int x, int y, vector<bool> &alpha, int cnt)
{
	for(int i = 0; i < 4; i++)
	{
		int px = mx[i] + x;
		int py = my[i] + y;

		//상, 하, 좌, 우 가능 한지 보기
		if(px >= 0 && px < r && py >= 0 && py < c)
		{	
			if(!alpha[board[px][py] - 'A'])
			{
				alpha[board[px][py] - 'A'] = true;
				cnt += 1;

				if(maximum < cnt)
				{
					maximum = cnt;
				}

				move(px,py,alpha,cnt);

				//돌아가기
				cnt -=1;
				alpha[board[px][py] - 'A'] = false;
			}
		}
	}
}

int main()
{
	vector<bool> alpha(26);

	//보드판  r * c입력
	cin >> r >> c;

	//보드판에 알파벳 입력
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			cin >> board[i][j];
		}
	}

	//처음 시작 사용 알파벳 사용
	alpha[board[0][0] - 'A'] = true;

	//움직이기
	move(0,0,alpha,1);

	//최대값 출력
	cout << maximum << '\n';

	return 0;
}