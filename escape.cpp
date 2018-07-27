#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

int m_x[4] = {-1,1,0,0};
int m_y[4] = {0,0,-1,1};

int main()
{
	//�� �� �Է�
	int r, c;
	scanf("%d %d", &r, &c);

	//����, �ɸ��� �ð�
	vector< vector<int> > map;
	vector< vector<int> > check;

	for(int i = 0; i < r; i++)
	{
		vector<int> element(c);
		map.push_back(element);
		check.push_back(element);
	}

	//�ִ밪���� ����� ����
	for(int i = 0; i < r; i++)
	{
		fill(check[i].begin(), check[i].end(),-1);
	}

	//���� ��ǥ
	queue< pair<int,int> > w_q;

	//����ġ�� ��ǥ
	int my_x;
	int my_y;

	//����� ��
	int home_x;
	int home_y;

	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			char ch;
			scanf(" %c", &ch);

			switch (ch)
			{
			case '.' : map[i][j] = 0; break;
			case '*' : map[i][j] = 1; w_q.push(make_pair(i,j)); break;
			case 'X' : map[i][j] = 2; break;
			case 'D' : map[i][j] = 3; home_x = i; home_y = j; break;
			case 'S' : map[i][j] = 4; my_x = i; my_y = j; break;
			}
		}
	}

	queue< pair<int,int> > q;
	q.push(make_pair(my_x,my_y));
	check[my_x][my_y] = 0;

	vector<int> re_water(2501);

	while(!q.empty())
	{
		//����ġ�� ��ǥ
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		if(check[x][y] == -1) check[x][y] = 0;

		//1�и��� ���� Ȯ��ȴ�.
		if(re_water[check[x][y]] == 0)
		{
			//���� Ȯ��

			int w_q_len = w_q.size();

			for(int i = 0; i < w_q_len; i++)
			{
				int temp_x = w_q.front().first;
				int temp_y = w_q.front().second;

				w_q.pop();

				//���� ��ǥ�� �����¿�
				for(int j = 0; j < 4; j++)
				{
					int m_w_x = temp_x + m_x[j];
					int m_w_y = temp_y + m_y[j];

					//map�� ����� �ȵȴ�.
					if(m_w_x >= 0 && m_w_x < r && m_w_y >= 0 && m_w_y < c)
					{
						//��� �ִ� ��츸 �Ѵ�
						if(map[m_w_x][m_w_y] == 0)
						{
							map[m_w_x][m_w_y] = 1;
							w_q.push(make_pair(m_w_x,m_w_y));
						}
					}
				} 
			}

			re_water[check[x][y]] = 1;
		}

		//����ġ�� �̵� (�����¿�)
		for(int i = 0; i < 4; i++)
		{
			int d_x = x + m_x[i];
			int d_y = y + m_y[i];
			//map�� ����� �ȵȴ�.
			if(d_x >= 0 && d_x < r &&d_y >= 0 && d_y < c)
			{
				//��� �ִ� ��츸 �Ѵ�
				if(map[d_x][d_y] == 0 || map[d_x][d_y] == 3)
				{
					//�ּ� ����� ��쿡�� �����ش�.
					if(check[d_x][d_y] > check[x][y] + 1 || check[d_x][d_y] == -1)
					{
						check[d_x][d_y] = check[x][y] + 1;
						q.push(make_pair(d_x,d_y));
					}
				}
			}
		}
	}

	if(check[home_x][home_y] == -1)
	{
		printf("KAKTUS\n");
	}
	else printf("%d\n",check[home_x][home_y]);

	return 0;
}