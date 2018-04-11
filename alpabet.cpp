#include<iostream>
#include<vector>

using namespace std;

int r, c;
int maximum = 1; //������������
char board[20][20];

const int mx[4] = {-1, 0, 1, 0};
const int my[4]= {0, 1, 0, -1};

void move (int x, int y, vector<bool> &alpha, int cnt)
{
	for(int i = 0; i < 4; i++)
	{
		int px = mx[i] + x;
		int py = my[i] + y;

		//��, ��, ��, �� ���� ���� ����
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

				//���ư���
				cnt -=1;
				alpha[board[px][py] - 'A'] = false;
			}
		}
	}
}

int main()
{
	vector<bool> alpha(26);

	//������  r * c�Է�
	cin >> r >> c;

	//�����ǿ� ���ĺ� �Է�
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			cin >> board[i][j];
		}
	}

	//ó�� ���� ��� ���ĺ� ���
	alpha[board[0][0] - 'A'] = true;

	//�����̱�
	move(0,0,alpha,1);

	//�ִ밪 ���
	cout << maximum << '\n';

	return 0;
}